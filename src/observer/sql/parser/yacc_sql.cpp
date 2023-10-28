/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 2 "yacc_sql.y"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/parser/parse_defs.h"
#include "sql/parser/yacc_sql.hpp"
#include "sql/parser/lex_sql.h"
#include "sql/expr/expression.h"

using namespace std;

string token_name(const char *sql_string, YYLTYPE *llocp)
{
  return string(sql_string + llocp->first_column, llocp->last_column - llocp->first_column + 1);
}

int yyerror(YYLTYPE *llocp, const char *sql_string, ParsedSqlResult *sql_result, yyscan_t scanner, const char *msg)
{
  std::unique_ptr<ParsedSqlNode> error_sql_node = std::make_unique<ParsedSqlNode>(SCF_ERROR);
  error_sql_node->error.error_msg = msg;
  error_sql_node->error.line = llocp->first_line;
  error_sql_node->error.column = llocp->first_column;
  sql_result->add_sql_node(std::move(error_sql_node));
  return 0;
}

ArithmeticExpr *create_arithmetic_expression(ArithmeticExpr::Type type,
                                             Expression *left,
                                             Expression *right,
                                             const char *sql_string,
                                             YYLTYPE *llocp)
{
  ArithmeticExpr *expr = new ArithmeticExpr(type, left, right);
  expr->set_name(token_name(sql_string, llocp));
  return expr;
}


#line 115 "yacc_sql.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "yacc_sql.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_SEMICOLON = 3,                  /* SEMICOLON  */
  YYSYMBOL_CREATE = 4,                     /* CREATE  */
  YYSYMBOL_DROP = 5,                       /* DROP  */
  YYSYMBOL_TABLE = 6,                      /* TABLE  */
  YYSYMBOL_TABLES = 7,                     /* TABLES  */
  YYSYMBOL_INDEX = 8,                      /* INDEX  */
  YYSYMBOL_CALC = 9,                       /* CALC  */
  YYSYMBOL_SELECT = 10,                    /* SELECT  */
  YYSYMBOL_DESC = 11,                      /* DESC  */
  YYSYMBOL_SHOW = 12,                      /* SHOW  */
  YYSYMBOL_SYNC = 13,                      /* SYNC  */
  YYSYMBOL_INSERT = 14,                    /* INSERT  */
  YYSYMBOL_DELETE = 15,                    /* DELETE  */
  YYSYMBOL_UPDATE = 16,                    /* UPDATE  */
  YYSYMBOL_LBRACE = 17,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 18,                    /* RBRACE  */
  YYSYMBOL_COMMA = 19,                     /* COMMA  */
  YYSYMBOL_TRX_BEGIN = 20,                 /* TRX_BEGIN  */
  YYSYMBOL_TRX_COMMIT = 21,                /* TRX_COMMIT  */
  YYSYMBOL_TRX_ROLLBACK = 22,              /* TRX_ROLLBACK  */
  YYSYMBOL_INT_T = 23,                     /* INT_T  */
  YYSYMBOL_STRING_T = 24,                  /* STRING_T  */
  YYSYMBOL_FLOAT_T = 25,                   /* FLOAT_T  */
  YYSYMBOL_DATE_T = 26,                    /* DATE_T  */
  YYSYMBOL_HELP = 27,                      /* HELP  */
  YYSYMBOL_EXIT = 28,                      /* EXIT  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_INTO = 30,                      /* INTO  */
  YYSYMBOL_VALUES = 31,                    /* VALUES  */
  YYSYMBOL_FROM = 32,                      /* FROM  */
  YYSYMBOL_WHERE = 33,                     /* WHERE  */
  YYSYMBOL_AND = 34,                       /* AND  */
  YYSYMBOL_SET = 35,                       /* SET  */
  YYSYMBOL_ON = 36,                        /* ON  */
  YYSYMBOL_LOAD = 37,                      /* LOAD  */
  YYSYMBOL_DATA = 38,                      /* DATA  */
  YYSYMBOL_INFILE = 39,                    /* INFILE  */
  YYSYMBOL_EXPLAIN = 40,                   /* EXPLAIN  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_LT = 42,                        /* LT  */
  YYSYMBOL_GT = 43,                        /* GT  */
  YYSYMBOL_LE = 44,                        /* LE  */
  YYSYMBOL_GE = 45,                        /* GE  */
  YYSYMBOL_NE = 46,                        /* NE  */
  YYSYMBOL_NOT = 47,                       /* NOT  */
  YYSYMBOL_LK = 48,                        /* LK  */
  YYSYMBOL_INNER = 49,                     /* INNER  */
  YYSYMBOL_JOIN = 50,                      /* JOIN  */
  YYSYMBOL_MAX_agg = 51,                   /* MAX_agg  */
  YYSYMBOL_MIN_agg = 52,                   /* MIN_agg  */
  YYSYMBOL_AVG_agg = 53,                   /* AVG_agg  */
  YYSYMBOL_COUNT_agg = 54,                 /* COUNT_agg  */
  YYSYMBOL_SUM_agg = 55,                   /* SUM_agg  */
  YYSYMBOL_UNIQUE = 56,                    /* UNIQUE  */
  YYSYMBOL_NULLABLE = 57,                  /* NULLABLE  */
  YYSYMBOL_IS = 58,                        /* IS  */
  YYSYMBOL_ORDER = 59,                     /* ORDER  */
  YYSYMBOL_BY = 60,                        /* BY  */
  YYSYMBOL_ASC = 61,                       /* ASC  */
  YYSYMBOL_IN = 62,                        /* IN  */
  YYSYMBOL_EXISTS = 63,                    /* EXISTS  */
  YYSYMBOL_OR = 64,                        /* OR  */
  YYSYMBOL_AS = 65,                        /* AS  */
  YYSYMBOL_LENGTH_func = 66,               /* LENGTH_func  */
  YYSYMBOL_ROUND_func = 67,                /* ROUND_func  */
  YYSYMBOL_FORMAT_func = 68,               /* FORMAT_func  */
  YYSYMBOL_TEXT_T = 69,                    /* TEXT_T  */
  YYSYMBOL_GROUP = 70,                     /* GROUP  */
  YYSYMBOL_HAVING = 71,                    /* HAVING  */
  YYSYMBOL_NUMBER = 72,                    /* NUMBER  */
  YYSYMBOL_FLOAT = 73,                     /* FLOAT  */
  YYSYMBOL_ID = 74,                        /* ID  */
  YYSYMBOL_SSS = 75,                       /* SSS  */
  YYSYMBOL_DATE = 76,                      /* DATE  */
  YYSYMBOL_PATTERN = 77,                   /* PATTERN  */
  YYSYMBOL_78_ = 78,                       /* '+'  */
  YYSYMBOL_79_ = 79,                       /* '-'  */
  YYSYMBOL_80_ = 80,                       /* '*'  */
  YYSYMBOL_81_ = 81,                       /* '/'  */
  YYSYMBOL_UMINUS = 82,                    /* UMINUS  */
  YYSYMBOL_YYACCEPT = 83,                  /* $accept  */
  YYSYMBOL_commands = 84,                  /* commands  */
  YYSYMBOL_command_wrapper = 85,           /* command_wrapper  */
  YYSYMBOL_exit_stmt = 86,                 /* exit_stmt  */
  YYSYMBOL_help_stmt = 87,                 /* help_stmt  */
  YYSYMBOL_sync_stmt = 88,                 /* sync_stmt  */
  YYSYMBOL_begin_stmt = 89,                /* begin_stmt  */
  YYSYMBOL_commit_stmt = 90,               /* commit_stmt  */
  YYSYMBOL_rollback_stmt = 91,             /* rollback_stmt  */
  YYSYMBOL_drop_table_stmt = 92,           /* drop_table_stmt  */
  YYSYMBOL_show_tables_stmt = 93,          /* show_tables_stmt  */
  YYSYMBOL_desc_table_stmt = 94,           /* desc_table_stmt  */
  YYSYMBOL_create_index_stmt = 95,         /* create_index_stmt  */
  YYSYMBOL_id_list = 96,                   /* id_list  */
  YYSYMBOL_drop_index_stmt = 97,           /* drop_index_stmt  */
  YYSYMBOL_create_table_stmt = 98,         /* create_table_stmt  */
  YYSYMBOL_attr_def_list = 99,             /* attr_def_list  */
  YYSYMBOL_attr_def = 100,                 /* attr_def  */
  YYSYMBOL_create_as = 101,                /* create_as  */
  YYSYMBOL_nullable = 102,                 /* nullable  */
  YYSYMBOL_number = 103,                   /* number  */
  YYSYMBOL_type = 104,                     /* type  */
  YYSYMBOL_insert_stmt = 105,              /* insert_stmt  */
  YYSYMBOL_insert_value = 106,             /* insert_value  */
  YYSYMBOL_insert_values = 107,            /* insert_values  */
  YYSYMBOL_value_list = 108,               /* value_list  */
  YYSYMBOL_value = 109,                    /* value  */
  YYSYMBOL_delete_stmt = 110,              /* delete_stmt  */
  YYSYMBOL_update_stmt = 111,              /* update_stmt  */
  YYSYMBOL_update_list = 112,              /* update_list  */
  YYSYMBOL_select_stmt = 113,              /* select_stmt  */
  YYSYMBOL_group = 114,                    /* group  */
  YYSYMBOL_having = 115,                   /* having  */
  YYSYMBOL_order = 116,                    /* order  */
  YYSYMBOL_order_by_list = 117,            /* order_by_list  */
  YYSYMBOL_calc_stmt = 118,                /* calc_stmt  */
  YYSYMBOL_expression_list = 119,          /* expression_list  */
  YYSYMBOL_expression = 120,               /* expression  */
  YYSYMBOL_arg_list = 121,                 /* arg_list  */
  YYSYMBOL_rel_attr = 122,                 /* rel_attr  */
  YYSYMBOL_attr_list = 123,                /* attr_list  */
  YYSYMBOL_rel_list = 124,                 /* rel_list  */
  YYSYMBOL_length_func_param = 125,        /* length_func_param  */
  YYSYMBOL_round_func_param = 126,         /* round_func_param  */
  YYSYMBOL_format_func_param = 127,        /* format_func_param  */
  YYSYMBOL_where = 128,                    /* where  */
  YYSYMBOL_on = 129,                       /* on  */
  YYSYMBOL_condition_list = 130,           /* condition_list  */
  YYSYMBOL_condition = 131,                /* condition  */
  YYSYMBOL_comp_op = 132,                  /* comp_op  */
  YYSYMBOL_agg = 133,                      /* agg  */
  YYSYMBOL_as = 134,                       /* as  */
  YYSYMBOL_load_data_stmt = 135,           /* load_data_stmt  */
  YYSYMBOL_explain_stmt = 136,             /* explain_stmt  */
  YYSYMBOL_set_variable_stmt = 137,        /* set_variable_stmt  */
  YYSYMBOL_opt_semicolon = 138             /* opt_semicolon  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  77
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   448

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  56
/* YYNRULES -- Number of rules.  */
#define YYNRULES  177
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   333


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    80,    78,     2,    79,     2,    81,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    82
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   228,   228,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     253,   254,   255,   259,   265,   270,   276,   282,   288,   294,
     301,   307,   315,   335,   357,   360,   371,   381,   398,   407,
     428,   431,   444,   453,   482,   486,   492,   495,   498,   502,
     505,   506,   507,   508,   509,   512,   526,   537,   540,   551,
     554,   565,   569,   573,   577,   581,   586,   591,   596,   603,
     615,   629,   632,   645,   658,   669,   684,   735,   757,   760,
     774,   777,   783,   786,   798,   810,   821,   823,   831,   839,
     849,   859,   887,   928,   950,   972,   994,  1016,  1021,  1029,
    1037,  1062,  1087,  1109,  1131,  1152,  1174,  1190,  1207,  1254,
    1257,  1262,  1271,  1275,  1284,  1295,  1310,  1322,  1334,  1346,
    1362,  1365,  1379,  1382,  1399,  1425,  1430,  1437,  1448,  1454,
    1459,  1467,  1474,  1479,  1486,  1495,  1506,  1522,  1525,  1531,
    1534,  1540,  1543,  1549,  1555,  1792,  1828,  1851,  1876,  1888,
    1896,  1903,  1934,  1935,  1936,  1937,  1938,  1939,  1940,  1941,
    1942,  1943,  1944,  1945,  1948,  1949,  1950,  1951,  1952,  1955,
    1958,  1961,  1964,  1970,  1983,  1991,  2001,  2002
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "SEMICOLON", "CREATE",
  "DROP", "TABLE", "TABLES", "INDEX", "CALC", "SELECT", "DESC", "SHOW",
  "SYNC", "INSERT", "DELETE", "UPDATE", "LBRACE", "RBRACE", "COMMA",
  "TRX_BEGIN", "TRX_COMMIT", "TRX_ROLLBACK", "INT_T", "STRING_T",
  "FLOAT_T", "DATE_T", "HELP", "EXIT", "DOT", "INTO", "VALUES", "FROM",
  "WHERE", "AND", "SET", "ON", "LOAD", "DATA", "INFILE", "EXPLAIN", "EQ",
  "LT", "GT", "LE", "GE", "NE", "NOT", "LK", "INNER", "JOIN", "MAX_agg",
  "MIN_agg", "AVG_agg", "COUNT_agg", "SUM_agg", "UNIQUE", "NULLABLE", "IS",
  "ORDER", "BY", "ASC", "IN", "EXISTS", "OR", "AS", "LENGTH_func",
  "ROUND_func", "FORMAT_func", "TEXT_T", "GROUP", "HAVING", "NUMBER",
  "FLOAT", "ID", "SSS", "DATE", "PATTERN", "'+'", "'-'", "'*'", "'/'",
  "UMINUS", "$accept", "commands", "command_wrapper", "exit_stmt",
  "help_stmt", "sync_stmt", "begin_stmt", "commit_stmt", "rollback_stmt",
  "drop_table_stmt", "show_tables_stmt", "desc_table_stmt",
  "create_index_stmt", "id_list", "drop_index_stmt", "create_table_stmt",
  "attr_def_list", "attr_def", "create_as", "nullable", "number", "type",
  "insert_stmt", "insert_value", "insert_values", "value_list", "value",
  "delete_stmt", "update_stmt", "update_list", "select_stmt", "group",
  "having", "order", "order_by_list", "calc_stmt", "expression_list",
  "expression", "arg_list", "rel_attr", "attr_list", "rel_list",
  "length_func_param", "round_func_param", "format_func_param", "where",
  "on", "condition_list", "condition", "comp_op", "agg", "as",
  "load_data_stmt", "explain_stmt", "set_variable_stmt", "opt_semicolon", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,    43,    45,
      42,    47,   333
};
#endif

