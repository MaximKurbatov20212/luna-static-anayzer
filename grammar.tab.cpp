/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "grammar.ypp"


#include "error_reporter.hpp"
#include "ast.hpp"

#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>

#include <string>
#include <cstring>
#include <string.h>

#include <vector>
#include <sstream>
#include <set>

using namespace std;

extern int yylex(void);
void yyerror(const char*);

extern int line_num; 
extern string line, prev_line; 

int cur_position_in_line = 0;
extern program* ast;

error_reporter reporter;


#line 104 "grammar.tab.cpp"

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

#include "grammar.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_STRING = 3,                     /* STRING  */
  YYSYMBOL_NAME = 4,                       /* NAME  */
  YYSYMBOL_INT = 5,                        /* INT  */
  YYSYMBOL_REAL = 6,                       /* REAL  */
  YYSYMBOL_SCOLON = 7,                     /* SCOLON  */
  YYSYMBOL_COMMA = 8,                      /* COMMA  */
  YYSYMBOL_COLON = 9,                      /* COLON  */
  YYSYMBOL_DOT = 10,                       /* DOT  */
  YYSYMBOL_SHARP = 11,                     /* SHARP  */
  YYSYMBOL_ARROW = 12,                     /* ARROW  */
  YYSYMBOL_LARROW = 13,                    /* LARROW  */
  YYSYMBOL_LARR = 14,                      /* LARR  */
  YYSYMBOL_RARR = 15,                      /* RARR  */
  YYSYMBOL_AMP = 16,                       /* AMP  */
  YYSYMBOL_KW_CF = 17,                     /* KW_CF  */
  YYSYMBOL_KW_DF = 18,                     /* KW_DF  */
  YYSYMBOL_KW_IMPORT = 19,                 /* KW_IMPORT  */
  YYSYMBOL_KW_AS = 20,                     /* KW_AS  */
  YYSYMBOL_KW_FOR = 21,                    /* KW_FOR  */
  YYSYMBOL_KW_IF = 22,                     /* KW_IF  */
  YYSYMBOL_KW_LET = 23,                    /* KW_LET  */
  YYSYMBOL_KW_VALUE = 24,                  /* KW_VALUE  */
  YYSYMBOL_KW_CUDA = 25,                   /* KW_CUDA  */
  YYSYMBOL_KW_NOCPU = 26,                  /* KW_NOCPU  */
  YYSYMBOL_KW_IN = 27,                     /* KW_IN  */
  YYSYMBOL_KW_OUT = 28,                    /* KW_OUT  */
  YYSYMBOL_KW_SIZE = 29,                   /* KW_SIZE  */
  YYSYMBOL_KW_SUB = 30,                    /* KW_SUB  */
  YYSYMBOL_KW_WHILE = 31,                  /* KW_WHILE  */
  YYSYMBOL_KW_INT = 32,                    /* KW_INT  */
  YYSYMBOL_KW_NAME = 33,                   /* KW_NAME  */
  YYSYMBOL_KW_REAL = 34,                   /* KW_REAL  */
  YYSYMBOL_KW_STRING = 35,                 /* KW_STRING  */
  YYSYMBOL_KW_RUSH = 36,                   /* KW_RUSH  */
  YYSYMBOL_KW_STATIC = 37,                 /* KW_STATIC  */
  YYSYMBOL_KW_STATIC_FOR = 38,             /* KW_STATIC_FOR  */
  YYSYMBOL_KW_UNROLLING = 39,              /* KW_UNROLLING  */
  YYSYMBOL_KW_BLOCK = 40,                  /* KW_BLOCK  */
  YYSYMBOL_KW_CPP = 41,                    /* KW_CPP  */
  YYSYMBOL_INTERPRETER = 42,               /* INTERPRETER  */
  YYSYMBOL_EQ = 43,                        /* EQ  */
  YYSYMBOL_LB = 44,                        /* LB  */
  YYSYMBOL_RB = 45,                        /* RB  */
  YYSYMBOL_LT = 46,                        /* LT  */
  YYSYMBOL_GT = 47,                        /* GT  */
  YYSYMBOL_LSB = 48,                       /* LSB  */
  YYSYMBOL_RSB = 49,                       /* RSB  */
  YYSYMBOL_DIAP = 50,                      /* DIAP  */
  YYSYMBOL_QMARK = 51,                     /* QMARK  */
  YYSYMBOL_DBLEQ = 52,                     /* DBLEQ  */
  YYSYMBOL_NEQ = 53,                       /* NEQ  */
  YYSYMBOL_LEQ = 54,                       /* LEQ  */
  YYSYMBOL_EQG = 55,                       /* EQG  */
  YYSYMBOL_GEQ = 56,                       /* GEQ  */
  YYSYMBOL_AT = 57,                        /* AT  */
  YYSYMBOL_PLUS = 58,                      /* PLUS  */
  YYSYMBOL_MINUS = 59,                     /* MINUS  */
  YYSYMBOL_MUL = 60,                       /* MUL  */
  YYSYMBOL_DIV = 61,                       /* DIV  */
  YYSYMBOL_MOD = 62,                       /* MOD  */
  YYSYMBOL_TAB = 63,                       /* TAB  */
  YYSYMBOL_WS = 64,                        /* WS  */
  YYSYMBOL_SWS = 65,                       /* SWS  */
  YYSYMBOL_LN = 66,                        /* LN  */
  YYSYMBOL_BUCK = 67,                      /* BUCK  */
  YYSYMBOL_PIPE = 68,                      /* PIPE  */
  YYSYMBOL_ASSIGN = 69,                    /* ASSIGN  */
  YYSYMBOL_LCB = 70,                       /* LCB  */
  YYSYMBOL_RCB = 71,                       /* RCB  */
  YYSYMBOL_IDX = 72,                       /* IDX  */
  YYSYMBOL_DBLPIPE = 73,                   /* DBLPIPE  */
  YYSYMBOL_DBLAMP = 74,                    /* DBLAMP  */
  YYSYMBOL_IFX = 75,                       /* IFX  */
  YYSYMBOL_KW_ELSE = 76,                   /* KW_ELSE  */
  YYSYMBOL_YYACCEPT = 77,                  /* $accept  */
  YYSYMBOL_all = 78,                       /* all  */
  YYSYMBOL_program = 79,                   /* program  */
  YYSYMBOL_sub_def = 80,                   /* sub_def  */
  YYSYMBOL_opt_ext_params = 81,            /* opt_ext_params  */
  YYSYMBOL_ext_params_seq = 82,            /* ext_params_seq  */
  YYSYMBOL_code_df_param = 83,             /* code_df_param  */
  YYSYMBOL_code_df = 84,                   /* code_df  */
  YYSYMBOL_type = 85,                      /* type  */
  YYSYMBOL_block = 86,                     /* block  */
  YYSYMBOL_opt_dfdecls = 87,               /* opt_dfdecls  */
  YYSYMBOL_dfdecls = 88,                   /* dfdecls  */
  YYSYMBOL_name_seq = 89,                  /* name_seq  */
  YYSYMBOL_statement_seq = 90,             /* statement_seq  */
  YYSYMBOL_control_pragma = 91,            /* control_pragma  */
  YYSYMBOL_statement = 92,                 /* statement  */
  YYSYMBOL_cf_statement = 93,              /* cf_statement  */
  YYSYMBOL_opt_behavior = 94,              /* opt_behavior  */
  YYSYMBOL_behv_pragmas_seq = 95,          /* behv_pragmas_seq  */
  YYSYMBOL_behv_pragma = 96,               /* behv_pragma  */
  YYSYMBOL_id_seq = 97,                    /* id_seq  */
  YYSYMBOL_let_statement = 98,             /* let_statement  */
  YYSYMBOL_for_statement = 99,             /* for_statement  */
  YYSYMBOL_while_statement = 100,          /* while_statement  */
  YYSYMBOL_if_statement = 101,             /* if_statement  */
  YYSYMBOL_assign_seq = 102,               /* assign_seq  */
  YYSYMBOL_assign = 103,                   /* assign  */
  YYSYMBOL_opt_label = 104,                /* opt_label  */
  YYSYMBOL_id = 105,                       /* id  */
  YYSYMBOL_opt_exprs = 106,                /* opt_exprs  */
  YYSYMBOL_exprs_seq = 107,                /* exprs_seq  */
  YYSYMBOL_opt_setdf_rules = 108,          /* opt_setdf_rules  */
  YYSYMBOL_opt_rules = 109,                /* opt_rules  */
  YYSYMBOL_code_id = 110,                  /* code_id  */
  YYSYMBOL_expr = 111,                     /* expr  */
  YYSYMBOL_112_1 = 112,                    /* $@1  */
  YYSYMBOL_opt_params = 113,               /* opt_params  */
  YYSYMBOL_params_seq = 114,               /* params_seq  */
  YYSYMBOL_param = 115,                    /* param  */
  YYSYMBOL_where_type = 116                /* where_type  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   592

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  109
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  228

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   331


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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   154,   154,   158,   164,   170,   180,   186,   191,   197,
     202,   207,   213,   214,   218,   222,   229,   232,   238,   239,
     243,   244,   245,   246,   247,   248,   252,   257,   264,   269,
     273,   277,   281,   288,   293,   300,   307,   313,   319,   322,
     327,   331,   332,   333,   334,   337,   344,   348,   352,   357,
     366,   370,   374,   378,   382,   388,   392,   397,   401,   405,
     409,   417,   421,   428,   432,   434,   441,   442,   448,   452,
     459,   463,   471,   475,   482,   483,   489,   496,   497,   498,
     499,   500,   501,   502,   503,   503,   504,   505,   506,   507,
     508,   509,   510,   511,   512,   513,   514,   515,   516,   517,
     521,   522,   528,   532,   539,   542,   543,   544,   545,   546
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "STRING", "NAME",
  "INT", "REAL", "SCOLON", "COMMA", "COLON", "DOT", "SHARP", "ARROW",
  "LARROW", "LARR", "RARR", "AMP", "KW_CF", "KW_DF", "KW_IMPORT", "KW_AS",
  "KW_FOR", "KW_IF", "KW_LET", "KW_VALUE", "KW_CUDA", "KW_NOCPU", "KW_IN",
  "KW_OUT", "KW_SIZE", "KW_SUB", "KW_WHILE", "KW_INT", "KW_NAME",
  "KW_REAL", "KW_STRING", "KW_RUSH", "KW_STATIC", "KW_STATIC_FOR",
  "KW_UNROLLING", "KW_BLOCK", "KW_CPP", "INTERPRETER", "EQ", "LB", "RB",
  "LT", "GT", "LSB", "RSB", "DIAP", "QMARK", "DBLEQ", "NEQ", "LEQ", "EQG",
  "GEQ", "AT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "TAB", "WS", "SWS",
  "LN", "BUCK", "PIPE", "ASSIGN", "LCB", "RCB", "IDX", "DBLPIPE", "DBLAMP",
  "IFX", "KW_ELSE", "$accept", "all", "program", "sub_def",
  "opt_ext_params", "ext_params_seq", "code_df_param", "code_df", "type",
  "block", "opt_dfdecls", "dfdecls", "name_seq", "statement_seq",
  "control_pragma", "statement", "cf_statement", "opt_behavior",
  "behv_pragmas_seq", "behv_pragma", "id_seq", "let_statement",
  "for_statement", "while_statement", "if_statement", "assign_seq",
  "assign", "opt_label", "id", "opt_exprs", "exprs_seq", "opt_setdf_rules",
  "opt_rules", "code_id", "expr", "$@1", "opt_params", "params_seq",
  "param", "where_type", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-168)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-14)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      88,     7,    -6,    85,    23,    88,  -168,  -168,   -31,   319,
       7,    27,     7,  -168,  -168,   139,  -168,  -168,  -168,  -168,
     101,    57,    66,    57,   105,   103,  -168,  -168,  -168,  -168,
      98,   138,  -168,   145,   284,  -168,   500,    82,   155,   111,
    -168,  -168,   142,   301,  -168,  -168,  -168,  -168,  -168,  -168,
     114,   123,   133,   284,   131,   129,  -168,   190,     4,  -168,
     194,    -6,   284,   197,    -6,   204,  -168,  -168,  -168,  -168,
    -168,  -168,  -168,     7,   163,   181,     7,  -168,   284,   284,
     284,   292,   284,   284,  -168,   284,   284,   284,   284,   284,
     284,   284,   284,   284,   284,   284,   284,   284,   284,  -168,
     186,  -168,     9,   228,   247,   191,    71,  -168,   284,   241,
     309,  -168,   202,  -168,   244,    12,   316,   340,   364,  -168,
     393,   201,   182,   182,   177,   182,   182,   182,   182,    62,
     467,  -168,  -168,  -168,   513,   530,  -168,  -168,   213,  -168,
     284,   197,  -168,   153,  -168,    83,   257,    -7,  -168,   278,
     250,   221,  -168,   242,  -168,  -168,  -168,  -168,  -168,   284,
    -168,   284,   467,  -168,   267,  -168,   268,   266,   219,  -168,
    -168,    20,   467,   202,   265,  -168,   146,   490,   418,   236,
    -168,  -168,   210,  -168,   284,  -168,  -168,   202,   219,  -168,
     259,   284,   284,   282,   467,  -168,   285,   288,   247,   443,
      13,   185,     1,  -168,  -168,  -168,  -168,   263,   284,   189,
     102,  -168,  -168,  -168,   194,     0,  -168,   194,   284,   284,
     147,  -168,   131,    24,    74,  -168,  -168,  -168
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,    39,     0,     0,     2,     4,    76,     0,   109,
       0,     0,     0,     1,     5,     0,   105,   106,   107,   108,
       0,     0,     0,     0,     0,    25,    20,    23,    21,    22,
       0,    12,    14,    19,     0,    38,     0,    65,     0,     0,
      17,    24,     0,     0,    18,    16,    79,    66,    77,    78,
       0,     0,     0,     0,    98,     0,   101,     0,     0,   102,
       0,    39,     0,     0,    39,    29,     6,    26,    40,    41,
      42,    43,    44,     0,     0,     0,     0,    15,     0,     0,
       0,     0,     0,     0,    36,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   104,
       0,   100,     0,     0,    65,     0,    65,    61,     0,     0,
      65,    28,     0,    11,     0,     0,     0,     0,     0,    97,
       0,     0,    89,    90,     0,    93,    94,    91,    92,    83,
      84,    86,    87,    88,    96,    95,   103,    64,     0,    60,
       0,     0,    57,     0,    31,     0,     0,    65,    33,     0,
      73,     0,     8,     0,    80,    81,    82,    67,    37,     0,
      85,     0,    63,    62,     0,    30,     0,     0,    47,    34,
      69,     0,    70,     0,    75,     7,     0,    99,     0,     0,
      32,    35,     0,    27,     0,    68,    72,     0,    47,     9,
       0,     0,     0,     0,    71,    74,     0,     0,    65,     0,
      31,     0,     0,    48,    45,    10,    58,     0,     0,     0,
      55,    54,    46,    49,     0,     0,    52,     0,     0,     0,
      65,    53,    56,     0,     0,    59,    50,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -168,  -168,  -168,   291,  -168,  -168,   254,  -168,   -32,  -103,
    -168,   205,   195,  -168,     5,   -47,  -168,   126,  -168,   109,
    -168,  -168,  -168,  -168,  -168,  -168,   183,  -168,   -58,  -167,
    -168,  -168,  -168,    38,   -53,  -168,   306,  -168,   249,  -168
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     4,     5,     6,    30,    31,    32,    45,    33,    66,
     110,   111,   201,   147,    10,    67,    68,   183,   202,   203,
     209,    69,    70,    71,    72,   106,   107,    73,    54,   150,
     171,   174,   188,     8,    55,   160,    37,    58,    59,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   139,   102,   142,    57,   200,   186,   221,     9,   104,
      60,     7,   100,    15,    61,    62,    63,    47,   137,   152,
     195,   153,   208,    13,    64,   116,   117,   118,   184,   120,
     121,   226,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,    85,    86,    21,   101,
      23,    87,    88,    89,    90,   143,    91,    82,    92,    93,
      94,    95,    96,   148,   168,   185,   103,    22,    57,   108,
      85,    86,   212,    97,    98,    87,    88,    89,    90,   141,
      91,   227,    92,    93,    94,    95,    96,   162,    60,    11,
     165,   166,    61,    62,    63,   206,   172,    97,    98,    60,
     169,    36,    64,    61,    62,    63,   177,     1,   178,    34,
      38,   112,    40,    64,   115,    12,    35,   225,     2,    41,
      85,    86,    94,    95,    96,    87,    88,    89,    90,     3,
      91,   194,    92,    93,    94,    95,    96,    83,   198,   199,
      24,    65,   210,    42,    84,   218,    43,    97,    98,    44,
      82,    75,    65,   189,   190,   215,   220,   219,    78,   222,
      74,   164,    76,    25,    60,   223,   224,    79,    61,    62,
      63,    26,    27,    28,    29,    85,    86,    80,    64,    82,
      87,    88,    89,    90,   -13,    91,   159,    92,    93,    94,
      95,    96,   211,   166,    99,    82,   216,   217,    47,    85,
      86,   105,    97,    98,    87,    88,    89,    90,   113,    91,
      25,    92,    93,    94,    95,    96,   158,    65,    26,    27,
      28,    29,   109,    85,    86,   114,    97,    98,    87,    88,
      89,    90,   138,    91,   140,    92,    93,    94,    95,    96,
      92,    93,    94,    95,    96,   144,   149,    85,    86,   151,
      97,    98,    87,    88,    89,    90,   161,    91,   167,    92,
      93,    94,    95,    96,    60,   173,   175,   176,    61,    62,
      63,   179,   180,   181,    97,    98,   182,   187,    64,   192,
     193,    46,    47,    48,    49,   197,   200,    46,    47,    48,
      49,   214,   204,    85,    86,   205,    14,    77,    87,    88,
      89,    90,    24,    91,   145,    92,    93,    94,    95,    96,
      50,   213,    51,    52,   196,   146,    50,    65,    51,    52,
      97,    98,    53,   170,   163,    25,    60,   109,    53,    39,
      61,    62,    63,    26,    27,    28,    29,   119,    85,    86,
      64,     0,     0,    87,    88,    89,    90,     0,    91,   136,
      92,    93,    94,    95,    96,    16,    17,    18,    19,     0,
       0,   154,    85,    86,     0,    97,    98,    87,    88,    89,
      90,     0,    91,     0,    92,    93,    94,    95,    96,     0,
       0,     0,     0,     0,     0,   155,    85,    86,     0,    97,
      98,    87,    88,    89,    90,     0,    91,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,   156,
      85,    86,     0,    97,    98,    87,    88,    89,    90,     0,
      91,     0,    92,    93,    94,    95,    96,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    97,    98,    85,
      86,     0,   157,     0,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,     0,    85,    86,    97,    98,   191,    87,
      88,    89,    90,     0,    91,     0,    92,    93,    94,    95,
      96,     0,     0,     0,     0,     0,     0,     0,     0,    85,
      86,    97,    98,   207,    87,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,    96,     0,     0,     0,     0,
       0,     0,     0,    85,    86,     0,    97,    98,    87,    88,
      89,    90,     0,    91,    25,    92,    93,    94,    95,    96,
       0,     0,    26,    27,    28,    29,    85,    86,     0,     0,
      97,    98,    88,    89,    90,    56,    91,     0,    92,    93,
      94,    95,    96,     0,     0,     0,     0,     0,     0,    85,
      86,     0,     0,    97,    98,    88,    89,    90,     0,    91,
       0,    92,    93,    94,    95,    96,    85,    86,     0,     0,
       0,     0,    88,    89,    90,     0,    91,    98,    92,    93,
      94,    95,    96
};

static const yytype_int16 yycheck[] =
{
      53,   104,    60,   106,    36,     4,   173,     7,    14,    62,
      17,     4,     8,    44,    21,    22,    23,     4,     9,     7,
     187,     9,     9,     0,    31,    78,    79,    80,     8,    82,
      83,     7,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    46,    47,    10,    45,
      12,    51,    52,    53,    54,   108,    56,    48,    58,    59,
      60,    61,    62,   110,    71,    45,    61,    40,   100,    64,
      46,    47,    71,    73,    74,    51,    52,    53,    54,     8,
      56,     7,    58,    59,    60,    61,    62,   140,    17,     4,
       7,     8,    21,    22,    23,   198,   149,    73,    74,    17,
     147,    44,    31,    21,    22,    23,   159,    19,   161,     8,
      44,    73,     7,    31,    76,    30,    15,   220,    30,    16,
      46,    47,    60,    61,    62,    51,    52,    53,    54,    41,
      56,   184,    58,    59,    60,    61,    62,     8,   191,   192,
       1,    70,   200,    45,    15,    43,     8,    73,    74,     4,
      48,    40,    70,     7,     8,   208,   214,    55,    44,   217,
       5,     8,    20,    24,    17,   218,   219,    44,    21,    22,
      23,    32,    33,    34,    35,    46,    47,    44,    31,    48,
      51,    52,    53,    54,    45,    56,     9,    58,    59,    60,
      61,    62,     7,     8,     4,    48,     7,     8,     4,    46,
      47,     4,    73,    74,    51,    52,    53,    54,    45,    56,
      24,    58,    59,    60,    61,    62,    15,    70,    32,    33,
      34,    35,    18,    46,    47,    44,    73,    74,    51,    52,
      53,    54,     4,    56,    43,    58,    59,    60,    61,    62,
      58,    59,    60,    61,    62,     4,    44,    46,    47,     5,
      73,    74,    51,    52,    53,    54,    43,    56,     1,    58,
      59,    60,    61,    62,    17,    15,    45,    25,    21,    22,
      23,     4,     4,     7,    73,    74,    57,    12,    31,    43,
      70,     3,     4,     5,     6,    26,     4,     3,     4,     5,
       6,    28,     7,    46,    47,     7,     5,    43,    51,    52,
      53,    54,     1,    56,   109,    58,    59,    60,    61,    62,
      32,   202,    34,    35,   188,   110,    32,    70,    34,    35,
      73,    74,    44,    45,   141,    24,    17,    18,    44,    23,
      21,    22,    23,    32,    33,    34,    35,    45,    46,    47,
      31,    -1,    -1,    51,    52,    53,    54,    -1,    56,   100,
      58,    59,    60,    61,    62,    36,    37,    38,    39,    -1,
      -1,    45,    46,    47,    -1,    73,    74,    51,    52,    53,
      54,    -1,    56,    -1,    58,    59,    60,    61,    62,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,    73,
      74,    51,    52,    53,    54,    -1,    56,    -1,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    47,    -1,    73,    74,    51,    52,    53,    54,    -1,
      56,    -1,    58,    59,    60,    61,    62,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,    46,
      47,    -1,    49,    -1,    51,    52,    53,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    47,    73,    74,    50,    51,
      52,    53,    54,    -1,    56,    -1,    58,    59,    60,    61,
      62,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    73,    74,    50,    51,    52,    53,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    73,    74,    51,    52,
      53,    54,    -1,    56,    24,    58,    59,    60,    61,    62,
      -1,    -1,    32,    33,    34,    35,    46,    47,    -1,    -1,
      73,    74,    52,    53,    54,    45,    56,    -1,    58,    59,
      60,    61,    62,    -1,    -1,    -1,    -1,    -1,    -1,    46,
      47,    -1,    -1,    73,    74,    52,    53,    54,    -1,    56,
      -1,    58,    59,    60,    61,    62,    46,    47,    -1,    -1,
      -1,    -1,    52,    53,    54,    -1,    56,    74,    58,    59,
      60,    61,    62
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    19,    30,    41,    78,    79,    80,     4,   110,    14,
      91,     4,    30,     0,    80,    44,    36,    37,    38,    39,
     116,   110,    40,   110,     1,    24,    32,    33,    34,    35,
      81,    82,    83,    85,     8,    15,    44,   113,    44,   113,
       7,    16,    45,     8,     4,    84,     3,     4,     5,     6,
      32,    34,    35,    44,   105,   111,    45,    85,   114,   115,
      17,    21,    22,    23,    31,    70,    86,    92,    93,    98,
      99,   100,   101,   104,     5,    40,    20,    83,    44,    44,
      44,   111,    48,     8,    15,    46,    47,    51,    52,    53,
      54,    56,    58,    59,    60,    61,    62,    73,    74,     4,
       8,    45,   105,    91,   111,     4,   102,   103,    91,    18,
      87,    88,   110,    45,    44,   110,   111,   111,   111,    45,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   115,     9,     4,    86,
      43,     8,    86,   111,     4,    89,    88,    90,    92,    44,
     106,     5,     7,     9,    45,    45,    45,    49,    15,     9,
     112,    43,   111,   103,     8,     7,     8,     1,    71,    92,
      45,   107,   111,    15,   108,    45,    25,   111,   111,     4,
       4,     7,    57,    94,     8,    45,   106,    12,   109,     7,
       8,    50,    43,    70,   111,   106,    94,    26,   111,   111,
       4,    89,    95,    96,     7,     7,    86,    50,     9,    97,
     105,     7,    71,    96,    28,   111,     7,     8,    43,    55,
     105,     7,   105,   111,   111,    86,     7,     7
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      80,    80,    81,    81,    82,    82,    83,    83,    84,    84,
      85,    85,    85,    85,    85,    85,    86,    86,    87,    87,
      88,    89,    89,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    93,    94,    94,    95,    95,
      96,    96,    96,    96,    96,    97,    97,    98,    99,   100,
     101,   102,   102,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   110,   111,   111,   111,
     111,   111,   111,   111,   112,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   111,   111,   111,   111,   111,   111,
     113,   113,   114,   114,   115,   116,   116,   116,   116,   116
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     5,     8,     8,    10,
      12,     6,     1,     0,     1,     3,     2,     2,     1,     0,
       1,     1,     1,     1,     2,     1,     1,     5,     1,     0,
       3,     1,     3,     1,     2,     3,     5,     7,     3,     0,
       1,     1,     1,     1,     1,     7,     4,     0,     1,     2,
       5,     5,     3,     4,     2,     1,     3,     3,     8,    11,
       3,     1,     3,     3,     3,     0,     1,     4,     3,     2,
       1,     3,     2,     0,     2,     0,     1,     1,     1,     1,
       4,     4,     4,     3,     0,     4,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     5,
       3,     2,     1,     3,     2,     1,     1,     1,     1,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
        yyerror (YY_("syntax error: cannot back up")); \
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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
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
                 int yyrule)
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
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
      yychar = yylex ();
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
  case 2: /* all: program  */
