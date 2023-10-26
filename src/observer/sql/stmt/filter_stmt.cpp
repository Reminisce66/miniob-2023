/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/5/22.
//

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"
#include <cmath>
#include "utils.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode *conditions, int condition_num, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC function_calc(const RelAttrSqlNode &attr, Value &value)
{
  switch (attr.func)
  {
  case LENGTH_FUNC:
  {
    LengthParam param = attr.lengthparam;
    if (param.raw_data.attr_type() != CHARS) {
      LOG_ERROR("length() Func input mismatch.");
      return RC::VARIABLE_NOT_VALID;
    }

    value.set_int(param.raw_data.get_string().size());
  } break;

  case ROUND_FUNC:
  {
    // round()函数可以只有一个参数，表示数据取整;也可以有两个参数，第二个参数表示保留的小数位数
    RoundParam param = attr.roundparam;
    if (param.raw_data.attr_type() != FLOATS) {
      LOG_ERROR("round() Func input mismatch.");
      return RC::VARIABLE_NOT_VALID;
    }

    float raw_data = param.raw_data.get_float();
    if (param.bits.length() == 0) {
      // 只有一个参数
      value.set_int(round(raw_data));
    } else if (param.bits.attr_type() != INTS) {
      // 有两个参数，但第二个参数类型不对
      LOG_ERROR("round() Func bits error.");
      return RC::VARIABLE_NOT_VALID;
    } else {
      // 有两个参数，且格式正确
      raw_data *= pow(10, param.bits.get_int());
      value.set_float(round(raw_data)/pow(10, param.bits.get_int()));
    }
  } break;

  case FORMAT_FUNC:
  {
    FormatParam param = attr.formatparam;
    if (param.raw_data.attr_type() != DATES || param.format.attr_type() != CHARS) {
      LOG_ERROR("date_format() Func input mismatch.");
      return RC::VARIABLE_NOT_VALID;
    }
    std::string raw_data = param.raw_data.get_string();
    std::string format = param.format.get_string();
    value.set_date(formatDate(raw_data.c_str(), format.c_str()).c_str());
  } break;
  
  default:
    return RC::UNIMPLENMENT;
  }
  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const ConditionSqlNode &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  if (condition.left_is_attr) {
    FilterObj filter_obj;
    // 处理where中Function参数为raw_data而非表中字段的情况，直接计算出值
    if (condition.left_attr.func != NO_FUNC && condition.left_attr.attribute_name.empty()) {
      Value v;
      rc = function_calc(condition.left_attr, v);
      if (rc != RC::SUCCESS) {
        LOG_WARN("function_calc false.");
        return rc;
      }

      filter_obj.init_value(v);
    } else {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }

      if (condition.left_attr.func != NO_FUNC) {
        switch (condition.left_attr.func)
        {
        case LENGTH_FUNC:
          filter_obj.init_func(Field(table, field), condition.left_attr.func, condition.left_attr.lengthparam);
          break;
        case ROUND_FUNC:
          filter_obj.init_func(Field(table, field), condition.left_attr.func, condition.left_attr.roundparam);
          break;
        case FORMAT_FUNC:
          filter_obj.init_func(Field(table, field), condition.left_attr.func, condition.left_attr.formatparam);
          break;
        default:
          return RC::UNIMPLENMENT;
        }
      } else {
        filter_obj.init_attr(Field(table, field));
      }
    }   
    
    filter_unit->set_left(filter_obj);
  } else {
    if(condition.left_value.attr_type()==DATES&& !common::is_valid_date(condition.left_value.data())){
      return RC::INVALID_ARGUMENT;

    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.left_value);
    filter_unit->set_left(filter_obj);
  }

  if (condition.right_is_attr) {
    FilterObj filter_obj;
    if (condition.right_attr.func != NO_FUNC && condition.right_attr.attribute_name.empty()) {
      Value v;
      rc = function_calc(condition.right_attr, v);
      if (rc != RC::SUCCESS) {
        LOG_WARN("function_calc false.");
        return rc;
      }

      filter_obj.init_value(v);
    } else {
      Table *table = nullptr;
      const FieldMeta *field = nullptr;
      rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find attr");
        return rc;
      }   
      
      if (condition.right_attr.func != NO_FUNC) {
        switch (condition.right_attr.func)
        {
        case LENGTH_FUNC:
          filter_obj.init_func(Field(table, field), condition.right_attr.func, condition.right_attr.lengthparam);
          break;
        case ROUND_FUNC:
          filter_obj.init_func(Field(table, field), condition.right_attr.func, condition.right_attr.roundparam);
          break;
        case FORMAT_FUNC:
          filter_obj.init_func(Field(table, field), condition.right_attr.func, condition.right_attr.formatparam);
          break;
        default:
          return RC::UNIMPLENMENT;
        }
      } else {
        filter_obj.init_attr(Field(table, field));
      }
    }

    filter_unit->set_right(filter_obj);
  } else {
    if(condition.right_value.attr_type()==DATES&& !common::is_valid_date(condition.right_value.data())){
      return RC::INVALID_ARGUMENT;

    }
    FilterObj filter_obj;
    filter_obj.init_value(condition.right_value);
    filter_unit->set_right(filter_obj);
  }

  filter_unit->set_comp(comp);

  // 检查两个类型是否能够比较
  return rc;
}