#define YYPACT_NINF (-282)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     370,     8,    78,   184,   184,   -46,   114,  -282,   113,    65,
      31,  -282,  -282,  -282,  -282,  -282,    54,   102,   370,   154,
     175,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,   117,   133,   178,   138,   140,   184,  -282,  -282,  -282,
    -282,  -282,  -282,   204,   212,   213,  -282,  -282,   203,  -282,
    -282,  -282,   214,  -282,  -282,  -282,    68,   216,   119,  -282,
    -282,   160,   166,   207,   202,   205,  -282,  -282,  -282,  -282,
       1,   209,   172,  -282,   211,    22,    67,    90,   111,   -39,
    -282,  -282,  -282,   -40,  -282,   184,   184,   184,   184,   230,
      43,   179,   143,  -282,   223,   222,   196,    98,   197,   200,
     265,  -282,  -282,   210,   240,   221,  -282,   248,  -282,   260,
     264,     7,   261,    13,   266,   283,  -282,  -282,  -282,  -282,
     112,   112,  -282,  -282,   184,   101,   284,   286,   -13,     3,
     242,   289,   315,  -282,   -15,   290,  -282,   267,   222,   132,
    -282,   279,    21,   291,  -282,   297,   241,  -282,   249,  -282,
     244,   259,   262,  -282,   256,   263,   257,  -282,  -282,    82,
     270,    82,  -282,    66,   317,   321,   265,  -282,  -282,  -282,
    -282,  -282,  -282,   -24,  -282,   292,  -282,   245,   143,   143,
      98,   326,    34,  -282,  -282,  -282,   334,  -282,  -282,  -282,
    -282,  -282,    51,   200,   328,   293,   336,  -282,  -282,  -282,
     345,  -282,   346,  -282,   347,  -282,   350,  -282,   295,   320,
     222,   371,   265,   353,  -282,  -282,  -282,     3,   147,  -282,
    -282,   357,   290,  -282,   265,   359,   298,   316,   330,  -282,
    -282,   291,     2,   380,   327,   331,   312,  -282,   -13,   332,
     341,   275,   384,  -282,   385,   390,    98,   391,   326,   393,
     196,  -282,  -282,   402,  -282,  -282,  -282,   348,   403,   380,
    -282,  -282,    66,   -13,   363,   354,     3,   147,  -282,    98,
    -282,   357,  -282,  -282,   406,  -282,    75,   380,  -282,   408,
    -282,   392,   128,   367,  -282,   412,   357,  -282,   196,  -282,
    -282,  -282,   143,    66,     0,   -13,    11,   414,   128,  -282,
     416,  -282,  -282,  -282,    87,  -282,  -282,   413,   128,   413,
    -282,    92,   417,  -282,   -13,   -13,  -282,    12,  -282,   110,
     419,   128,   364,  -282,  -282,   413,   413,  -282,   365,   -13,
     417,   143,  -282,  -282,  -282,   420,  -282,  -282,  -282,   -13,
    -282
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,    25,     0,     0,
       0,    26,    27,    28,    24,    23,     0,     0,     0,     0,
     176,    22,    21,    14,    15,    16,    17,     9,    10,    11,
      12,    13,     8,     5,     7,     6,     4,     3,    18,    19,
      20,     0,     0,     0,     0,     0,     0,   164,   165,   166,
     167,   168,    68,     0,     0,     0,    61,    63,   100,    65,
      66,    67,     0,   104,    99,    90,   169,     0,   137,    31,
      30,     0,     0,     0,     0,     0,   174,     1,   177,     2,
       0,     0,     0,    29,     0,     0,     0,     0,     0,     0,
      61,    63,    98,     0,   171,     0,     0,     0,     0,    91,
     109,     0,   141,    77,     0,   137,    71,     0,     0,     0,
       0,    38,    45,     0,     0,     0,    97,   125,   127,     0,
     133,   129,     0,     0,     0,     0,   102,   105,   172,   170,
      93,    94,    95,    96,     0,   112,   110,     0,   169,     0,
       0,     0,     0,   138,   142,     0,    69,     0,   137,     0,
     175,     0,     0,    40,    44,     0,     0,    36,     0,   106,
       0,     0,     0,   107,     0,     0,     0,   108,    92,   109,
       0,   109,   101,   122,     0,     0,     0,   152,   153,   154,
     155,   156,   157,     0,   158,   160,   162,     0,   141,   141,
       0,    57,     0,    70,    62,    64,     0,    50,    51,    52,
      53,    54,    46,     0,     0,     0,     0,   126,   132,   128,
     131,   134,     0,   136,   112,   113,     0,   111,     0,     0,
     137,     0,     0,     0,   159,   163,   161,     0,   145,   143,
     144,    59,     0,    55,     0,    72,     0,     0,     0,    47,
      43,    40,    37,    34,     0,     0,     0,   103,   169,     0,
      82,     0,     0,   149,    99,     0,     0,     0,    57,     0,
      71,   173,    49,     0,    48,    41,    39,     0,     0,    34,
     130,   135,   122,   169,     0,    78,     0,   147,   150,     0,
     146,    59,    56,    58,    74,    73,    46,    34,    32,     0,
     123,   139,     0,     0,    76,     0,    59,    60,    71,    42,
      35,    33,   141,   122,   169,   169,    86,     0,     0,   148,
       0,    75,   140,   124,     0,   114,   118,    86,     0,    86,
      84,   109,   120,   151,   169,   169,    85,    86,    83,   112,
       0,     0,    80,   116,   119,    86,    86,    88,     0,   169,
     120,   141,    79,    89,    87,     0,   115,   121,    81,   169,
     117
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -282,  -282,   422,  -282,  -282,  -282,  -282,  -282,  -282,  -282,
    -282,  -282,  -282,  -248,  -282,  -282,   201,   238,   206,   157,
    -282,  -282,  -282,   215,   186,  -200,  -103,  -282,  -282,  -235,
     -77,  -282,  -282,  -282,  -201,  -282,     4,    -3,  -162,  -281,
     105,  -255,  -282,  -282,  -282,   -95,  -282,  -183,  -282,   225,
    -204,  -136,  -282,  -282,  -282,  -282
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,   268,    31,    32,   204,   153,   111,   240,
     263,   202,    33,   191,   233,   257,    64,    34,    35,   148,
      36,   294,   342,   275,   320,    37,    65,   142,   137,   306,
     332,   220,   119,   122,   125,   103,   303,   143,   144,   187,
      67,    99,    38,    39,    40,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      66,    66,   173,   112,   150,   229,   230,   215,    68,   217,
     146,     4,     4,     4,    41,   128,    42,   290,   109,   188,
      46,   289,   317,   335,   224,   285,   161,   322,    69,   314,
     318,   318,   164,   154,   129,   126,   162,   327,   225,   300,
     116,   127,   165,    85,   197,   198,   199,   200,   313,   189,
     340,   234,    93,   193,    47,    48,    49,    50,    51,    92,
      52,    94,   174,   311,    43,    93,   110,   110,   237,    53,
      54,    55,   319,   336,    94,    56,    57,    58,    59,    60,
      61,   297,    62,    63,    44,   218,    45,   231,   307,   235,
     201,    52,   130,   131,   132,   133,   310,    72,   238,   223,
      95,    96,    97,    98,   307,    73,    56,    57,   239,    59,
      60,    61,   272,   149,   307,   219,   326,   135,   328,   312,
     169,    70,   238,   136,   254,   250,   337,   307,    74,   169,
     170,    66,   239,    93,   343,   344,    85,   291,   168,   338,
      75,   117,    94,    71,   118,   252,    95,    96,    97,    98,
     255,   101,   102,   281,    77,    52,   214,   259,   348,   330,
     139,   324,   136,   120,   121,   112,   329,   325,   315,   316,
      56,    57,   136,    59,    60,    61,   296,   149,    78,    47,
      48,    49,    50,    51,   228,   123,    82,   124,   333,   334,
     140,    80,    97,    98,    47,    48,    49,    50,    51,   295,
      52,    46,   304,   346,   194,   195,   141,    81,   305,    53,
      54,    55,    83,   350,    84,    56,    57,    58,    59,    60,
      61,    86,    62,    63,    85,    95,    96,    97,    98,    87,
      88,    46,    89,   100,   104,    47,    48,    49,    50,    51,
     105,    52,   106,   107,   108,   113,   114,   115,   277,   134,
      53,    54,    55,   138,   145,   102,    56,    57,    58,    59,
      60,    61,   227,    62,    63,    47,    48,    49,    50,    51,
     147,    52,   151,    85,   152,     4,   156,   158,   159,   163,
      53,    54,    55,   160,   155,   166,    90,    91,    58,    59,
      60,    61,   276,    62,    63,   157,    47,    48,    49,    50,
      51,   167,    52,   171,   172,   175,   176,   190,   192,   196,
     203,    53,    54,    55,   205,   206,   208,    56,    57,    58,
      59,    60,    61,   207,    62,    63,    47,    48,    49,    50,
      51,   209,    52,   211,   213,   221,   210,   212,   222,   226,
     236,    53,    54,    55,   216,   232,   242,    56,    57,    58,
      59,    60,    61,   244,    62,    63,   177,   178,   179,   180,
     181,   182,   183,   184,   245,   246,   169,   243,   247,   248,
     249,   253,   261,   185,     1,     2,   256,   186,   260,     3,
       4,     5,     6,     7,     8,     9,    10,   264,   262,   271,
      11,    12,    13,    95,    96,    97,    98,    14,    15,   267,
     274,   269,   278,   270,   279,    16,   273,    17,   280,   282,
      18,   284,   177,   178,   179,   180,   181,   182,   183,   184,
     286,   288,   287,   292,   293,   298,   301,   308,   302,   185,
     309,   321,   318,   186,   323,   341,   331,   339,   349,   345,
      76,   241,   265,   299,   283,   347,   251,   258,   266
};

static const yytype_int16 yycheck[] =
{
       3,     4,   138,    80,   107,   188,   189,   169,     4,   171,
     105,    10,    10,    10,     6,    55,     8,   272,    17,    34,
      17,   269,    11,    11,    48,   260,    19,   308,    74,    29,
      19,    19,    19,   110,    74,    74,    29,   318,    62,   287,
      18,    80,    29,    46,    23,    24,    25,    26,   303,    64,
     331,    17,    65,   148,    51,    52,    53,    54,    55,    62,
      57,    74,   139,   298,    56,    65,    65,    65,    17,    66,
      67,    68,    61,    61,    74,    72,    73,    74,    75,    76,
      77,   281,    79,    80,     6,    19,     8,   190,   292,   192,
      69,    57,    95,    96,    97,    98,   296,    32,    47,   176,
      78,    79,    80,    81,   308,    74,    72,    73,    57,    75,
      76,    77,   248,    79,   318,    49,   317,    74,   319,   302,
      19,     7,    47,    80,   227,   220,   327,   331,    74,    19,
      29,   134,    57,    65,   335,   336,   139,   273,   134,    29,
      38,    74,    74,    30,    77,   222,    78,    79,    80,    81,
     227,    32,    33,   256,     0,    57,    74,   234,   341,   321,
      17,    74,    80,    73,    74,   242,    74,    80,   304,   305,
      72,    73,    80,    75,    76,    77,   279,    79,     3,    51,
      52,    53,    54,    55,   187,    74,     8,    76,   324,   325,
      47,    74,    80,    81,    51,    52,    53,    54,    55,   276,
      57,    17,    74,   339,    72,    73,    63,    74,    80,    66,
      67,    68,    74,   349,    74,    72,    73,    74,    75,    76,
      77,    17,    79,    80,   227,    78,    79,    80,    81,    17,
      17,    17,    29,    17,    74,    51,    52,    53,    54,    55,
      74,    57,    35,    41,    39,    36,    74,    36,   251,    19,
      66,    67,    68,    74,    31,    33,    72,    73,    74,    75,
      76,    77,    17,    79,    80,    51,    52,    53,    54,    55,
      74,    57,    75,   276,    74,    10,    36,    29,    18,    18,
      66,    67,    68,    19,    74,    19,    72,    73,    74,    75,
      76,    77,    17,    79,    80,    74,    51,    52,    53,    54,
      55,    18,    57,    19,    18,    63,    17,    17,    41,    30,
      19,    66,    67,    68,    17,    74,    72,    72,    73,    74,
      75,    76,    77,    74,    79,    80,    51,    52,    53,    54,
      55,    72,    57,    77,    77,    18,    74,    74,    17,    47,
       6,    66,    67,    68,    74,    19,    18,    72,    73,    74,
      75,    76,    77,    17,    79,    80,    41,    42,    43,    44,
      45,    46,    47,    48,    19,    19,    19,    74,    18,    74,
      50,    18,    74,    58,     4,     5,    19,    62,    19,     9,
      10,    11,    12,    13,    14,    15,    16,    57,    72,    77,
      20,    21,    22,    78,    79,    80,    81,    27,    28,    19,
      59,    74,    18,    72,    19,    35,    74,    37,    18,    18,
      40,    18,    41,    42,    43,    44,    45,    46,    47,    48,
      18,    18,    74,    60,    70,    19,    18,    60,    36,    58,
      18,    17,    19,    62,    18,    71,    19,    18,    18,    74,
      18,   203,   241,   286,   258,   340,   221,   232,   242
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,     5,     9,    10,    11,    12,    13,    14,    15,
      16,    20,    21,    22,    27,    28,    35,    37,    40,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    97,    98,   105,   110,   111,   113,   118,   135,   136,
     137,     6,     8,    56,     6,     8,    17,    51,    52,    53,
      54,    55,    57,    66,    67,    68,    72,    73,    74,    75,
      76,    77,    79,    80,   109,   119,   120,   133,   119,    74,
       7,    30,    32,    74,    74,    38,    85,     0,     3,   138,
      74,    74,     8,    74,    74,   120,    17,    17,    17,    29,
      72,    73,   120,    65,    74,    78,    79,    80,    81,   134,
      17,    32,    33,   128,    74,    74,    35,    41,    39,    17,
      65,   101,   113,    36,    74,    36,    18,    74,    77,   125,
      73,    74,   126,    74,    76,   127,    74,    80,    55,    74,
     120,   120,   120,   120,    19,    74,    80,   121,    74,    17,
      47,    63,   120,   130,   131,    31,   128,    74,   112,    79,
     109,    75,    74,   100,   113,    74,    36,    74,    29,    18,
      19,    19,    29,    18,    19,    29,    19,    18,   119,    19,
      29,    19,    18,   134,   113,    63,    17,    41,    42,    43,
      44,    45,    46,    47,    48,    58,    62,   132,    34,    64,
      17,   106,    41,   128,    72,    73,    30,    23,    24,    25,
      26,    69,   104,    19,    99,    17,    74,    74,    72,    72,
      74,    77,    74,    77,    74,   121,    74,   121,    19,    49,
     124,    18,    17,   113,    48,    62,    47,    17,   120,   130,
     130,   109,    19,   107,    17,   109,     6,    17,    47,    57,
     102,   100,    18,    74,    17,    19,    19,    18,    74,    50,
     128,   132,   113,    18,   109,   113,    19,   108,   106,   113,
      19,    74,    72,   103,    57,    99,   101,    19,    96,    74,
      72,    77,   134,    74,    59,   116,    17,   120,    18,    19,
      18,   109,    18,   107,    18,   112,    18,    74,    18,    96,
     124,   134,    60,    70,   114,   113,   109,   108,    19,   102,
      96,    18,    36,   129,    74,    80,   122,   133,    60,    18,
     108,   112,   130,   124,    29,   134,   134,    11,    19,    61,
     117,    17,   122,    18,    74,    80,   117,   122,   117,    74,
     121,    19,   123,   134,   134,    11,    61,   117,    29,    18,
     122,    71,   115,   117,   117,    74,   134,   123,   130,    18,
     134
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    95,    96,    96,    97,    98,    98,    98,
      99,    99,   100,   100,   101,   101,   102,   102,   102,   103,
     104,   104,   104,   104,   104,   105,   106,   107,   107,   108,
     108,   109,   109,   109,   109,   109,   109,   109,   109,   110,
     111,   112,   112,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   116,   116,   116,   116,   117,   117,   117,   117,
     118,   119,   119,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,   120,   120,   120,   120,   120,   120,   121,
     121,   121,   121,   121,   122,   122,   122,   122,   122,   122,
     123,   123,   124,   124,   124,   125,   125,   125,   126,   126,
     126,   126,   126,   126,   127,   127,   127,   128,   128,   129,
     129,   130,   130,   130,   130,   131,   131,   131,   131,   131,
     131,   131,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   132,   132,   133,   133,   133,   133,   133,   134,
     134,   134,   134,   135,   136,   137,   138,   138
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       2,     2,     9,    10,     0,     3,     5,     7,     4,     8,
       0,     3,     6,     3,     2,     1,     0,     1,     2,     1,
       1,     1,     1,     1,     1,     6,     4,     0,     3,     0,
       3,     1,     2,     1,     2,     1,     1,     1,     1,     4,
       5,     0,     3,     5,     5,     7,     9,     3,     0,     5,
       0,     2,     0,     5,     4,     5,     0,     4,     3,     4,
       2,     2,     4,     3,     3,     3,     3,     3,     2,     1,
       1,     4,     3,     6,     1,     3,     4,     4,     4,     0,
       1,     3,     1,     3,     2,     5,     4,     7,     2,     4,
       0,     3,     0,     4,     6,     1,     3,     1,     3,     1,
       5,     3,     3,     1,     3,     5,     3,     0,     2,     0,
       2,     0,     1,     3,     3,     3,     5,     5,     7,     4,
       5,     8,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     0,
       2,     1,     2,     7,     2,     4,     0,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (&yylloc, sql_string, sql_result, scanner, YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location, sql_string, sql_result, scanner); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  YYUSE (sql_string);
  YYUSE (sql_result);
  YYUSE (scanner);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp, sql_string, sql_result, scanner);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]), sql_string, sql_result, scanner);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule, sql_string, sql_result, scanner); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp, const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  YYUSE (sql_string);
  YYUSE (sql_result);
  YYUSE (scanner);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (const char * sql_string, ParsedSqlResult * sql_result, void * scanner)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc, scanner);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* commands: command_wrapper opt_semicolon  */