#line 154 "grammar.ypp"
                { 
        ast = (yyvsp[0].program_);
    }
#line 1556 "grammar.tab.cpp"
    break;

  case 3: /* all: %empty  */
#line 158 "grammar.ypp"
    {
        ////std::cerr << "whitespace\n";
    }
#line 1564 "grammar.tab.cpp"
    break;

  case 4: /* program: sub_def  */
#line 164 "grammar.ypp"
            {
        (yyval.program_) = new program();
        (yyval.program_)->sub_defs->push_back((yyvsp[0].sub_def_));
        // //std::cerr << "program\n";
    }
#line 1574 "grammar.tab.cpp"
    break;

  case 5: /* program: program sub_def  */
#line 170 "grammar.ypp"
                      { 
        (yyval.program_) = new program();
        (yyval.program_)->sub_defs->insert((yyval.program_)->sub_defs->end(), (yyvsp[-1].program_)->sub_defs->begin(), (yyvsp[-1].program_)->sub_defs->end()); 
        (yyval.program_)->sub_defs->push_back((yyvsp[0].sub_def_));
        ////std::cerr << "program sub_def\n";
    }
#line 1585 "grammar.tab.cpp"
    break;

  case 6: /* sub_def: KW_SUB control_pragma code_id opt_params block  */
#line 180 "grammar.ypp"
                                                       {
        (yyval.sub_def_) = new luna_sub_def((yyvsp[-3].control_pragma_), (yyvsp[-2].string_), (yyvsp[-1].opt_params_), (yyvsp[0].block_));
        ////std::cerr <<  "luna_sub_def\n";
    }
#line 1594 "grammar.tab.cpp"
    break;

  case 7: /* sub_def: KW_CPP KW_SUB code_id opt_params KW_BLOCK LB INT RB  */
#line 186 "grammar.ypp"
                                                              {
        (yyval.sub_def_) = new cxx_block_with_params_def((yyvsp[-5].string_), (yyvsp[-4].opt_params_));
    }
#line 1602 "grammar.tab.cpp"
    break;

  case 8: /* sub_def: KW_IMPORT code_id LB opt_ext_params RB KW_AS code_id SCOLON  */
#line 191 "grammar.ypp"
                                                                      {
        ////std::cerr << "import\n";
        (yyval.sub_def_) = new import_def((yyvsp[-6].string_), (yyvsp[-4].opt_ext_params_), (yyvsp[-1].string_));
    }
#line 1611 "grammar.tab.cpp"
    break;

  case 9: /* sub_def: KW_IMPORT code_id LB opt_ext_params RB KW_AS code_id COLON KW_CUDA SCOLON  */