#line 229 "yacc_sql.y"
  {
    std::unique_ptr<ParsedSqlNode> sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[-1].sql_node));
    sql_result->add_sql_node(std::move(sql_node));
  }
#line 1898 "yacc_sql.cpp"
    break;

  case 23: /* exit_stmt: EXIT  */
#line 259 "yacc_sql.y"
         {
      (void)yynerrs;  // 这么写为了消除yynerrs未使用的告警。如果你有更好的方法欢迎提PR
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXIT);
    }
#line 1907 "yacc_sql.cpp"
    break;

  case 24: /* help_stmt: HELP  */
#line 265 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_HELP);
    }
#line 1915 "yacc_sql.cpp"
    break;

  case 25: /* sync_stmt: SYNC  */
#line 270 "yacc_sql.y"
         {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SYNC);
    }
#line 1923 "yacc_sql.cpp"
    break;

  case 26: /* begin_stmt: TRX_BEGIN  */
#line 276 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_BEGIN);
    }
#line 1931 "yacc_sql.cpp"
    break;

  case 27: /* commit_stmt: TRX_COMMIT  */
#line 282 "yacc_sql.y"
               {
      (yyval.sql_node) = new ParsedSqlNode(SCF_COMMIT);
    }
#line 1939 "yacc_sql.cpp"
    break;

  case 28: /* rollback_stmt: TRX_ROLLBACK  */
#line 288 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_ROLLBACK);
    }
#line 1947 "yacc_sql.cpp"
    break;

  case 29: /* drop_table_stmt: DROP TABLE ID  */
#line 294 "yacc_sql.y"
                  {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_TABLE);
      (yyval.sql_node)->drop_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1957 "yacc_sql.cpp"
    break;

  case 30: /* show_tables_stmt: SHOW TABLES  */
#line 301 "yacc_sql.y"
                {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SHOW_TABLES);
    }
#line 1965 "yacc_sql.cpp"
    break;

  case 31: /* desc_table_stmt: DESC ID  */
#line 307 "yacc_sql.y"
             {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DESC_TABLE);
      (yyval.sql_node)->desc_table.relation_name = (yyvsp[0].string);
      free((yyvsp[0].string));
    }
#line 1975 "yacc_sql.cpp"
    break;

  case 32: /* create_index_stmt: CREATE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 316 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
      create_index.index_name = (yyvsp[-6].string);
      create_index.relation_name = (yyvsp[-4].string);
      create_index.is_unique=false;
      if((yyvsp[-1].relation_list)==nullptr){
      create_index.attribute_name.push_back((yyvsp[-2].string));

      }else{
      (yyvsp[-1].relation_list)->push_back((yyvsp[-2].string));
       create_index.attribute_name.swap(*(yyvsp[-1].relation_list));
      }
      std::reverse(create_index.attribute_name.begin(), create_index.attribute_name.end());
      free((yyvsp[-6].string));
      free((yyvsp[-4].string));
      free((yyvsp[-2].string));
      free((yyvsp[-1].relation_list));
    }
#line 1999 "yacc_sql.cpp"
    break;

  case 33: /* create_index_stmt: CREATE UNIQUE INDEX ID ON ID LBRACE ID id_list RBRACE  */
#line 336 "yacc_sql.y"
         {
           (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_INDEX);
           CreateIndexSqlNode &create_index = (yyval.sql_node)->create_index;
           create_index.index_name = (yyvsp[-6].string);
           create_index.relation_name = (yyvsp[-4].string);
           create_index.is_unique=true;
           if((yyvsp[-1].relation_list)==nullptr){
           create_index.attribute_name.push_back((yyvsp[-2].string));

           }else{
           (yyvsp[-1].relation_list)->push_back((yyvsp[-2].string));
            create_index.attribute_name.swap(*(yyvsp[-1].relation_list));
           }
           std::reverse(create_index.attribute_name.begin(), create_index.attribute_name.end());
           free((yyvsp[-6].string));
           free((yyvsp[-4].string));
           free((yyvsp[-2].string));
           free((yyvsp[-1].relation_list));
         }
#line 2023 "yacc_sql.cpp"
    break;

  case 34: /* id_list: %empty  */
#line 357 "yacc_sql.y"
  {
  (yyval.relation_list)=nullptr;
  }
#line 2031 "yacc_sql.cpp"
    break;

  case 35: /* id_list: COMMA ID id_list  */
#line 360 "yacc_sql.y"
                   {
   if((yyvsp[0].relation_list)!=nullptr){
   (yyval.relation_list)=(yyvsp[0].relation_list);
   }else{
   (yyval.relation_list)=new std::vector<std::string>;
   }
   (yyval.relation_list)->push_back((yyvsp[-1].string));
   free((yyvsp[-1].string));

  }
#line 2046 "yacc_sql.cpp"
    break;

  case 36: /* drop_index_stmt: DROP INDEX ID ON ID  */
#line 372 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DROP_INDEX);
      (yyval.sql_node)->drop_index.index_name = (yyvsp[-2].string);
      (yyval.sql_node)->drop_index.relation_name = (yyvsp[0].string);
      free((yyvsp[-2].string));
      free((yyvsp[0].string));
    }
#line 2058 "yacc_sql.cpp"
    break;

  case 37: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE  */
#line 382 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-4].string);
      free((yyvsp[-4].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-1].attr_infos);

      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-2].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());
      create_table.has_select = false;
      delete (yyvsp[-2].attr_info);
    }
#line 2079 "yacc_sql.cpp"
    break;

  case 38: /* create_table_stmt: CREATE TABLE ID create_as  */
#line 399 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-1].string);
      free((yyvsp[-1].string));
      create_table.has_select = true;
      create_table.selectSqlNode = *((yyvsp[0].select_sql_node));
    }
#line 2092 "yacc_sql.cpp"
    break;

  case 39: /* create_table_stmt: CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE create_as  */
#line 408 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CREATE_TABLE);
      CreateTableSqlNode &create_table = (yyval.sql_node)->create_table;
      create_table.relation_name = (yyvsp[-5].string);
      free((yyvsp[-5].string));

      std::vector<AttrInfoSqlNode> *src_attrs = (yyvsp[-2].attr_infos);
      if (src_attrs != nullptr) {
        create_table.attr_infos.swap(*src_attrs);
      }
      create_table.attr_infos.emplace_back(*(yyvsp[-3].attr_info));
      std::reverse(create_table.attr_infos.begin(), create_table.attr_infos.end());

      create_table.has_select = true;
      create_table.selectSqlNode = *((yyvsp[0].select_sql_node));
      delete (yyvsp[-3].attr_info);
    }
#line 2114 "yacc_sql.cpp"
    break;

  case 40: /* attr_def_list: %empty  */
#line 428 "yacc_sql.y"
    {
      (yyval.attr_infos) = nullptr;
    }
#line 2122 "yacc_sql.cpp"
    break;

  case 41: /* attr_def_list: COMMA attr_def attr_def_list  */
#line 432 "yacc_sql.y"
    {
      if ((yyvsp[0].attr_infos) != nullptr) {
        (yyval.attr_infos) = (yyvsp[0].attr_infos);
      } else {
        (yyval.attr_infos) = new std::vector<AttrInfoSqlNode>;
      }
      (yyval.attr_infos)->emplace_back(*(yyvsp[-1].attr_info));
      delete (yyvsp[-1].attr_info);
    }
#line 2136 "yacc_sql.cpp"
    break;

  case 42: /* attr_def: ID type LBRACE number RBRACE nullable  */
#line 445 "yacc_sql.y"
    {
      (yyval.attr_info) = new AttrInfoSqlNode;
      (yyval.attr_info)->type = (AttrType)(yyvsp[-4].number);
      (yyval.attr_info)->name = (yyvsp[-5].string);
      (yyval.attr_info)->length = (yyvsp[-2].number);
      (yyval.attr_info)->is_null=(yyvsp[0].is_null);
      free((yyvsp[-5].string));
    }
#line 2149 "yacc_sql.cpp"
    break;

  case 43: /* attr_def: ID type nullable  */
#line 454 "yacc_sql.y"
    {
    if ((AttrType)(yyvsp[-1].number)==DATES){
    (yyval.attr_info) = new AttrInfoSqlNode;
              (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
              (yyval.attr_info)->name = (yyvsp[-2].string);
              (yyval.attr_info)->length = 10;
              (yyval.attr_info)->is_null=(yyvsp[0].is_null);
              free((yyvsp[-2].string));
    }else if((AttrType)(yyvsp[-1].number)==TEXTS){
    (yyval.attr_info) = new AttrInfoSqlNode;
              (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
              (yyval.attr_info)->name = (yyvsp[-2].string);
              (yyval.attr_info)->length = 8;
              (yyval.attr_info)->is_null=(yyvsp[0].is_null);
              free((yyvsp[-2].string));
    }else{
    (yyval.attr_info) = new AttrInfoSqlNode;
          (yyval.attr_info)->type = (AttrType)(yyvsp[-1].number);
          (yyval.attr_info)->name = (yyvsp[-2].string);
          (yyval.attr_info)->length = 4;
          (yyval.attr_info)->is_null=(yyvsp[0].is_null);
          free((yyvsp[-2].string));
    }

    }
#line 2179 "yacc_sql.cpp"
    break;

  case 44: /* create_as: AS select_stmt  */
#line 483 "yacc_sql.y"
  {
    (yyval.select_sql_node) = &((yyvsp[0].sql_node)->selection);
  }
#line 2187 "yacc_sql.cpp"
    break;

  case 45: /* create_as: select_stmt  */
#line 487 "yacc_sql.y"
  {
    (yyval.select_sql_node) = &((yyvsp[0].sql_node)->selection);
  }
#line 2195 "yacc_sql.cpp"
    break;

  case 46: /* nullable: %empty  */
#line 492 "yacc_sql.y"
   {
   (yyval.is_null)=true;
   }
#line 2203 "yacc_sql.cpp"
    break;

  case 47: /* nullable: NULLABLE  */
#line 495 "yacc_sql.y"
            {
   (yyval.is_null)=true;
   }
#line 2211 "yacc_sql.cpp"
    break;

  case 48: /* nullable: NOT NULLABLE  */
#line 498 "yacc_sql.y"
                {
   (yyval.is_null)=false;
   }
#line 2219 "yacc_sql.cpp"
    break;

  case 49: /* number: NUMBER  */
#line 502 "yacc_sql.y"
           {(yyval.number) = (yyvsp[0].number);}
#line 2225 "yacc_sql.cpp"
    break;

  case 50: /* type: INT_T  */
#line 505 "yacc_sql.y"
               { (yyval.number)=INTS; }
#line 2231 "yacc_sql.cpp"
    break;

  case 51: /* type: STRING_T  */
#line 506 "yacc_sql.y"
               { (yyval.number)=CHARS; }
#line 2237 "yacc_sql.cpp"
    break;

  case 52: /* type: FLOAT_T  */
#line 507 "yacc_sql.y"
               { (yyval.number)=FLOATS; }
#line 2243 "yacc_sql.cpp"
    break;

  case 53: /* type: DATE_T  */
#line 508 "yacc_sql.y"
              {(yyval.number)=DATES;}
#line 2249 "yacc_sql.cpp"
    break;

  case 54: /* type: TEXT_T  */
#line 509 "yacc_sql.y"
             {(yyval.number)=TEXTS;}
#line 2255 "yacc_sql.cpp"
    break;

  case 55: /* insert_stmt: INSERT INTO ID VALUES insert_value insert_values  */
#line 513 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_INSERT);
      (yyval.sql_node)->insertion.relation_name = (yyvsp[-3].string);
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.sql_node)->insertion.values.swap(*(yyvsp[0].value_list));
      }
      (yyval.sql_node)->insertion.values.insert((yyval.sql_node)->insertion.values.end(),(yyvsp[-1].value_list)->begin(),(yyvsp[-1].value_list)->end());
      std::reverse((yyval.sql_node)->insertion.values.begin(), (yyval.sql_node)->insertion.values.end());
      delete (yyvsp[-1].value_list);
      free((yyvsp[-3].string));
    }