#line 197 "grammar.ypp"
                                                                                {
        (yyval.sub_def_) = new import_def_cuda((yyvsp[-8].string_), (yyvsp[-6].opt_ext_params_), (yyvsp[-3].string_));
    }
#line 1619 "grammar.tab.cpp"
    break;

  case 10: /* sub_def: KW_IMPORT code_id LB opt_ext_params RB KW_AS code_id COLON KW_CUDA COMMA KW_NOCPU SCOLON  */
#line 202 "grammar.ypp"
                                                                                                {
        (yyval.sub_def_) = new import_def_cuda_nocpu((yyvsp[-10].string_), (yyvsp[-8].opt_ext_params_), (yyvsp[-5].string_));
    }
#line 1627 "grammar.tab.cpp"
    break;

  case 11: /* sub_def: KW_CPP NAME KW_BLOCK LB INT RB  */
#line 207 "grammar.ypp"
                                         {
        (yyval.sub_def_) = new cxx_block_def((yyvsp[-4].string_));
    }
#line 1635 "grammar.tab.cpp"
    break;

  case 12: /* opt_ext_params: ext_params_seq  */
#line 213 "grammar.ypp"
                   { (yyval.opt_ext_params_) = new opt_ext_params((yyvsp[0].ext_params_seq_)); }
#line 1641 "grammar.tab.cpp"
    break;

  case 13: /* opt_ext_params: %empty  */
#line 214 "grammar.ypp"
          { (yyval.opt_ext_params_) = new opt_ext_params(nullptr); }
#line 1647 "grammar.tab.cpp"
    break;

  case 14: /* ext_params_seq: code_df_param  */
#line 218 "grammar.ypp"
                       { 
        (yyval.ext_params_seq_) = new ext_params_seq();
        (yyval.ext_params_seq_)->params_->push_back((yyvsp[0].code_df_param_));
    }
#line 1656 "grammar.tab.cpp"
    break;

  case 15: /* ext_params_seq: ext_params_seq COMMA code_df_param  */
#line 222 "grammar.ypp"
                                             {
        (yyval.ext_params_seq_)->params_->insert((yyval.ext_params_seq_)->params_->end(), (yyvsp[-2].ext_params_seq_)->params_->begin(), (yyvsp[-2].ext_params_seq_)->params_->end()); 
        (yyval.ext_params_seq_)->params_->push_back((yyvsp[0].code_df_param_));
    }
#line 1665 "grammar.tab.cpp"
    break;

  case 16: /* code_df_param: type code_df  */
#line 229 "grammar.ypp"
                 {
        (yyval.code_df_param_) = new code_df_param((yyvsp[-1].string_), (yyvsp[0].string_));
    }
#line 1673 "grammar.tab.cpp"
    break;

  case 17: /* code_df_param: error SCOLON  */
#line 232 "grammar.ypp"
                   {
	    reporter.report(ERROR_LEVEL::ERROR,line, line_num, (yylsp[-1]).first_column + 1, "int, string, value, real, name");
	}
#line 1681 "grammar.tab.cpp"
    break;

  case 18: /* code_df: NAME  */
#line 238 "grammar.ypp"
             { (yyval.string_) = (yyvsp[0].string_); }
#line 1687 "grammar.tab.cpp"
    break;

  case 19: /* code_df: %empty  */
#line 239 "grammar.ypp"
          { (yyval.string_) = nullptr; }
#line 1693 "grammar.tab.cpp"
    break;

  case 20: /* type: KW_INT  */
#line 243 "grammar.ypp"
               { (yyval.string_) = (yyvsp[0].string_); }
#line 1699 "grammar.tab.cpp"
    break;

  case 21: /* type: KW_REAL  */
#line 244 "grammar.ypp"
                  { (yyval.string_) = (yyvsp[0].string_); }
#line 1705 "grammar.tab.cpp"
    break;

  case 22: /* type: KW_STRING  */
#line 245 "grammar.ypp"
                     { (yyval.string_) = (yyvsp[0].string_); }
#line 1711 "grammar.tab.cpp"
    break;

  case 23: /* type: KW_NAME  */
#line 246 "grammar.ypp"
                  { (yyval.string_) = (yyvsp[0].string_); }
#line 1717 "grammar.tab.cpp"
    break;

  case 24: /* type: KW_VALUE AMP  */
#line 247 "grammar.ypp"
                       { (yyval.string_) = (yyvsp[-1].string_); }
#line 1723 "grammar.tab.cpp"
    break;

  case 25: /* type: KW_VALUE  */
#line 248 "grammar.ypp"
                   { (yyval.string_) = (yyvsp[0].string_); }
#line 1729 "grammar.tab.cpp"
    break;

  case 26: /* block: statement  */
#line 252 "grammar.ypp"
              { 
        // //////std::cerr << "block\n";
        (yyval.block_) = new block();
        (yyval.block_)->statement_seq_->statements_->push_back((yyvsp[0].statement_)); 
    }
#line 1739 "grammar.tab.cpp"
    break;

  case 27: /* block: LCB opt_dfdecls statement_seq RCB opt_behavior  */
#line 257 "grammar.ypp"
                                                         { 
        // ////std::cerr << "block1\n";
        (yyval.block_) = new block((yyvsp[-3].opt_dfdecls_), (yyvsp[-2].statement_seq_), (yyvsp[0].opt_behavior_)); 
    }
#line 1748 "grammar.tab.cpp"
    break;

  case 28: /* opt_dfdecls: dfdecls  */
#line 264 "grammar.ypp"
                { 
        //std::cerr << "df_decls" << std::endl;
        (yyval.opt_dfdecls_) = new opt_dfdecls((yyvsp[0].dfdecls_)); 
    }
#line 1757 "grammar.tab.cpp"
    break;

  case 29: /* opt_dfdecls: %empty  */
#line 269 "grammar.ypp"
          { (yyval.opt_dfdecls_) = new opt_dfdecls(nullptr); }
#line 1763 "grammar.tab.cpp"
    break;

  case 30: /* dfdecls: KW_DF name_seq SCOLON  */
#line 273 "grammar.ypp"
                              { (yyval.dfdecls_) = new dfdecls((yyvsp[-1].name_seq_)); }
#line 1769 "grammar.tab.cpp"
    break;

  case 31: /* name_seq: NAME  */
#line 277 "grammar.ypp"
             { 
        (yyval.name_seq_) = new name_seq();
        (yyval.name_seq_)->names_->push_back((yyvsp[0].string_)); 
    }
#line 1778 "grammar.tab.cpp"
    break;

  case 32: /* name_seq: name_seq COMMA NAME  */
#line 281 "grammar.ypp"
                              {
        (yyval.name_seq_)->names_->insert((yyval.name_seq_)->names_->end(), (yyvsp[-2].name_seq_)->names_->begin(), (yyvsp[-2].name_seq_)->names_->end()); 
        (yyval.name_seq_)->names_->push_back((yyvsp[0].string_));
    }
#line 1787 "grammar.tab.cpp"
    break;

  case 33: /* statement_seq: statement  */