#line 2271 "yacc_sql.cpp"
    break;

  case 56: /* insert_value: LBRACE value value_list RBRACE  */
#line 526 "yacc_sql.y"
                                   {
	if ((yyvsp[-1].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[-1].value_list);
        } else {
        (yyval.value_list) = new std::vector<Value>;
        }
        (yyval.value_list)->emplace_back(*(yyvsp[-2].value));
         delete (yyvsp[-2].value);
    }
#line 2285 "yacc_sql.cpp"
    break;

  case 57: /* insert_values: %empty  */
#line 537 "yacc_sql.y"
    {
    (yyval.value_list)=nullptr;
    }
#line 2293 "yacc_sql.cpp"
    break;

  case 58: /* insert_values: COMMA insert_value insert_values  */
#line 540 "yacc_sql.y"
                                     {
	if ((yyvsp[0].value_list) != nullptr) {
                (yyval.value_list) = (yyvsp[0].value_list);
              } else {
                (yyval.value_list) = new std::vector<Value>;
              }
              (yyval.value_list)->insert((yyval.value_list)->end(),(yyvsp[-1].value_list)->begin(),(yyvsp[-1].value_list)->end());
              delete (yyvsp[-1].value_list);
    }
#line 2307 "yacc_sql.cpp"
    break;

  case 59: /* value_list: %empty  */
#line 551 "yacc_sql.y"
    {
      (yyval.value_list) = nullptr;
    }
#line 2315 "yacc_sql.cpp"
    break;

  case 60: /* value_list: COMMA value value_list  */
#line 554 "yacc_sql.y"
                              { 
      if ((yyvsp[0].value_list) != nullptr) {
        (yyval.value_list) = (yyvsp[0].value_list);
      } else {
        (yyval.value_list) = new std::vector<Value>;
      }
      (yyval.value_list)->emplace_back(*(yyvsp[-1].value));
      delete (yyvsp[-1].value);
    }
#line 2329 "yacc_sql.cpp"
    break;

  case 61: /* value: NUMBER  */
#line 565 "yacc_sql.y"
           {
      (yyval.value) = new Value((int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2338 "yacc_sql.cpp"
    break;

  case 62: /* value: '-' NUMBER  */
#line 569 "yacc_sql.y"
                {
      (yyval.value) = new Value(-(int)(yyvsp[0].number));
      (yyloc) = (yylsp[0]);
    }
#line 2347 "yacc_sql.cpp"
    break;

  case 63: /* value: FLOAT  */
#line 573 "yacc_sql.y"
           {
      (yyval.value) = new Value((float)(yyvsp[0].floats));
      (yyloc) = (yylsp[0]);
    }
#line 2356 "yacc_sql.cpp"
    break;

  case 64: /* value: '-' FLOAT  */
#line 577 "yacc_sql.y"
               {
    (yyval.value) = new Value(-(float)(yyvsp[0].floats));
    (yyloc) = (yylsp[0]);
    }
#line 2365 "yacc_sql.cpp"
    break;

  case 65: /* value: SSS  */
#line 581 "yacc_sql.y"
         {
      char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
      (yyval.value) = new Value(tmp,CHARS);
      free(tmp);
    }
#line 2375 "yacc_sql.cpp"
    break;

  case 66: /* value: DATE  */
#line 586 "yacc_sql.y"
          {
           char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
           (yyval.value) = new Value(tmp,DATES);
           free(tmp);
         }
#line 2385 "yacc_sql.cpp"
    break;

  case 67: /* value: PATTERN  */
#line 591 "yacc_sql.y"
             {
         char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
         (yyval.value) = new Value(tmp,CHARS);
         free(tmp);
         }
#line 2395 "yacc_sql.cpp"
    break;

  case 68: /* value: NULLABLE  */
#line 596 "yacc_sql.y"
             {
      (yyval.value)=new Value();
      (yyval.value)->set_null();
    }
#line 2404 "yacc_sql.cpp"
    break;

  case 69: /* delete_stmt: DELETE FROM ID where  */
#line 604 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_DELETE);
      (yyval.sql_node)->deletion.relation_name = (yyvsp[-1].string);
      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->deletion.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-1].string));
    }
#line 2418 "yacc_sql.cpp"
    break;

  case 70: /* update_stmt: UPDATE ID SET update_list where  */
#line 616 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_UPDATE);
      (yyval.sql_node)->update.relation_name = (yyvsp[-3].string);
      (yyval.sql_node)->update.updateValue_list.swap(*(yyvsp[-1].update_list));

      if ((yyvsp[0].condition_list) != nullptr) {
        (yyval.sql_node)->update.conditions.swap(*(yyvsp[0].condition_list));
        delete (yyvsp[0].condition_list);
      }
      free((yyvsp[-3].string));
      free((yyvsp[-1].update_list));
    }
#line 2435 "yacc_sql.cpp"
    break;

  case 71: /* update_list: %empty  */
#line 629 "yacc_sql.y"
   {
   (yyval.update_list)=nullptr;
   }
#line 2443 "yacc_sql.cpp"
    break;

  case 72: /* update_list: ID EQ value  */
#line 632 "yacc_sql.y"
                {

      (yyval.update_list)=new std::vector<UpdateValue>;



      UpdateValue value;
      value.is_select=false;
      value.value=*(yyvsp[0].value);
      value.attribute_name=(yyvsp[-2].string);
      (yyval.update_list)->push_back(value);

      }
#line 2461 "yacc_sql.cpp"
    break;

  case 73: /* update_list: ID EQ value COMMA update_list  */
#line 645 "yacc_sql.y"
                                 {
   if((yyvsp[0].update_list)==nullptr){
   (yyval.update_list)=new std::vector<UpdateValue>;
   }else{
   (yyval.update_list)=(yyvsp[0].update_list);
   }
   UpdateValue value;
   value.is_select=false;
   value.value=*(yyvsp[-2].value);
   value.attribute_name=(yyvsp[-4].string);
   (yyval.update_list)->push_back(value);

   }
#line 2479 "yacc_sql.cpp"
    break;

  case 74: /* update_list: ID EQ LBRACE select_stmt RBRACE  */
#line 658 "yacc_sql.y"
                                     {

         (yyval.update_list)=new std::vector<UpdateValue>;

         UpdateValue value;
         value.is_select=true;
         value.selectSqlNode=(yyvsp[-1].sql_node)->selection;
         value.attribute_name=(yyvsp[-4].string);
         (yyval.update_list)->push_back(value);

      }
#line 2495 "yacc_sql.cpp"
    break;

  case 75: /* update_list: ID EQ LBRACE select_stmt RBRACE COMMA update_list  */
#line 669 "yacc_sql.y"
                                                      {
   if((yyvsp[0].update_list)==nullptr){
      (yyval.update_list)=new std::vector<UpdateValue>;
      }else{
      (yyval.update_list)=(yyvsp[0].update_list);
      }
      UpdateValue value;
      value.is_select=true;
      value.selectSqlNode=(yyvsp[-3].sql_node)->selection;
      value.attribute_name=(yyvsp[-6].string);
      (yyval.update_list)->push_back(value);

   }
#line 2513 "yacc_sql.cpp"
    break;

  case 76: /* select_stmt: SELECT expression_list FROM ID as rel_list where order group  */
#line 685 "yacc_sql.y"
         {
           (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
           if ((yyvsp[-7].expression) != nullptr) {
             (yyval.sql_node)->selection.attributes.swap((yyvsp[-7].expression)->relAttrSqlNodes);
             (yyval.sql_node)->selection.attributes_expression.swap((yyvsp[-7].expression)->expression);
             (yyval.sql_node)->selection.stringsqlExprs.swap((yyvsp[-7].expression)->stringsqlExprs);
             (yyval.sql_node)->selection.fieldExprs.swap((yyvsp[-7].expression)->fieldExprs);
             (yyval.sql_node)->selection.is_expression_select_attr=(yyvsp[-7].expression)->is_expression;
             (yyval.sql_node)->selection.expr_alias_map.swap((yyvsp[-7].expression)->expr_alias_map);
             std::reverse((yyval.sql_node)->selection.attributes_expression.begin(), (yyval.sql_node)->selection.attributes_expression.end());
             delete (yyvsp[-7].expression);
           }
           (yyval.sql_node)->selection.is_alias_right=true;
           if ((yyvsp[-3].inner_join_list) != nullptr) {
             (yyval.sql_node)->selection.relations.swap((yyvsp[-3].inner_join_list)->relations);
             (yyval.sql_node)->selection.conditions.swap((yyvsp[-3].inner_join_list)->conditions);
             (yyval.sql_node)->selection.alias_map.insert((yyvsp[-3].inner_join_list)->alias_map.begin(), (yyvsp[-3].inner_join_list)->alias_map.end());
             (yyval.sql_node)->selection.is_alias_right=(yyvsp[-3].inner_join_list)->is_alias_right;
             delete (yyvsp[-3].inner_join_list);
           }
           (yyval.sql_node)->selection.relations.push_back((yyvsp[-5].string));
           std::reverse((yyval.sql_node)->selection.relations.begin(), (yyval.sql_node)->selection.relations.end());
           if ((yyvsp[-4].string) != nullptr) {
           if((yyval.sql_node)->selection.alias_map.find((yyvsp[-4].string))==(yyval.sql_node)->selection.alias_map.end()){
           (yyval.sql_node)->selection.alias_map.insert(std::pair<std::string, std::string>((yyvsp[-4].string), (yyvsp[-5].string)));
           }else{
           (yyval.sql_node)->selection.is_alias_right=false;
            }
           }

           if ((yyvsp[-2].condition_list) != nullptr) {
             (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.begin(),(yyvsp[-2].condition_list)->begin(),(yyvsp[-2].condition_list)->end());
             std::reverse((yyval.sql_node)->selection.conditions.begin(), (yyval.sql_node)->selection.conditions.end());
             delete (yyvsp[-2].condition_list);
           }
           if((yyvsp[-1].order_by)!=nullptr){
           (yyval.sql_node)->selection.order_by.insert((yyval.sql_node)->selection.order_by.begin(),(yyvsp[-1].order_by)->begin(),(yyvsp[-1].order_by)->end());
           std::reverse((yyval.sql_node)->selection.order_by.begin(), (yyval.sql_node)->selection.order_by.end());
                        delete (yyvsp[-1].order_by);
           }
           (yyval.sql_node)->selection.is_sub_select=false;

           if((yyvsp[0].group_by)!=nullptr){
           (yyval.sql_node)->selection.group_by=*(yyvsp[0].group_by);
           (yyval.sql_node)->selection.is_group_by=true;
           }else{
           (yyval.sql_node)->selection.is_group_by=false;
           }
           free((yyvsp[-5].string));
         }
#line 2568 "yacc_sql.cpp"
    break;

  case 77: /* select_stmt: SELECT expression_list where  */
#line 735 "yacc_sql.y"
                                         {
            (yyval.sql_node) = new ParsedSqlNode(SCF_SELECT);
            if ((yyvsp[-1].expression) != nullptr) {
                (yyval.sql_node)->selection.attributes.swap((yyvsp[-1].expression)->relAttrSqlNodes);
                (yyval.sql_node)->selection.attributes_expression.swap((yyvsp[-1].expression)->expression);
                (yyval.sql_node)->selection.stringsqlExprs.swap((yyvsp[-1].expression)->stringsqlExprs);
                (yyval.sql_node)->selection.fieldExprs.swap((yyvsp[-1].expression)->fieldExprs);
                (yyval.sql_node)->selection.is_expression_select_attr=(yyvsp[-1].expression)->is_expression;
                std::reverse((yyval.sql_node)->selection.attributes_expression.begin(), (yyval.sql_node)->selection.attributes_expression.end());
                delete (yyvsp[-1].expression);
              }
            (yyval.sql_node)->selection.is_alias_right=true;
            if ((yyvsp[0].condition_list) != nullptr) {
                (yyval.sql_node)->selection.conditions.insert((yyval.sql_node)->selection.conditions.begin(),(yyvsp[0].condition_list)->begin(),(yyvsp[0].condition_list)->end());
                std::reverse((yyval.sql_node)->selection.conditions.begin(), (yyval.sql_node)->selection.conditions.end());
                delete (yyvsp[0].condition_list);
              }
            (yyval.sql_node)->selection.is_sub_select=false;
          }
#line 2592 "yacc_sql.cpp"
    break;

  case 78: /* group: %empty  */
#line 757 "yacc_sql.y"
       {
        (yyval.group_by)=nullptr;
       }
#line 2600 "yacc_sql.cpp"
    break;

  case 79: /* group: GROUP BY rel_attr attr_list having  */
#line 760 "yacc_sql.y"
                                          {
       (yyval.group_by)=new GroupBySqlNode;
         if((yyvsp[-1].rel_attr_list)!=nullptr){
         (yyval.group_by)->attrs.insert((yyval.group_by)->attrs.end(),(yyvsp[-1].rel_attr_list)->begin(),(yyvsp[-1].rel_attr_list)->end());
         }
         (yyval.group_by)->attrs.push_back(*(yyvsp[-2].rel_attr));
         std::reverse((yyval.group_by)->attrs.begin(),(yyval.group_by)->attrs.end());
         if((yyvsp[0].condition_list)!=nullptr){
         (yyval.group_by)->conditions.insert((yyval.group_by)->conditions.end(),(yyvsp[0].condition_list)->begin(),(yyvsp[0].condition_list)->end());
         }

       }
#line 2617 "yacc_sql.cpp"
    break;

  case 80: /* having: %empty  */
#line 774 "yacc_sql.y"
      {
       (yyval.condition_list)=nullptr;
      }
#line 2625 "yacc_sql.cpp"
    break;

  case 81: /* having: HAVING condition_list  */
#line 777 "yacc_sql.y"
                             {
         (yyval.condition_list) = (yyvsp[0].condition_list);
      }
#line 2633 "yacc_sql.cpp"
    break;

  case 82: /* order: %empty  */
#line 783 "yacc_sql.y"
  {
  (yyval.order_by)=nullptr;
  }
#line 2641 "yacc_sql.cpp"
    break;

  case 83: /* order: ORDER BY rel_attr ASC order_by_list  */
#line 786 "yacc_sql.y"
                                      {
  if((yyvsp[0].order_by)!=nullptr){
  (yyval.order_by)=(yyvsp[0].order_by);
  }else{
  (yyval.order_by)=new std::vector<OrderBySqlNode>;
  }
  OrderBySqlNode orderBySqlNode;
      orderBySqlNode.attrs=*(yyvsp[-2].rel_attr);
      orderBySqlNode.orderBySequence=ASC_ORDER_BY;
      (yyval.order_by)->push_back(orderBySqlNode);
   std::reverse((yyval.order_by)->begin(),(yyval.order_by)->end());
  }
#line 2658 "yacc_sql.cpp"
    break;

  case 84: /* order: ORDER BY rel_attr order_by_list  */
#line 798 "yacc_sql.y"
                                   {
    if((yyvsp[0].order_by)!=nullptr){
    (yyval.order_by)=(yyvsp[0].order_by);
    }else{
    (yyval.order_by)=new std::vector<OrderBySqlNode>;
    }
    OrderBySqlNode orderBySqlNode;
    orderBySqlNode.attrs=*(yyvsp[-1].rel_attr);
    orderBySqlNode.orderBySequence=ASC_ORDER_BY;
    (yyval.order_by)->push_back(orderBySqlNode);
     std::reverse((yyval.order_by)->begin(),(yyval.order_by)->end());
    }
#line 2675 "yacc_sql.cpp"
    break;

  case 85: /* order: ORDER BY rel_attr DESC order_by_list  */
#line 810 "yacc_sql.y"
                                       {
  if((yyvsp[0].order_by)!=nullptr){
    (yyval.order_by)=(yyvsp[0].order_by);
    }else{
    (yyval.order_by)=new std::vector<OrderBySqlNode>;
    }
    (yyval.order_by)->push_back({*(yyvsp[-2].rel_attr),DESC_ORDER_BY});
     std::reverse((yyval.order_by)->begin(),(yyval.order_by)->end());

  }
#line 2690 "yacc_sql.cpp"
    break;

  case 86: /* order_by_list: %empty  */
#line 821 "yacc_sql.y"
   {(yyval.order_by)=nullptr;
   }
#line 2697 "yacc_sql.cpp"
    break;

  case 87: /* order_by_list: COMMA rel_attr ASC order_by_list  */
#line 823 "yacc_sql.y"
                                    {
   if((yyvsp[0].order_by)!=nullptr){
     (yyval.order_by)=(yyvsp[0].order_by);
     }else{
     (yyval.order_by)=new std::vector<OrderBySqlNode>;
     }
     (yyval.order_by)->push_back({*(yyvsp[-2].rel_attr),ASC_ORDER_BY});
   }
#line 2710 "yacc_sql.cpp"
    break;

  case 88: /* order_by_list: COMMA rel_attr order_by_list  */
#line 831 "yacc_sql.y"
                                 {
   if((yyvsp[0].order_by)!=nullptr){
        (yyval.order_by)=(yyvsp[0].order_by);
        }else{
        (yyval.order_by)=new std::vector<OrderBySqlNode>;
        }
        (yyval.order_by)->push_back({*(yyvsp[-1].rel_attr),ASC_ORDER_BY});

   }
#line 2724 "yacc_sql.cpp"
    break;

  case 89: /* order_by_list: COMMA rel_attr DESC order_by_list  */
#line 839 "yacc_sql.y"
                                      {
       if((yyvsp[0].order_by)!=nullptr){
            (yyval.order_by)=(yyvsp[0].order_by);
            }else{
            (yyval.order_by)=new std::vector<OrderBySqlNode>;
            }
            (yyval.order_by)->push_back({*(yyvsp[-2].rel_attr),DESC_ORDER_BY});
    }
#line 2737 "yacc_sql.cpp"
    break;

  case 90: /* calc_stmt: CALC expression_list  */
#line 850 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_CALC);
      std::reverse((yyvsp[0].expression)->expression.begin(), (yyvsp[0].expression)->expression.end());
      (yyval.sql_node)->calc.expressions.swap((yyvsp[0].expression)->expression);
      delete (yyvsp[0].expression);
    }