#line 288 "grammar.ypp"
                   { 
        // //std::cerr << "statement_seq\n";
        (yyval.statement_seq_) = new statement_seq();
        (yyval.statement_seq_)->statements_->push_back((yyvsp[0].statement_)); 
    }
#line 1797 "grammar.tab.cpp"
    break;

  case 34: /* statement_seq: statement_seq statement  */
#line 293 "grammar.ypp"
                                  {
        (yyval.statement_seq_)->statements_->insert((yyval.statement_seq_)->statements_->end(), (yyvsp[-1].statement_seq_)->statements_->begin(), (yyvsp[-1].statement_seq_)->statements_->end()); 
        (yyval.statement_seq_)->statements_->push_back((yyvsp[0].statement_));
        // //std::cerr << "statement_seq statement\n";
    }
#line 1807 "grammar.tab.cpp"
    break;

  case 35: /* statement_seq: dfdecls error SCOLON  */
#line 300 "grammar.ypp"
                         {
	    reporter.report(ERROR_LEVEL::ERROR, line, line_num, (yylsp[-2]).first_column + 1, "stament. <Invalid usage. Try: df x, y;>");
    }
#line 1815 "grammar.tab.cpp"
    break;

  case 36: /* control_pragma: LARR where_type COMMA expr RARR  */
#line 307 "grammar.ypp"
                                    {
        vector<expr *> exprs;
        exprs.push_back((yyvsp[-1].expr_));
        (yyval.control_pragma_) = new control_pragma((yyvsp[-3].string_), &exprs);
    }
#line 1825 "grammar.tab.cpp"
    break;

  case 37: /* control_pragma: LARR where_type COMMA expr COMMA expr RARR  */
#line 313 "grammar.ypp"
                                                 {
        vector<expr *> exprs;
        exprs.push_back((yyvsp[-3].expr_));
        exprs.push_back((yyvsp[-1].expr_));
        (yyval.control_pragma_) = new control_pragma((yyvsp[-5].string_), &exprs);
    }
#line 1836 "grammar.tab.cpp"
    break;

  case 38: /* control_pragma: LARR where_type RARR  */
#line 319 "grammar.ypp"
                          {
        (yyval.control_pragma_) = new control_pragma((yyvsp[-1].string_), nullptr);
    }
#line 1844 "grammar.tab.cpp"
    break;

  case 39: /* control_pragma: %empty  */
#line 322 "grammar.ypp"
      {
        (yyval.control_pragma_) = nullptr;
    }
#line 1852 "grammar.tab.cpp"
    break;

  case 40: /* statement: cf_statement  */
#line 327 "grammar.ypp"
                 { 
        (yyval.statement_) = (yyvsp[0].cf_statement_);
        // ////std::cerr << "statement\n" ;
    }
#line 1861 "grammar.tab.cpp"
    break;

  case 41: /* statement: let_statement  */
#line 331 "grammar.ypp"
                    { (yyval.statement_) = (yyvsp[0].let_statement_); }
#line 1867 "grammar.tab.cpp"
    break;

  case 42: /* statement: for_statement  */
#line 332 "grammar.ypp"
                    { (yyval.statement_) = (yyvsp[0].for_statement_); }
#line 1873 "grammar.tab.cpp"
    break;

  case 43: /* statement: while_statement  */
#line 333 "grammar.ypp"
                      { (yyval.statement_) = (yyvsp[0].while_statement_); }
#line 1879 "grammar.tab.cpp"
    break;

  case 44: /* statement: if_statement  */
#line 334 "grammar.ypp"
                   { (yyval.statement_) = (yyvsp[0].if_statement_); }
#line 1885 "grammar.tab.cpp"
    break;

  case 45: /* cf_statement: opt_label code_id opt_exprs opt_setdf_rules opt_rules opt_behavior SCOLON  */
#line 337 "grammar.ypp"
                                                                                        {
        (yyval.cf_statement_) = new cf_statement((yyvsp[-6].opt_label_), (yyvsp[-5].string_), (yyvsp[-4].opt_exprs_), (yyvsp[-3].opt_setdf_rules_), (yyvsp[-2].opt_rules_), (yyvsp[-1].opt_behavior_));
        // ////std::cerr << "cf_statement\n"; 
    }
#line 1894 "grammar.tab.cpp"
    break;

  case 46: /* opt_behavior: AT LCB behv_pragmas_seq RCB  */
#line 344 "grammar.ypp"
                                    {
        (yyval.opt_behavior_) = new opt_behavior((yyvsp[-1].behv_pragmas_seq_));
        // ////std::cerr << "opt_behavior\n";
    }
#line 1903 "grammar.tab.cpp"
    break;

  case 47: /* opt_behavior: %empty  */
#line 348 "grammar.ypp"
          { (yyval.opt_behavior_) = new opt_behavior(); }
#line 1909 "grammar.tab.cpp"
    break;

  case 48: /* behv_pragmas_seq: behv_pragma  */
#line 352 "grammar.ypp"
                    { 
        (yyval.behv_pragmas_seq_) = new behv_pragmas_seq();
        (yyval.behv_pragmas_seq_)->behv_pragma_->push_back((yyvsp[0].behv_pragma_)); 
        ////std::cerr << "behv_pragma\n" ;
    }
#line 1919 "grammar.tab.cpp"
    break;

  case 49: /* behv_pragmas_seq: behv_pragmas_seq behv_pragma  */
#line 357 "grammar.ypp"
                                       {
        (yyval.behv_pragmas_seq_) = new behv_pragmas_seq();
        (yyval.behv_pragmas_seq_)->behv_pragma_->insert((yyval.behv_pragmas_seq_)->behv_pragma_->end(), (yyvsp[-1].behv_pragmas_seq_)->behv_pragma_->begin(), (yyvsp[-1].behv_pragmas_seq_)->behv_pragma_->end()); 
        (yyval.behv_pragmas_seq_)->behv_pragma_->push_back((yyvsp[0].behv_pragma_));
	    ////std::cerr << "behv_pragmas_seq behv_pragma\n"; 
    }
#line 1930 "grammar.tab.cpp"
    break;

  case 50: /* behv_pragma: NAME id EQ expr SCOLON  */
#line 366 "grammar.ypp"
                               {
        (yyval.behv_pragma_) = new behv_pragma_eq((yyvsp[-4].string_), (yyvsp[-3].id_), (yyvsp[-1].expr_));
    }
#line 1938 "grammar.tab.cpp"
    break;

  case 51: /* behv_pragma: NAME id EQG expr SCOLON  */
#line 370 "grammar.ypp"
                                  {
        (yyval.behv_pragma_) = new behv_pragma_eqg((yyvsp[-4].string_), (yyvsp[-3].id_), (yyvsp[-1].expr_));
    }
#line 1946 "grammar.tab.cpp"
    break;

  case 52: /* behv_pragma: NAME id_seq SCOLON  */
#line 374 "grammar.ypp"
                             {
        (yyval.behv_pragma_) = new behv_pragma_id_seq((yyvsp[-2].string_), (yyvsp[-1].id_seq_));
    }
#line 1954 "grammar.tab.cpp"
    break;

  case 53: /* behv_pragma: NAME COLON expr SCOLON  */
#line 378 "grammar.ypp"
                                 {
        (yyval.behv_pragma_) = new behv_pragma_expr((yyvsp[-3].string_), (yyvsp[-1].expr_));
    }
#line 1962 "grammar.tab.cpp"
    break;

  case 54: /* behv_pragma: name_seq SCOLON  */
#line 382 "grammar.ypp"
                          {
        (yyval.behv_pragma_) = new behv_pragma_seq((yyvsp[-1].name_seq_));
    }
#line 1970 "grammar.tab.cpp"
    break;

  case 55: /* id_seq: id  */
#line 388 "grammar.ypp"
           { 
        (yyval.id_seq_) = new id_seq();
        (yyval.id_seq_)->seq_->push_back((yyvsp[0].id_)); 
    }
#line 1979 "grammar.tab.cpp"
    break;

  case 56: /* id_seq: id_seq COMMA id  */
#line 392 "grammar.ypp"
                          {
        (yyval.id_seq_)->seq_->insert((yyval.id_seq_)->seq_->end(), (yyvsp[-2].id_seq_)->seq_->begin(), (yyvsp[-2].id_seq_)->seq_->end()); 
        (yyval.id_seq_)->seq_->push_back((yyvsp[0].id_));
    }
#line 1988 "grammar.tab.cpp"
    break;

  case 57: /* let_statement: KW_LET assign_seq block  */
#line 397 "grammar.ypp"
                                       {
    (yyval.let_statement_) = new let_statement((yyvsp[-1].assign_seq_), (yyvsp[0].block_));
}
#line 1996 "grammar.tab.cpp"
    break;

  case 58: /* for_statement: KW_FOR control_pragma NAME EQ expr DIAP expr block  */
#line 401 "grammar.ypp"
                                                                  {
    (yyval.for_statement_) = new for_statement((yyvsp[-6].control_pragma_), (yyvsp[-5].string_), (yyvsp[-3].expr_), (yyvsp[-1].expr_), (yyvsp[0].block_));
}
#line 2004 "grammar.tab.cpp"
    break;

  case 59: /* while_statement: KW_WHILE control_pragma expr COMMA NAME EQ expr DIAP KW_OUT id block  */
#line 405 "grammar.ypp"
                                                                                      {
    (yyval.while_statement_) = new while_statement((yyvsp[-9].control_pragma_), (yyvsp[-8].expr_), (yyvsp[-6].string_), (yyvsp[-4].expr_), (yyvsp[-1].id_), (yyvsp[0].block_));
}
#line 2012 "grammar.tab.cpp"
    break;

  case 60: /* if_statement: KW_IF expr block  */
#line 409 "grammar.ypp"
                                         {
    (yyval.if_statement_) = new if_statement((yyvsp[-1].expr_), (yyvsp[0].block_));
}
#line 2020 "grammar.tab.cpp"
    break;

  case 61: /* assign_seq: assign  */
#line 417 "grammar.ypp"
               { 
        (yyval.assign_seq_) = new assign_seq();
        (yyval.assign_seq_)->assign_seq_->push_back((yyvsp[0].assign_));
    }
#line 2029 "grammar.tab.cpp"
    break;

  case 62: /* assign_seq: assign_seq COMMA assign  */
#line 421 "grammar.ypp"
                                   {
        (yyval.assign_seq_)->assign_seq_->insert((yyval.assign_seq_)->assign_seq_->end(), (yyvsp[-2].assign_seq_)->assign_seq_->begin(), (yyvsp[-2].assign_seq_)->assign_seq_->end()); 
        (yyval.assign_seq_)->assign_seq_->push_back((yyvsp[0].assign_));
    }
#line 2038 "grammar.tab.cpp"
    break;

  case 63: /* assign: NAME EQ expr  */
#line 428 "grammar.ypp"
                     { (yyval.assign_) = new assign((yyvsp[-2].string_), (yyvsp[0].expr_)); }
#line 2044 "grammar.tab.cpp"
    break;

  case 64: /* opt_label: KW_CF id COLON  */
#line 432 "grammar.ypp"
                       { (yyval.opt_label_) = new opt_label((yyvsp[-1].id_)); }
#line 2050 "grammar.tab.cpp"
    break;

  case 65: /* opt_label: %empty  */
#line 434 "grammar.ypp"
    {
        ////std::cerr << "opt label is nullptr" << std::endl;
        (yyval.opt_label_) = new opt_label(nullptr);
	}
#line 2059 "grammar.tab.cpp"
    break;

  case 66: /* id: NAME  */
#line 441 "grammar.ypp"
             { (yyval.id_) = new simple_id((yyvsp[0].string_)); }
#line 2065 "grammar.tab.cpp"
    break;

  case 67: /* id: id LSB expr RSB  */
#line 442 "grammar.ypp"
                          {
        (yyval.id_) = new complex_id((yyvsp[-3].id_), (yyvsp[-1].expr_));
    }
#line 2073 "grammar.tab.cpp"
    break;

  case 68: /* opt_exprs: LB exprs_seq RB  */
#line 448 "grammar.ypp"
                        { 
        ////std::cerr << "opt_exprs" << std::endl;
        (yyval.opt_exprs_) = new opt_exprs((yyvsp[-1].exprs_seq_)); 
    }
#line 2082 "grammar.tab.cpp"
    break;

  case 69: /* opt_exprs: LB RB  */
#line 452 "grammar.ypp"
                { 
        ////std::cerr << "exprs_seq is nullptr" << std::endl;
        (yyval.opt_exprs_) = new opt_exprs(nullptr); 
        }
#line 2091 "grammar.tab.cpp"
    break;

  case 70: /* exprs_seq: expr  */
#line 459 "grammar.ypp"
             { 
        (yyval.exprs_seq_) = new exprs_seq();
        (yyval.exprs_seq_)->expr_->push_back((yyvsp[0].expr_)); 
    }
#line 2100 "grammar.tab.cpp"
    break;

  case 71: /* exprs_seq: exprs_seq COMMA expr  */
#line 463 "grammar.ypp"
                               {
        ////std::cerr << "expr seq" << std::endl;
        (yyval.exprs_seq_)->expr_->insert((yyval.exprs_seq_)->expr_->end(), (yyvsp[-2].exprs_seq_)->expr_->begin(), (yyvsp[-2].exprs_seq_)->expr_->end()); 
        (yyval.exprs_seq_)->expr_->push_back((yyvsp[0].expr_));
    }
#line 2110 "grammar.tab.cpp"
    break;

  case 72: /* opt_setdf_rules: RARR opt_exprs  */
#line 471 "grammar.ypp"
                       { 
        (yyval.opt_setdf_rules_) = new opt_setdf_rules((yyvsp[0].opt_exprs_)); 
        ////std::cerr << "opt_setdf_rules" << std::endl;
        }
#line 2119 "grammar.tab.cpp"
    break;

  case 73: /* opt_setdf_rules: %empty  */
#line 475 "grammar.ypp"
      {
        (yyval.opt_setdf_rules_) = new opt_setdf_rules(nullptr); 
    }
#line 2127 "grammar.tab.cpp"
    break;

  case 74: /* opt_rules: ARROW opt_exprs  */
#line 482 "grammar.ypp"
                    { (yyval.opt_rules_) = new opt_rules((yyvsp[0].opt_exprs_)); }
#line 2133 "grammar.tab.cpp"
    break;

  case 75: /* opt_rules: %empty  */
#line 483 "grammar.ypp"
      {
        (yyval.opt_rules_) = new opt_rules(nullptr);
    }
#line 2141 "grammar.tab.cpp"
    break;

  case 76: /* code_id: NAME  */