#line 2748 "yacc_sql.cpp"
    break;

  case 91: /* expression_list: expression as  */
#line 860 "yacc_sql.y"
    {
      (yyval.expression) = (yyvsp[-1].expression);
      if((yyvsp[0].string)!=nullptr){
	      if((yyvsp[-1].expression)->is_expression==false){
		      if((yyvsp[-1].expression)->relAttrSqlNodes.size()==1){

		      	if ((yyvsp[-1].expression)->relAttrSqlNodes[0].attribute_name == "*" && (yyvsp[-1].expression)->relAttrSqlNodes[0].agg == NO_AGG) {
		      	      (yyvsp[-1].expression)->relAttrSqlNodes[0].is_right = false;
		      	}

			(yyvsp[-1].expression)->relAttrSqlNodes[0].alias_name=(yyvsp[0].string);
		      }
		      if ((yyvsp[-1].expression)->fieldExprs.size() != 0) {
		      	(yyvsp[-1].expression)->fieldExprs[0]->set_alias_name((yyvsp[0].string));
		      }

	      } else {
	      	(yyvsp[-1].expression)->expr_alias_map[(yyvsp[-1].expression)->expression[0]->name()] = (yyvsp[0].string);
	      }
      }else{
      if ((yyvsp[-1].expression)->relAttrSqlNodes.size() != 0 && (yyvsp[-1].expression)->relAttrSqlNodes[0].attribute_name == "*") {
      		      		(yyvsp[-1].expression)->relAttrSqlNodes[0].is_right = true;
        }
      }


    }
#line 2780 "yacc_sql.cpp"
    break;

  case 92: /* expression_list: expression as COMMA expression_list  */
#line 888 "yacc_sql.y"
    {
      if ((yyvsp[0].expression) != nullptr) {
        (yyval.expression) = (yyvsp[0].expression);
      } else {
        (yyval.expression) = new ExpressionSqlNode ;
      }

      if((yyvsp[-2].string)!=nullptr){
      	      if((yyvsp[-3].expression)->is_expression==false){
      		      if((yyvsp[-3].expression)->relAttrSqlNodes.size()==1){

      		      if ((yyvsp[-3].expression)->relAttrSqlNodes[0].attribute_name == "*" && (yyvsp[-3].expression)->relAttrSqlNodes[0].agg == NO_AGG) {
                      		      	      (yyvsp[-3].expression)->relAttrSqlNodes[0].is_right = false;
                      		      	}
      			(yyvsp[-3].expression)->relAttrSqlNodes[0].alias_name=(yyvsp[-2].string);
      		      }
      		      if ((yyvsp[-3].expression)->fieldExprs.size() != 0) {
      		      	(yyvsp[-3].expression)->fieldExprs[0]->set_alias_name((yyvsp[-2].string));
      		      }

      	      } else {
      	      	(yyvsp[-3].expression)->expr_alias_map[(yyvsp[-3].expression)->expression[0]->name()] = (yyvsp[-2].string);
      	      }
      } else {
      	if ((yyvsp[-3].expression)->relAttrSqlNodes.size() != 0 && (yyvsp[-3].expression)->relAttrSqlNodes[0].attribute_name == "*") {
              		      		(yyvsp[-3].expression)->relAttrSqlNodes[0].is_right = true;
                }
      }

      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[-3].expression)->relAttrSqlNodes.begin(),(yyvsp[-3].expression)->relAttrSqlNodes.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[-3].expression)->stringsqlExprs.begin(),(yyvsp[-3].expression)->stringsqlExprs.end());
      (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[-3].expression)->fieldExprs.begin(),(yyvsp[-3].expression)->fieldExprs.end());
      (yyval.expression)->expression.insert((yyval.expression)->expression.end(),(yyvsp[-3].expression)->expression.begin(),(yyvsp[-3].expression)->expression.end());
      if((yyvsp[-3].expression)->is_expression){
      (yyval.expression)->is_expression=true;
      }
      (yyval.expression)->expr_alias_map.insert((yyvsp[-3].expression)->expr_alias_map.begin(), (yyvsp[-3].expression)->expr_alias_map.end());
    }
#line 2823 "yacc_sql.cpp"
    break;

  case 93: /* expression: expression '+' expression  */
#line 928 "yacc_sql.y"
                              {
    (yyval.expression)=new ExpressionSqlNode;
      (yyval.expression)->expression.push_back(create_arithmetic_expression(ArithmeticExpr::Type::ADD, (yyvsp[-2].expression)->expression[0], (yyvsp[0].expression)->expression[0], sql_string, &(yyloc)));
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[-2].expression)->relAttrSqlNodes.begin(),(yyvsp[-2].expression)->relAttrSqlNodes.end());
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[-2].expression)->stringsqlExprs.begin(),(yyvsp[-2].expression)->stringsqlExprs.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[0].expression)->stringsqlExprs.begin(),(yyvsp[0].expression)->stringsqlExprs.end());
      (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[-2].expression)->fieldExprs.begin(),(yyvsp[-2].expression)->fieldExprs.end());
            (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
            (yyval.expression)->is_expression=true;
//      if ($4 != nullptr) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $4;
//      }
//      if ($1->relAttrSqlNodes.size() != 0 && !$1->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $1->relAttrSqlNodes[0].alias_name;
//        $1->relAttrSqlNodes[0].alias_name = "";
//      }
//      if ($3->relAttrSqlNodes.size() != 0 && !$3->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $3->relAttrSqlNodes[0].alias_name;
//        $3->relAttrSqlNodes[0].alias_name = "";
//      }
    }
#line 2850 "yacc_sql.cpp"
    break;

  case 94: /* expression: expression '-' expression  */
#line 950 "yacc_sql.y"
                                {
    (yyval.expression)=new ExpressionSqlNode;
      (yyval.expression)->expression.push_back( create_arithmetic_expression(ArithmeticExpr::Type::SUB, (yyvsp[-2].expression)->expression[0], (yyvsp[0].expression)->expression[0], sql_string, &(yyloc)));
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[-2].expression)->relAttrSqlNodes.begin(),(yyvsp[-2].expression)->relAttrSqlNodes.end());
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[-2].expression)->stringsqlExprs.begin(),(yyvsp[-2].expression)->stringsqlExprs.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[0].expression)->stringsqlExprs.begin(),(yyvsp[0].expression)->stringsqlExprs.end());
      (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[-2].expression)->fieldExprs.begin(),(yyvsp[-2].expression)->fieldExprs.end());
                  (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
                  (yyval.expression)->is_expression=true;
//      if ($4 != nullptr) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $4;
//      }
//      if ($1->relAttrSqlNodes.size() != 0 && !$1->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $1->relAttrSqlNodes[0].alias_name;
//        $1->relAttrSqlNodes[0].alias_name = "";
//      }
//      if ($3->relAttrSqlNodes.size() != 0 && !$3->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $3->relAttrSqlNodes[0].alias_name;
//        $3->relAttrSqlNodes[0].alias_name = "";
//      }
    }
#line 2877 "yacc_sql.cpp"
    break;

  case 95: /* expression: expression '*' expression  */
#line 972 "yacc_sql.y"
                                {
    (yyval.expression)=new ExpressionSqlNode;
      (yyval.expression)->expression.push_back( create_arithmetic_expression(ArithmeticExpr::Type::MUL, (yyvsp[-2].expression)->expression[0], (yyvsp[0].expression)->expression[0], sql_string, &(yyloc)));
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[-2].expression)->relAttrSqlNodes.begin(),(yyvsp[-2].expression)->relAttrSqlNodes.end());
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[-2].expression)->stringsqlExprs.begin(),(yyvsp[-2].expression)->stringsqlExprs.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[0].expression)->stringsqlExprs.begin(),(yyvsp[0].expression)->stringsqlExprs.end());
      (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[-2].expression)->fieldExprs.begin(),(yyvsp[-2].expression)->fieldExprs.end());
                  (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
                  (yyval.expression)->is_expression=true;
//      if ($4 != nullptr) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $4;
//      }
//      if ($1->relAttrSqlNodes.size() != 0 && !$1->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $1->relAttrSqlNodes[0].alias_name;
//        $1->relAttrSqlNodes[0].alias_name = "";
//      }
//      if ($3->relAttrSqlNodes.size() != 0 && !$3->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $3->relAttrSqlNodes[0].alias_name;
//        $3->relAttrSqlNodes[0].alias_name = "";
//      }
    }
#line 2904 "yacc_sql.cpp"
    break;

  case 96: /* expression: expression '/' expression  */
#line 994 "yacc_sql.y"
                                {
    (yyval.expression)=new ExpressionSqlNode;
      (yyval.expression)->expression.push_back(create_arithmetic_expression(ArithmeticExpr::Type::DIV, (yyvsp[-2].expression)->expression[0], (yyvsp[0].expression)->expression[0], sql_string, &(yyloc)));
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[-2].expression)->relAttrSqlNodes.begin(),(yyvsp[-2].expression)->relAttrSqlNodes.end());
      (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[-2].expression)->stringsqlExprs.begin(),(yyvsp[-2].expression)->stringsqlExprs.end());
      (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[0].expression)->stringsqlExprs.begin(),(yyvsp[0].expression)->stringsqlExprs.end());
      (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[-2].expression)->fieldExprs.begin(),(yyvsp[-2].expression)->fieldExprs.end());
                  (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
                  (yyval.expression)->is_expression=true;
//      if ($4 != nullptr) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $4;
//      }
//      if ($1->relAttrSqlNodes.size() != 0 && !$1->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $1->relAttrSqlNodes[0].alias_name;
//        $1->relAttrSqlNodes[0].alias_name = "";
//      }
//      if ($3->relAttrSqlNodes.size() != 0 && !$3->relAttrSqlNodes[0].alias_name.empty()) {
//        $$->expr_alias_map[token_name(sql_string, &@$)] = $3->relAttrSqlNodes[0].alias_name;
//        $3->relAttrSqlNodes[0].alias_name = "";
//      }
    }
#line 2931 "yacc_sql.cpp"
    break;

  case 97: /* expression: LBRACE expression RBRACE  */
#line 1016 "yacc_sql.y"
                               {
      (yyval.expression) = (yyvsp[-1].expression);
      (yyval.expression)->expression[0]->set_name(token_name(sql_string, &(yyloc)));
      (yyval.expression)->is_expression=true;
    }
#line 2941 "yacc_sql.cpp"
    break;

  case 98: /* expression: '-' expression  */
#line 1021 "yacc_sql.y"
                                  {
    (yyval.expression)=new ExpressionSqlNode;
    (yyval.expression)->expression.push_back( create_arithmetic_expression(ArithmeticExpr::Type::NEGATIVE, (yyvsp[0].expression)->expression[0], nullptr, sql_string, &(yyloc)));
    (yyval.expression)->relAttrSqlNodes.insert((yyval.expression)->relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
    (yyval.expression)->stringsqlExprs.insert((yyval.expression)->stringsqlExprs.end(),(yyvsp[0].expression)->stringsqlExprs.begin(),(yyvsp[0].expression)->stringsqlExprs.end());
    (yyval.expression)->fieldExprs.insert((yyval.expression)->fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
    (yyval.expression)->is_expression=true;
    }
#line 2954 "yacc_sql.cpp"
    break;

  case 99: /* expression: value  */
#line 1029 "yacc_sql.y"
            {
      (yyval.expression)=new ExpressionSqlNode;
      (yyval.expression)->expression.push_back( new ValueExpr(*(yyvsp[0].value)));
      (yyval.expression)->expression[0]->set_name(token_name(sql_string, &(yyloc)));
      (yyval.expression)->is_expression=false;
      (yyval.expression)->is_value=true;
      delete (yyvsp[0].value);
    }
#line 2967 "yacc_sql.cpp"
    break;

  case 100: /* expression: ID  */
#line 1037 "yacc_sql.y"
        {
    (yyval.expression)=new ExpressionSqlNode;
           auto relAttrSqlNode = new RelAttrSqlNode;
           relAttrSqlNode->attribute_name = (yyvsp[0].string);
           relAttrSqlNode->agg=NO_AGG;
           relAttrSqlNode->func = NO_FUNC;
           relAttrSqlNode->is_right=true;
//           if($2!=nullptr){
//           relAttrSqlNode->alias_name=$2;
//           }
    relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
    (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
    auto fieldExpr=new FieldExpr;
    fieldExpr->set_name(token_name(sql_string, &(yyloc)));
//    if($2!=nullptr){
//      std::string str = $2;
//      fieldExpr->set_alias_name(str);
//    }
    
    (yyval.expression)->expression.push_back(fieldExpr);
    (yyval.expression)->fieldExprs.push_back(fieldExpr);
    (yyval.expression)->is_expression=false;
    (yyval.expression)->is_value=false;
           free((yyvsp[0].string));
         }
#line 2997 "yacc_sql.cpp"
    break;

  case 101: /* expression: agg LBRACE arg_list RBRACE  */
#line 1062 "yacc_sql.y"
                                    {
         (yyval.expression)=new ExpressionSqlNode;
         auto relAttrSqlNode = new RelAttrSqlNode;
              if((yyvsp[-1].relation_list)==nullptr||(yyvsp[-1].relation_list)->size()!=1){
              relAttrSqlNode->is_right=false;
              }else{
              relAttrSqlNode->attribute_name = (*(yyvsp[-1].relation_list))[0];
              relAttrSqlNode->is_right=true;
              relAttrSqlNode->agg=(yyvsp[-3].agg);
              relAttrSqlNode->func = NO_FUNC;
              }
//              if($5!=nullptr){
//               relAttrSqlNode->alias_name=$5;
//              }
              relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
              (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
                  auto stringSqlExpr=new StringSqlExpr;
                  stringSqlExpr->set_name(token_name(sql_string, &(yyloc)));
                  (yyval.expression)->expression.push_back(stringSqlExpr);
                  (yyval.expression)->stringsqlExprs.push_back(stringSqlExpr);
                  (yyval.expression)->is_expression=false;
                  (yyval.expression)->is_value=false;
               free((yyvsp[-1].relation_list));

              }
#line 3027 "yacc_sql.cpp"
    break;

  case 102: /* expression: ID DOT ID  */
#line 1087 "yacc_sql.y"
                     {
         (yyval.expression)=new ExpressionSqlNode;
         auto relAttrSqlNode = new RelAttrSqlNode;
           relAttrSqlNode->relation_name  = (yyvsp[-2].string);
           relAttrSqlNode->attribute_name = (yyvsp[0].string);
           relAttrSqlNode->agg=NO_AGG;
           relAttrSqlNode->func = NO_FUNC;
           relAttrSqlNode->is_right=true;
//           if($4!=nullptr){
//           relAttrSqlNode->alias_name=$4;
//           }
           relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
               (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
               auto fieldExpr=new FieldExpr;
               fieldExpr->set_name(token_name(sql_string, &(yyloc)));
               (yyval.expression)->expression.push_back(fieldExpr);
               (yyval.expression)->fieldExprs.push_back(fieldExpr);
               (yyval.expression)->is_expression=false;
               (yyval.expression)->is_value=false;
           free((yyvsp[-2].string));
           free((yyvsp[0].string));
         }
#line 3054 "yacc_sql.cpp"
    break;

  case 103: /* expression: agg LBRACE ID DOT ID RBRACE  */
#line 1109 "yacc_sql.y"
                                      {
         (yyval.expression)=new ExpressionSqlNode;
                  auto relAttrSqlNode = new RelAttrSqlNode;
                    relAttrSqlNode->relation_name  = (yyvsp[-3].string);
                    relAttrSqlNode->attribute_name = (yyvsp[-1].string);
                    relAttrSqlNode->is_right=true;
                    relAttrSqlNode->agg=(yyvsp[-5].agg);
                    relAttrSqlNode->func = NO_FUNC;
//                    if($7!=nullptr){
//                          relAttrSqlNode->alias_name=$7;
//                          }
                    relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
                    (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
                    auto stringSqlExpr=new StringSqlExpr;
                    stringSqlExpr->set_name(token_name(sql_string, &(yyloc)));
                    (yyval.expression)->expression.push_back(stringSqlExpr);
                    (yyval.expression)->stringsqlExprs.push_back(stringSqlExpr);
                    (yyval.expression)->is_expression=false;
                    (yyval.expression)->is_value=false;
                    free((yyvsp[-3].string));
                    free((yyvsp[-1].string));
         }
#line 3081 "yacc_sql.cpp"
    break;

  case 104: /* expression: '*'  */
#line 1131 "yacc_sql.y"
              {
         (yyval.expression)=new ExpressionSqlNode;
         auto relAttrSqlNode = new RelAttrSqlNode;
               relAttrSqlNode->relation_name  = "";
               relAttrSqlNode->attribute_name = "*";
//               if($2!=nullptr){
//               relAttrSqlNode->is_right=false;
//               }else{
//               relAttrSqlNode->is_right=true;
//               }
               relAttrSqlNode->agg=NO_AGG;
               relAttrSqlNode->func = NO_FUNC;
               relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
               (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
               auto fieldExpr=new FieldExpr;
               fieldExpr->set_name(token_name(sql_string, &(yyloc)));
               (yyval.expression)->expression.push_back(fieldExpr);
               (yyval.expression)->fieldExprs.push_back(fieldExpr);
               (yyval.expression)->is_expression=false;
               (yyval.expression)->is_value=false;
             }
#line 3107 "yacc_sql.cpp"
    break;

  case 105: /* expression: ID DOT '*'  */
#line 1152 "yacc_sql.y"
                     {
         (yyval.expression)=new ExpressionSqlNode;
         auto relAttrSqlNode = new RelAttrSqlNode;
               relAttrSqlNode->relation_name  = (yyvsp[-2].string);
               relAttrSqlNode->attribute_name = "*";
//               if($4!=nullptr){
//               relAttrSqlNode->is_right=false;
//               }else{
//               relAttrSqlNode->is_right=true;
//               }

               relAttrSqlNode->agg=NO_AGG;
               relAttrSqlNode->func = NO_FUNC;
               relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
               (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);
               auto fieldExpr=new FieldExpr;
               fieldExpr->set_name(token_name(sql_string, &(yyloc)));
               (yyval.expression)->expression.push_back(fieldExpr);
               (yyval.expression)->fieldExprs.push_back(fieldExpr);
               (yyval.expression)->is_expression=false;
               (yyval.expression)->is_value=false;
         }
#line 3134 "yacc_sql.cpp"
    break;

  case 106: /* expression: LENGTH_func LBRACE length_func_param RBRACE  */
#line 1174 "yacc_sql.y"
                                                      {
          (yyval.expression)=new ExpressionSqlNode;
          auto relAttrSqlNode = new RelAttrSqlNode;
          relAttrSqlNode->relation_name  = (yyvsp[-1].length_func_param)->relation_name;
          relAttrSqlNode->attribute_name = (yyvsp[-1].length_func_param)->attribute_name;
          relAttrSqlNode->is_right = true;
//          if($5!=nullptr){relAttrSqlNode->alias_name=$5;}
          relAttrSqlNode->agg = NO_AGG;
          relAttrSqlNode->func = LENGTH_FUNC;
          relAttrSqlNode->lengthparam = *(yyvsp[-1].length_func_param);
          relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
          (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);

          (yyval.expression)->is_expression=false;
          (yyval.expression)->is_value=false;
        }
#line 3155 "yacc_sql.cpp"
    break;

  case 107: /* expression: ROUND_func LBRACE round_func_param RBRACE  */
#line 1190 "yacc_sql.y"
                                                    {
          (yyval.expression)=new ExpressionSqlNode;
          auto relAttrSqlNode = new RelAttrSqlNode;
          relAttrSqlNode->relation_name  = (yyvsp[-1].round_func_param)->relation_name;
          relAttrSqlNode->attribute_name = (yyvsp[-1].round_func_param)->attribute_name;
          relAttrSqlNode->is_right = true;
//          if($5!=nullptr){relAttrSqlNode->alias_name=$5;}
          relAttrSqlNode->agg = NO_AGG;
          relAttrSqlNode->func = ROUND_FUNC;
          relAttrSqlNode->roundparam = *(yyvsp[-1].round_func_param);
          relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
          (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);

          (yyval.expression)->is_expression=false;
          (yyval.expression)->is_value=false;

        }
#line 3177 "yacc_sql.cpp"
    break;

  case 108: /* expression: FORMAT_func LBRACE format_func_param RBRACE  */
#line 1207 "yacc_sql.y"
                                                      {
          (yyval.expression)=new ExpressionSqlNode;
          auto relAttrSqlNode = new RelAttrSqlNode;
          relAttrSqlNode->relation_name  = (yyvsp[-1].format_func_param)->relation_name;
          relAttrSqlNode->attribute_name = (yyvsp[-1].format_func_param)->attribute_name;
          relAttrSqlNode->is_right = true;
//          if($5!=nullptr){relAttrSqlNode->alias_name=$5;}
          relAttrSqlNode->agg = NO_AGG;
          relAttrSqlNode->func = FORMAT_FUNC;
          relAttrSqlNode->formatparam = *(yyvsp[-1].format_func_param);
          relAttrSqlNode->sqlString=token_name(sql_string, &(yyloc));
          (yyval.expression)->relAttrSqlNodes.push_back(*relAttrSqlNode);

          (yyval.expression)->is_expression=false;
          (yyval.expression)->is_value=false;
        }
#line 3198 "yacc_sql.cpp"
    break;

  case 109: /* arg_list: %empty  */
#line 1254 "yacc_sql.y"
    {
      (yyval.relation_list) = nullptr;
    }
#line 3206 "yacc_sql.cpp"
    break;

  case 110: /* arg_list: '*'  */
#line 1257 "yacc_sql.y"
         {
    (yyval.relation_list)=new std::vector<std::string>;
    (yyval.relation_list)->push_back("*");

    }
#line 3216 "yacc_sql.cpp"
    break;

  case 111: /* arg_list: '*' COMMA arg_list  */
#line 1262 "yacc_sql.y"
                       {
    if((yyvsp[0].relation_list)!=nullptr){
    (yyval.relation_list)=(yyvsp[0].relation_list);
    }else{
    (yyval.relation_list)=new std::vector<std::string>;
    }

     (yyval.relation_list)->push_back("*");
    }
#line 3230 "yacc_sql.cpp"
    break;

  case 112: /* arg_list: ID  */
#line 1271 "yacc_sql.y"
         {
    (yyval.relation_list)=new std::vector<std::string>;
    (yyval.relation_list)->push_back((yyvsp[0].string));
    }
#line 3239 "yacc_sql.cpp"
    break;

  case 113: /* arg_list: ID COMMA arg_list  */
#line 1275 "yacc_sql.y"
                      {
    if((yyvsp[0].relation_list)!=nullptr){
        (yyval.relation_list)=(yyvsp[0].relation_list);
        }else{
        (yyval.relation_list)=new std::vector<std::string>;
        }
        (yyval.relation_list)->push_back((yyvsp[-2].string));
    }
#line 3252 "yacc_sql.cpp"
    break;

  case 114: /* rel_attr: ID as  */
#line 1284 "yacc_sql.y"
         {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      (yyval.rel_attr)->agg=NO_AGG;
      (yyval.rel_attr)->is_right=true;
      if((yyvsp[0].string)!=nullptr){
      (yyval.rel_attr)->alias_name=(yyvsp[0].string);
      }

      free((yyvsp[-1].string));
    }
#line 3268 "yacc_sql.cpp"
    break;

  case 115: /* rel_attr: agg LBRACE arg_list RBRACE as  */
#line 1295 "yacc_sql.y"
                                  {
         (yyval.rel_attr) = new RelAttrSqlNode;
         if((yyvsp[-2].relation_list)==nullptr||(yyvsp[-2].relation_list)->size()!=1){
         (yyval.rel_attr)->is_right=false;
         }else{
         (yyval.rel_attr)->attribute_name = (*(yyvsp[-2].relation_list))[0];
         (yyval.rel_attr)->is_right=true;
         (yyval.rel_attr)->agg=(yyvsp[-4].agg);
         }
         if((yyvsp[0].string)!=nullptr){
          (yyval.rel_attr)->alias_name=(yyvsp[0].string);
         }
          free((yyvsp[-2].relation_list));

         }
#line 3288 "yacc_sql.cpp"
    break;

  case 116: /* rel_attr: ID DOT ID as  */
#line 1310 "yacc_sql.y"
                  {
      (yyval.rel_attr) = new RelAttrSqlNode;
      (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
      (yyval.rel_attr)->attribute_name = (yyvsp[-1].string);
      (yyval.rel_attr)->agg=NO_AGG;
      (yyval.rel_attr)->is_right=true;
      if((yyvsp[0].string)!=nullptr){
      (yyval.rel_attr)->alias_name=(yyvsp[0].string);
      }
      free((yyvsp[-3].string));
      free((yyvsp[-1].string));
    }
#line 3305 "yacc_sql.cpp"
    break;

  case 117: /* rel_attr: agg LBRACE ID DOT ID RBRACE as  */
#line 1322 "yacc_sql.y"
                                    {
               (yyval.rel_attr) = new RelAttrSqlNode;
               (yyval.rel_attr)->relation_name  = (yyvsp[-4].string);
               (yyval.rel_attr)->attribute_name = (yyvsp[-2].string);
               (yyval.rel_attr)->is_right=true;
               (yyval.rel_attr)->agg=(yyvsp[-6].agg);
               if((yyvsp[0].string)!=nullptr){
                     (yyval.rel_attr)->alias_name=(yyvsp[0].string);
                     }
               free((yyvsp[-4].string));
               free((yyvsp[-2].string));
    }
#line 3322 "yacc_sql.cpp"
    break;

  case 118: /* rel_attr: '*' as  */
#line 1334 "yacc_sql.y"
            {
          (yyval.rel_attr) = new RelAttrSqlNode;
          (yyval.rel_attr)->relation_name  = "";
          (yyval.rel_attr)->attribute_name = "*";
          if((yyvsp[0].string)!=nullptr){
          (yyval.rel_attr)->is_right=false;
          }else{
          (yyval.rel_attr)->is_right=true;
          }

          (yyval.rel_attr)->agg=NO_AGG;
        }
#line 3339 "yacc_sql.cpp"
    break;

  case 119: /* rel_attr: ID DOT '*' as  */
#line 1346 "yacc_sql.y"
                   {
           (yyval.rel_attr) = new RelAttrSqlNode;
          (yyval.rel_attr)->relation_name  = (yyvsp[-3].string);
          (yyval.rel_attr)->attribute_name = "*";
          if((yyvsp[0].string)!=nullptr){
          (yyval.rel_attr)->is_right=false;
          }else{
          (yyval.rel_attr)->is_right=true;
          }

          (yyval.rel_attr)->agg=NO_AGG;
    }
#line 3356 "yacc_sql.cpp"
    break;

  case 120: /* attr_list: %empty  */
#line 1362 "yacc_sql.y"
    {
      (yyval.rel_attr_list) = nullptr;
    }
#line 3364 "yacc_sql.cpp"
    break;

  case 121: /* attr_list: COMMA rel_attr attr_list  */
#line 1365 "yacc_sql.y"
                               {
      if ((yyvsp[0].rel_attr_list) != nullptr) {
        (yyval.rel_attr_list) = (yyvsp[0].rel_attr_list);
      } else {
        (yyval.rel_attr_list) = new std::vector<RelAttrSqlNode>;
      }

      (yyval.rel_attr_list)->emplace_back(*(yyvsp[-1].rel_attr));
      delete (yyvsp[-1].rel_attr);
    }
#line 3379 "yacc_sql.cpp"
    break;

  case 122: /* rel_list: %empty  */
#line 1379 "yacc_sql.y"
    {
      (yyval.inner_join_list) = nullptr;
    }
#line 3387 "yacc_sql.cpp"
    break;

  case 123: /* rel_list: COMMA ID as rel_list  */
#line 1382 "yacc_sql.y"
                           {
      if ((yyvsp[0].inner_join_list) != nullptr) {
        (yyval.inner_join_list) = (yyvsp[0].inner_join_list);
      } else {
        (yyval.inner_join_list) = new InnerJoinSqlNode;
      }
      if((yyvsp[-1].string)!=nullptr){
      if((yyval.inner_join_list)->alias_map.find((yyvsp[-1].string))==(yyval.inner_join_list)->alias_map.end()){
      (yyval.inner_join_list)->alias_map[(yyvsp[-1].string)]=(yyvsp[-2].string);
      }else{
      (yyval.inner_join_list)->is_alias_right=false;
      }
      }

      (yyval.inner_join_list)->relations.push_back((yyvsp[-2].string));
      free((yyvsp[-2].string));
    }
#line 3409 "yacc_sql.cpp"
    break;

  case 124: /* rel_list: INNER JOIN ID as on rel_list  */
#line 1399 "yacc_sql.y"
                                  {
           if ((yyvsp[0].inner_join_list) != nullptr) {
             (yyval.inner_join_list) = (yyvsp[0].inner_join_list);
           } else {
             (yyval.inner_join_list) = new InnerJoinSqlNode;
           }

           (yyval.inner_join_list)->relations.push_back((yyvsp[-3].string));
           if((yyvsp[-1].condition_list)!=nullptr){
           (yyval.inner_join_list)->conditions.insert((yyval.inner_join_list)->conditions.end(),(yyvsp[-1].condition_list)->begin(),(yyvsp[-1].condition_list)->end());
           }
           if((yyvsp[-2].string)!=nullptr){
           if((yyval.inner_join_list)->alias_map.find((yyvsp[-2].string))==(yyval.inner_join_list)->alias_map.end()){
           (yyval.inner_join_list)->alias_map[(yyvsp[-2].string)]=(yyvsp[-3].string);
           }else{
           (yyval.inner_join_list)->is_alias_right=false;
           }

           }

           free((yyvsp[-3].string));
         }
#line 3436 "yacc_sql.cpp"
    break;

  case 125: /* length_func_param: ID  */
#line 1425 "yacc_sql.y"
     {
    (yyval.length_func_param) = new LengthParam;
    (yyval.length_func_param)->attribute_name = (yyvsp[0].string);
    free((yyvsp[0].string));
  }
#line 3446 "yacc_sql.cpp"
    break;

  case 126: /* length_func_param: ID DOT ID  */
#line 1430 "yacc_sql.y"
              {
    (yyval.length_func_param) = new LengthParam;
    (yyval.length_func_param)->relation_name = (yyvsp[-2].string);
    (yyval.length_func_param)->attribute_name = (yyvsp[0].string);
    free((yyvsp[-2].string));
    free((yyvsp[0].string));
  }
#line 3458 "yacc_sql.cpp"
    break;

  case 127: /* length_func_param: PATTERN  */
#line 1437 "yacc_sql.y"
            {
    (yyval.length_func_param) = new LengthParam;

    char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
    (yyval.length_func_param)->raw_data = Value(tmp,CHARS);
    free(tmp);
    free((yyvsp[0].string));
  }
#line 3471 "yacc_sql.cpp"
    break;

  case 128: /* round_func_param: ID COMMA NUMBER  */
#line 1448 "yacc_sql.y"
                  {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->attribute_name = (yyvsp[-2].string);
    (yyval.round_func_param)->bits = Value((int)(yyvsp[0].number));
    free((yyvsp[-2].string));
  }
#line 3482 "yacc_sql.cpp"
    break;

  case 129: /* round_func_param: ID  */
#line 1454 "yacc_sql.y"
       {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->attribute_name = (yyvsp[0].string);
    free((yyvsp[0].string));
  }
#line 3492 "yacc_sql.cpp"
    break;

  case 130: /* round_func_param: ID DOT ID COMMA NUMBER  */
#line 1459 "yacc_sql.y"
                           {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->relation_name = (yyvsp[-4].string);
    (yyval.round_func_param)->attribute_name = (yyvsp[-2].string);
    (yyval.round_func_param)->bits = Value((int)(yyvsp[0].number));
    free((yyvsp[-4].string));
    free((yyvsp[-2].string));
  }
#line 3505 "yacc_sql.cpp"
    break;

  case 131: /* round_func_param: ID DOT ID  */
#line 1467 "yacc_sql.y"
              {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->relation_name = (yyvsp[-2].string);
    (yyval.round_func_param)->attribute_name = (yyvsp[0].string);
    free((yyvsp[-2].string));
    free((yyvsp[0].string));
  }
#line 3517 "yacc_sql.cpp"
    break;

  case 132: /* round_func_param: FLOAT COMMA NUMBER  */
#line 1474 "yacc_sql.y"
                       {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->raw_data = Value((float)(yyvsp[-2].floats));
    (yyval.round_func_param)->bits = Value((int)(yyvsp[0].number));
  }
#line 3527 "yacc_sql.cpp"
    break;

  case 133: /* round_func_param: FLOAT  */
#line 1479 "yacc_sql.y"
          {
    (yyval.round_func_param) = new RoundParam;
    (yyval.round_func_param)->raw_data = Value((float)(yyvsp[0].floats));
  }
#line 3536 "yacc_sql.cpp"
    break;

  case 134: /* format_func_param: ID COMMA PATTERN  */
#line 1486 "yacc_sql.y"
                   {
    (yyval.format_func_param) = new FormatParam;
    (yyval.format_func_param)->attribute_name = (yyvsp[-2].string);

    char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
    (yyval.format_func_param)->format = Value(tmp,CHARS);
    free(tmp); 
    free((yyvsp[-2].string));
  }
#line 3550 "yacc_sql.cpp"
    break;

  case 135: /* format_func_param: ID DOT ID COMMA PATTERN  */
#line 1495 "yacc_sql.y"
                            {
    (yyval.format_func_param) = new FormatParam;
    (yyval.format_func_param)->relation_name = (yyvsp[-4].string);
    (yyval.format_func_param)->attribute_name = (yyvsp[-2].string);

    char *tmp = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
    (yyval.format_func_param)->format = Value(tmp,CHARS);
    free(tmp); 
    free((yyvsp[-4].string));
    free((yyvsp[-2].string));
  }
#line 3566 "yacc_sql.cpp"
    break;

  case 136: /* format_func_param: DATE COMMA PATTERN  */
#line 1506 "yacc_sql.y"
                       {
    (yyval.format_func_param) = new FormatParam;

    char *tmp = common::substr((yyvsp[-2].string),1,strlen((yyvsp[-2].string))-2);
    (yyval.format_func_param)->raw_data = Value(tmp,DATES);
    free(tmp);

    char *tmp2 = common::substr((yyvsp[0].string),1,strlen((yyvsp[0].string))-2);
    (yyval.format_func_param)->format = Value(tmp2,CHARS);
    free(tmp2);
    free((yyvsp[0].string));
  }
#line 3583 "yacc_sql.cpp"
    break;

  case 137: /* where: %empty  */
#line 1522 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3591 "yacc_sql.cpp"
    break;

  case 138: /* where: WHERE condition_list  */
#line 1525 "yacc_sql.y"
                           {
      (yyval.condition_list) = (yyvsp[0].condition_list);  
    }
#line 3599 "yacc_sql.cpp"
    break;

  case 139: /* on: %empty  */
#line 1531 "yacc_sql.y"
     {
        (yyval.condition_list) = nullptr;
     }
#line 3607 "yacc_sql.cpp"
    break;

  case 140: /* on: ON condition_list  */
#line 1534 "yacc_sql.y"
                         {
        (yyval.condition_list) = (yyvsp[0].condition_list);
     }
#line 3615 "yacc_sql.cpp"
    break;

  case 141: /* condition_list: %empty  */
#line 1540 "yacc_sql.y"
    {
      (yyval.condition_list) = nullptr;
    }
#line 3623 "yacc_sql.cpp"
    break;

  case 142: /* condition_list: condition  */
#line 1543 "yacc_sql.y"
                {
      (yyval.condition_list) = new std::vector<ConditionSqlNode>;
      (yyvsp[0].condition)->is_conjunction_or=false;
      (yyval.condition_list)->emplace_back(*(yyvsp[0].condition));
      delete (yyvsp[0].condition);
    }
#line 3634 "yacc_sql.cpp"
    break;

  case 143: /* condition_list: condition AND condition_list  */
#line 1549 "yacc_sql.y"
                                   {
      (yyval.condition_list) = (yyvsp[0].condition_list);
      (yyvsp[-2].condition)->is_conjunction_or=false;
      (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
      delete (yyvsp[-2].condition);
    }
#line 3645 "yacc_sql.cpp"
    break;

  case 144: /* condition_list: condition OR condition_list  */
#line 1555 "yacc_sql.y"
                                  {
           (yyval.condition_list) = (yyvsp[0].condition_list);
           (yyvsp[-2].condition)->is_conjunction_or=true;
           (yyval.condition_list)->emplace_back(*(yyvsp[-2].condition));
           delete (yyvsp[-2].condition);
         }
#line 3656 "yacc_sql.cpp"
    break;

  case 145: /* condition: expression comp_op expression  */
#line 1792 "yacc_sql.y"
                                  {
          (yyval.condition) = new ConditionSqlNode;
          if((yyvsp[-2].expression)->is_expression==false){
          if((yyvsp[-2].expression)->is_value==true){
          (yyval.condition)->left_type=VALUE_TYPE;
          (yyval.condition)->left_value=((ValueExpr*)((yyvsp[-2].expression)->expression[0]))->get_value();
          }else{
             (yyval.condition)->left_type = ATTR_TYPE;
             (yyval.condition)->left_attr = (yyvsp[-2].expression)->relAttrSqlNodes[0];
          }
          }else{
          (yyval.condition)->left_type = EXPR_TYPE;
          (yyval.condition)->left_expr = (yyvsp[-2].expression)->expression[0];
          (yyval.condition)->left_relAttrSqlNodes.insert((yyval.condition)->left_relAttrSqlNodes.end(),(yyvsp[-2].expression)->relAttrSqlNodes.begin(),(yyvsp[-2].expression)->relAttrSqlNodes.end());
          (yyval.condition)->left_fieldExprs.insert((yyval.condition)->left_fieldExprs.end(),(yyvsp[-2].expression)->fieldExprs.begin(),(yyvsp[-2].expression)->fieldExprs.end());
          }

          if((yyvsp[0].expression)->is_expression==false){
          if((yyvsp[0].expression)->is_value==true){
          (yyval.condition)->right_type=VALUE_TYPE;
          (yyval.condition)->right_value=((ValueExpr*)((yyvsp[0].expression)->expression[0]))->get_value();
          }else{
          (yyval.condition)->right_type = ATTR_TYPE;
          (yyval.condition)->right_attr = (yyvsp[0].expression)->relAttrSqlNodes[0];
          }
          }else{
          (yyval.condition)->right_type = EXPR_TYPE;
          (yyval.condition)->right_expr = (yyvsp[0].expression)->expression[0];
          (yyval.condition)->right_relAttrSqlNodes.insert((yyval.condition)->right_relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
          (yyval.condition)->right_fieldExprs.insert((yyval.condition)->right_fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
          }
          (yyval.condition)->comp = (yyvsp[-1].comp);



     }
#line 3697 "yacc_sql.cpp"
    break;

  case 146: /* condition: expression comp_op LBRACE select_stmt RBRACE  */
#line 1828 "yacc_sql.y"
                                                   {
          (yyval.condition) = new ConditionSqlNode;
          if((yyvsp[-4].expression)->is_expression==false){
          if((yyvsp[-4].expression)->is_value==true){
          (yyval.condition)->left_type=VALUE_TYPE;
          (yyval.condition)->left_value=((ValueExpr*)((yyvsp[-4].expression)->expression[0]))->get_value();
          }else{
                 (yyval.condition)->left_type = ATTR_TYPE;
                 (yyval.condition)->left_attr = (yyvsp[-4].expression)->relAttrSqlNodes[0];
          }
          }else{
          (yyval.condition)->left_type = EXPR_TYPE;
          (yyval.condition)->left_expr = (yyvsp[-4].expression)->expression[0];
          (yyval.condition)->left_relAttrSqlNodes.insert((yyval.condition)->left_relAttrSqlNodes.end(),(yyvsp[-4].expression)->relAttrSqlNodes.begin(),(yyvsp[-4].expression)->relAttrSqlNodes.end());
          (yyval.condition)->left_fieldExprs.insert((yyval.condition)->left_fieldExprs.end(),(yyvsp[-4].expression)->fieldExprs.begin(),(yyvsp[-4].expression)->fieldExprs.end());
          }

          (yyval.condition)->right_type = SUB_SELECT_TYPE;
          (yyval.condition)->right_select = &((yyvsp[-1].sql_node)->selection);
          (yyval.condition)->right_select->is_sub_select=true;
          (yyval.condition)->comp = (yyvsp[-3].comp);

     }
#line 3725 "yacc_sql.cpp"
    break;

  case 147: /* condition: LBRACE select_stmt RBRACE comp_op expression  */
#line 1851 "yacc_sql.y"
                                                   {
          (yyval.condition) = new ConditionSqlNode;

          if((yyvsp[0].expression)->is_expression==false){
          if((yyvsp[0].expression)->is_value==true){
          (yyval.condition)->right_type=VALUE_TYPE;
          (yyval.condition)->right_value=((ValueExpr*)((yyvsp[0].expression)->expression[0]))->get_value();
          }else{
          (yyval.condition)->right_type = ATTR_TYPE;
          (yyval.condition)->right_attr = (yyvsp[0].expression)->relAttrSqlNodes[0];
          }
          }else{
          (yyval.condition)->right_type = EXPR_TYPE;
          (yyval.condition)->right_expr = (yyvsp[0].expression)->expression[0];
          (yyval.condition)->right_relAttrSqlNodes.insert((yyval.condition)->right_relAttrSqlNodes.end(),(yyvsp[0].expression)->relAttrSqlNodes.begin(),(yyvsp[0].expression)->relAttrSqlNodes.end());
          (yyval.condition)->right_fieldExprs.insert((yyval.condition)->right_fieldExprs.end(),(yyvsp[0].expression)->fieldExprs.begin(),(yyvsp[0].expression)->fieldExprs.end());
          }


          (yyval.condition)->left_type = SUB_SELECT_TYPE;
          (yyval.condition)->left_select = &((yyvsp[-3].sql_node)->selection);
          (yyval.condition)->left_select->is_sub_select=true;
          (yyval.condition)->comp = (yyvsp[-1].comp);

     }
#line 3755 "yacc_sql.cpp"
    break;

  case 148: /* condition: LBRACE select_stmt RBRACE comp_op LBRACE select_stmt RBRACE  */
#line 1876 "yacc_sql.y"
                                                                 {
         (yyval.condition) = new ConditionSqlNode;
         (yyval.condition)->left_type = SUB_SELECT_TYPE;
         (yyval.condition)->left_select =  &((yyvsp[-5].sql_node)->selection);
         (yyval.condition)->left_select->is_sub_select=true;
         (yyval.condition)->right_type = SUB_SELECT_TYPE;
         (yyval.condition)->right_select =  &((yyvsp[-1].sql_node)->selection);
         (yyval.condition)->right_select->is_sub_select=true;
         (yyval.condition)->comp = (yyvsp[-3].comp);


     }
#line 3772 "yacc_sql.cpp"
    break;

  case 149: /* condition: EXISTS LBRACE select_stmt RBRACE  */
#line 1888 "yacc_sql.y"
                                      {
              (yyval.condition) = new ConditionSqlNode;
              (yyval.condition)->right_type = SUB_SELECT_TYPE;
              (yyval.condition)->right_select =  &((yyvsp[-1].sql_node)->selection);
              (yyval.condition)->right_select->is_sub_select=true;
              (yyval.condition)->comp = EXISTS_OP;

     }
#line 3785 "yacc_sql.cpp"
    break;

  case 150: /* condition: NOT EXISTS LBRACE select_stmt RBRACE  */
#line 1896 "yacc_sql.y"
                                           {
         (yyval.condition) = new ConditionSqlNode;
         (yyval.condition)->right_type = SUB_SELECT_TYPE;
         (yyval.condition)->right_select =  &((yyvsp[-1].sql_node)->selection);
         (yyval.condition)->right_select->is_sub_select=true;
         (yyval.condition)->comp = NOT_EXISTS_OP;
     }
#line 3797 "yacc_sql.cpp"
    break;

  case 151: /* condition: expression comp_op LBRACE value COMMA value value_list RBRACE  */
#line 1903 "yacc_sql.y"
                                                                   {
         (yyval.condition) = new ConditionSqlNode;

         if((yyvsp[-7].expression)->is_expression==false){
         if((yyvsp[-7].expression)->is_value==true){
         (yyval.condition)->left_type=VALUE_TYPE;
         (yyval.condition)->left_value=((ValueExpr*)((yyvsp[-7].expression)->expression[0]))->get_value();
         }else{
         (yyval.condition)->left_type = ATTR_TYPE;
         (yyval.condition)->left_attr = (yyvsp[-7].expression)->relAttrSqlNodes[0];
         }
         }else{
         (yyval.condition)->left_type = EXPR_TYPE;
         (yyval.condition)->left_expr = (yyvsp[-7].expression)->expression[0];
         (yyval.condition)->left_relAttrSqlNodes.insert((yyval.condition)->left_relAttrSqlNodes.end(),(yyvsp[-7].expression)->relAttrSqlNodes.begin(),(yyvsp[-7].expression)->relAttrSqlNodes.end());
         (yyval.condition)->left_fieldExprs.insert((yyval.condition)->left_fieldExprs.end(),(yyvsp[-7].expression)->fieldExprs.begin(),(yyvsp[-7].expression)->fieldExprs.end());
         }

         (yyval.condition)->right_type = VALUE_LIST_TYPE;
         if((yyvsp[-1].value_list)!=nullptr){
         (yyval.condition)->right_value_list.insert((yyval.condition)->right_value_list.end(),(yyvsp[-1].value_list)->begin(),(yyvsp[-1].value_list)->end());
          }
          (yyval.condition)->right_value_list.push_back(*(yyvsp[-2].value));
          (yyval.condition)->right_value_list.push_back(*(yyvsp[-4].value));
          std::reverse((yyval.condition)->right_value_list.begin(),(yyval.condition)->right_value_list.end());
          (yyval.condition)->comp = (yyvsp[-6].comp);
     }
#line 3829 "yacc_sql.cpp"
    break;

  case 152: /* comp_op: EQ  */
#line 1934 "yacc_sql.y"
         { (yyval.comp) = EQUAL_TO; }
#line 3835 "yacc_sql.cpp"
    break;

  case 153: /* comp_op: LT  */
#line 1935 "yacc_sql.y"
         { (yyval.comp) = LESS_THAN; }
#line 3841 "yacc_sql.cpp"
    break;

  case 154: /* comp_op: GT  */
#line 1936 "yacc_sql.y"
         { (yyval.comp) = GREAT_THAN; }
#line 3847 "yacc_sql.cpp"
    break;

  case 155: /* comp_op: LE  */
#line 1937 "yacc_sql.y"
         { (yyval.comp) = LESS_EQUAL; }
#line 3853 "yacc_sql.cpp"
    break;

  case 156: /* comp_op: GE  */
#line 1938 "yacc_sql.y"
         { (yyval.comp) = GREAT_EQUAL; }
#line 3859 "yacc_sql.cpp"
    break;

  case 157: /* comp_op: NE  */
#line 1939 "yacc_sql.y"
         { (yyval.comp) = NOT_EQUAL; }
#line 3865 "yacc_sql.cpp"
    break;

  case 158: /* comp_op: LK  */
#line 1940 "yacc_sql.y"
         {(yyval.comp) = LIKE;}
#line 3871 "yacc_sql.cpp"
    break;

  case 159: /* comp_op: NOT LK  */
#line 1941 "yacc_sql.y"
             {(yyval.comp) = NOT_LIKE;}
#line 3877 "yacc_sql.cpp"
    break;

  case 160: /* comp_op: IS  */
#line 1942 "yacc_sql.y"
            {(yyval.comp)=IS_NULL;}
#line 3883 "yacc_sql.cpp"
    break;

  case 161: /* comp_op: IS NOT  */
#line 1943 "yacc_sql.y"
             {(yyval.comp)=IS_NOT_NULL;}
#line 3889 "yacc_sql.cpp"
    break;

  case 162: /* comp_op: IN  */
#line 1944 "yacc_sql.y"
           {(yyval.comp)=IN_OP;}
#line 3895 "yacc_sql.cpp"
    break;

  case 163: /* comp_op: NOT IN  */
#line 1945 "yacc_sql.y"
             {(yyval.comp)=NOT_IN_OP;}
#line 3901 "yacc_sql.cpp"
    break;

  case 164: /* agg: MAX_agg  */
#line 1948 "yacc_sql.y"
           {(yyval.agg)=MAX_AGG;}
#line 3907 "yacc_sql.cpp"
    break;

  case 165: /* agg: MIN_agg  */
#line 1949 "yacc_sql.y"
            {(yyval.agg)=MIN_AGG;}
#line 3913 "yacc_sql.cpp"
    break;

  case 166: /* agg: AVG_agg  */
#line 1950 "yacc_sql.y"
            {(yyval.agg)=AVG_AGG;}
#line 3919 "yacc_sql.cpp"
    break;

  case 167: /* agg: COUNT_agg  */
#line 1951 "yacc_sql.y"
              {(yyval.agg)=COUNT_AGG;}
#line 3925 "yacc_sql.cpp"
    break;

  case 168: /* agg: SUM_agg  */
#line 1952 "yacc_sql.y"
            {(yyval.agg)=SUM_AGG;}
#line 3931 "yacc_sql.cpp"
    break;

  case 169: /* as: %empty  */
#line 1955 "yacc_sql.y"
  {
    (yyval.string) = nullptr;
  }
#line 3939 "yacc_sql.cpp"
    break;

  case 170: /* as: AS ID  */
#line 1958 "yacc_sql.y"
          {
    (yyval.string) = (yyvsp[0].string);
  }
#line 3947 "yacc_sql.cpp"
    break;

  case 171: /* as: ID  */
#line 1961 "yacc_sql.y"
       {
    (yyval.string) = (yyvsp[0].string);
  }
#line 3955 "yacc_sql.cpp"
    break;

  case 172: /* as: AS SUM_agg  */
#line 1964 "yacc_sql.y"
               {
    char* str = "sum";
    (yyval.string) = str;
  }
#line 3964 "yacc_sql.cpp"
    break;

  case 173: /* load_data_stmt: LOAD DATA INFILE SSS INTO TABLE ID  */
#line 1971 "yacc_sql.y"
    {
      char *tmp_file_name = common::substr((yyvsp[-3].string), 1, strlen((yyvsp[-3].string)) - 2);
      
      (yyval.sql_node) = new ParsedSqlNode(SCF_LOAD_DATA);
      (yyval.sql_node)->load_data.relation_name = (yyvsp[0].string);
      (yyval.sql_node)->load_data.file_name = tmp_file_name;
      free((yyvsp[0].string));
      free(tmp_file_name);
    }
#line 3978 "yacc_sql.cpp"
    break;

  case 174: /* explain_stmt: EXPLAIN command_wrapper  */
#line 1984 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_EXPLAIN);
      (yyval.sql_node)->explain.sql_node = std::unique_ptr<ParsedSqlNode>((yyvsp[0].sql_node));
    }
#line 3987 "yacc_sql.cpp"
    break;

  case 175: /* set_variable_stmt: SET ID EQ value  */
#line 1992 "yacc_sql.y"
    {
      (yyval.sql_node) = new ParsedSqlNode(SCF_SET_VARIABLE);
      (yyval.sql_node)->set_variable.name  = (yyvsp[-2].string);
      (yyval.sql_node)->set_variable.value = *(yyvsp[0].value);
      free((yyvsp[-2].string));
      delete (yyvsp[0].value);
    }
#line 3999 "yacc_sql.cpp"
    break;


#line 4003 "yacc_sql.cpp"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (&yylloc, sql_string, sql_result, scanner, yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          goto yyexhaustedlab;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if 1
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (&yylloc, sql_string, sql_result, scanner, YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc, sql_string, sql_result, scanner);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp, sql_string, sql_result, scanner);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 2004 "yacc_sql.y"

//_____________________________________________________________________
extern void scan_string(const char *str, yyscan_t scanner);

int sql_parse(const char *s, ParsedSqlResult *sql_result) {
  yyscan_t scanner;
  yylex_init(&scanner);
  scan_string(s, scanner);
  int result = yyparse(s, sql_result, scanner);
  yylex_destroy(scanner);
  return result;
}