#line 489 "grammar.ypp"
             {  
        (yyval.string_) = (yyvsp[0].string_);
        ////std::cerr << "code id : " << *($1->value_) << std::endl;
    }
#line 2150 "grammar.tab.cpp"
    break;

  case 77: /* expr: INT  */
#line 496 "grammar.ypp"
            { (yyval.expr_) = (yyvsp[0].int_); }
#line 2156 "grammar.tab.cpp"
    break;

  case 78: /* expr: REAL  */
#line 497 "grammar.ypp"
               { (yyval.expr_) = (yyvsp[0].double_); }
#line 2162 "grammar.tab.cpp"
    break;

  case 79: /* expr: STRING  */
#line 498 "grammar.ypp"
                 { (yyval.expr_) = (yyvsp[0].string_); }
#line 2168 "grammar.tab.cpp"
    break;

  case 80: /* expr: KW_INT LB expr RB  */
#line 499 "grammar.ypp"
                            {}
#line 2174 "grammar.tab.cpp"
    break;

  case 81: /* expr: KW_REAL LB expr RB  */
#line 500 "grammar.ypp"
                              {}
#line 2180 "grammar.tab.cpp"
    break;

  case 82: /* expr: KW_STRING LB expr RB  */
#line 501 "grammar.ypp"
                               {}
#line 2186 "grammar.tab.cpp"
    break;

  case 83: /* expr: expr PLUS expr  */
#line 502 "grammar.ypp"
                         { (yyval.expr_) = new sum((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2192 "grammar.tab.cpp"
    break;

  case 84: /* $@1: %empty  */
#line 503 "grammar.ypp"
                          {}
#line 2198 "grammar.tab.cpp"
    break;

  case 85: /* expr: expr MINUS expr $@1  */
#line 503 "grammar.ypp"
                             { (yyval.expr_) = new sub((yyvsp[-3].expr_), (yyvsp[-1].expr_)); }
#line 2204 "grammar.tab.cpp"
    break;

  case 86: /* expr: expr MUL expr  */
#line 504 "grammar.ypp"
                        { (yyval.expr_) = new mul((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2210 "grammar.tab.cpp"
    break;

  case 87: /* expr: expr DIV expr  */
#line 505 "grammar.ypp"
                        { (yyval.expr_) = new div1((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2216 "grammar.tab.cpp"
    break;

  case 88: /* expr: expr MOD expr  */
#line 506 "grammar.ypp"
                        { (yyval.expr_) = new mod((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2222 "grammar.tab.cpp"
    break;

  case 89: /* expr: expr LT expr  */
#line 507 "grammar.ypp"
                       { (yyval.expr_) = new lt((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2228 "grammar.tab.cpp"
    break;

  case 90: /* expr: expr GT expr  */
#line 508 "grammar.ypp"
                       { (yyval.expr_) = new gt((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2234 "grammar.tab.cpp"
    break;

  case 91: /* expr: expr LEQ expr  */
#line 509 "grammar.ypp"
                        { (yyval.expr_) = new leq((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2240 "grammar.tab.cpp"
    break;

  case 92: /* expr: expr GEQ expr  */
#line 510 "grammar.ypp"
                        { (yyval.expr_) = new geq((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2246 "grammar.tab.cpp"
    break;

  case 93: /* expr: expr DBLEQ expr  */
#line 511 "grammar.ypp"
                         { (yyval.expr_) = new dbleq((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2252 "grammar.tab.cpp"
    break;

  case 94: /* expr: expr NEQ expr  */
#line 512 "grammar.ypp"
                        { (yyval.expr_) = new neq((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2258 "grammar.tab.cpp"
    break;

  case 95: /* expr: expr DBLAMP expr  */
#line 513 "grammar.ypp"
                            { (yyval.expr_) = new dblamp((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2264 "grammar.tab.cpp"
    break;

  case 96: /* expr: expr DBLPIPE expr  */
#line 514 "grammar.ypp"
                            { (yyval.expr_) = new dblpipe((yyvsp[-2].expr_), (yyvsp[0].expr_)); }
#line 2270 "grammar.tab.cpp"
    break;

  case 97: /* expr: LB expr RB  */
#line 515 "grammar.ypp"
                     { (yyval.expr_) = (yyvsp[-1].expr_); }
#line 2276 "grammar.tab.cpp"
    break;

  case 98: /* expr: id  */
#line 516 "grammar.ypp"
             {}
#line 2282 "grammar.tab.cpp"
    break;

  case 99: /* expr: expr QMARK expr COLON expr  */
#line 517 "grammar.ypp"
                                     {}
#line 2288 "grammar.tab.cpp"
    break;

  case 100: /* opt_params: LB params_seq RB  */
#line 521 "grammar.ypp"
                         { (yyval.opt_params_) = new opt_params((yyvsp[-1].param_seq_)); }
#line 2294 "grammar.tab.cpp"
    break;

  case 101: /* opt_params: LB RB  */
#line 522 "grammar.ypp"
                { (yyval.opt_params_) = new opt_params(nullptr); 
                ////std::cerr << "opt params\n";
            }
#line 2302 "grammar.tab.cpp"
    break;

  case 102: /* params_seq: param  */
#line 528 "grammar.ypp"
               { 
        (yyval.param_seq_) = new param_seq();
        (yyval.param_seq_)->params_->push_back((yyvsp[0].param_)); 
    }
#line 2311 "grammar.tab.cpp"
    break;

  case 103: /* params_seq: params_seq COMMA param  */
#line 532 "grammar.ypp"
                                 {
        (yyval.param_seq_)->params_->insert((yyval.param_seq_)->params_->end(), (yyvsp[-2].param_seq_)->params_->begin(), (yyvsp[-2].param_seq_)->params_->end()); 
        (yyval.param_seq_)->params_->push_back((yyvsp[0].param_));
    }
#line 2320 "grammar.tab.cpp"
    break;

  case 104: /* param: type NAME  */
#line 539 "grammar.ypp"
                  {(yyval.param_) = new param((yyvsp[-1].string_), (yyvsp[0].string_)); }
#line 2326 "grammar.tab.cpp"
    break;

  case 105: /* where_type: KW_RUSH  */
#line 542 "grammar.ypp"
                    { (yyval.string_) = (yyvsp[0].string_); }
#line 2332 "grammar.tab.cpp"
    break;

  case 106: /* where_type: KW_STATIC  */
#line 543 "grammar.ypp"
                        { (yyval.string_) = (yyvsp[0].string_); }
#line 2338 "grammar.tab.cpp"
    break;

  case 107: /* where_type: KW_STATIC_FOR  */
#line 544 "grammar.ypp"
                            { (yyval.string_) = (yyvsp[0].string_); }
#line 2344 "grammar.tab.cpp"
    break;

  case 108: /* where_type: KW_UNROLLING  */
#line 545 "grammar.ypp"
                          { (yyval.string_) = (yyvsp[0].string_); }
#line 2350 "grammar.tab.cpp"
    break;

  case 109: /* where_type: %empty  */
#line 546 "grammar.ypp"
          { (yyval.string_) = new luna_string(nullptr); }
#line 2356 "grammar.tab.cpp"
    break;


#line 2360 "grammar.tab.cpp"

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
      yyerror (YY_("syntax error"));
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
                      yytoken, &yylval, &yylloc);
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
  ++yynerrs;

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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 548 "grammar.ypp"

