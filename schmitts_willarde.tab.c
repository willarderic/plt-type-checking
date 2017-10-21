/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 15 "schmitts_willarde.y" /* yacc.c:339  */

#include <stdio.h>
#include <stack>
#include <cstring>
#include <sstream>
#include "SymbolTable.h"

int numLines = 1;
int exprListIndex = 0;
bool exprListInt = false;
std::stack<SymbolTable> scopeStack;

void printRule(const char *, const char *);
int yyerror(const char *s);
char* setText(string s);
void printTokenInfo(const char* tokenType, const char* lexeme);
void beginScope();
void endScope();
bool findEntryInAnyScope(const string entry);

extern "C"
{
    int yyparse(void);
    int yylex(void);
    int yywrap() { return 1; }
}


#line 95 "schmitts_willarde.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_LETSTAR = 258,
    T_LAMBDA = 259,
    T_INPUT = 260,
    T_PRINT = 261,
    T_IF = 262,
    T_LPAREN = 263,
    T_RPAREN = 264,
    T_ADD = 265,
    T_MULT = 266,
    T_DIV = 267,
    T_SUB = 268,
    T_AND = 269,
    T_OR = 270,
    T_NOT = 271,
    T_LT = 272,
    T_GT = 273,
    T_LE = 274,
    T_GE = 275,
    T_EQ = 276,
    T_NE = 277,
    T_IDENT = 278,
    T_INTCONST = 279,
    T_STRCONST = 280,
    T_T = 281,
    T_NIL = 282,
    T_UNKNOWN = 283
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 44 "schmitts_willarde.y" /* yacc.c:355  */

    char op;
	char* text;
    TypeInfo typeInfo;

#line 167 "schmitts_willarde.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);



/* Copy the second part of user declarations.  */

#line 184 "schmitts_willarde.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  42
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   85

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  29
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  19
/* YYNRULES -- Number of rules.  */
#define YYNRULES  45
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  65

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
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
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    67,    67,    73,    80,    90,    97,   104,   111,   118,
     125,   132,   139,   146,   153,   160,   167,   174,   185,   270,
     288,   301,   304,   316,   329,   332,   344,   355,   362,   391,
     406,   411,   416,   421,   426,   431,   436,   441,   446,   451,
     456,   461,   466,   471,   476,   481
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_LETSTAR", "T_LAMBDA", "T_INPUT",
  "T_PRINT", "T_IF", "T_LPAREN", "T_RPAREN", "T_ADD", "T_MULT", "T_DIV",
  "T_SUB", "T_AND", "T_OR", "T_NOT", "T_LT", "T_GT", "T_LE", "T_GE",
  "T_EQ", "T_NE", "T_IDENT", "T_INTCONST", "T_STRCONST", "T_T", "T_NIL",
  "T_UNKNOWN", "$accept", "N_START", "N_EXPR", "N_CONST",
  "N_PARENTHESIZED_EXPR", "N_ARITHLOGIC_EXPR", "N_IF_EXPR", "N_LET_EXPR",
  "N_ID_EXPR_LIST", "N_LAMBDA_EXPR", "N_ID_LIST", "N_PRINT_EXPR",
  "N_INPUT_EXPR", "N_EXPR_LIST", "N_BIN_OP", "N_ARITH_OP", "N_LOG_OP",
  "N_REL_OP", "N_UN_OP", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283
};
# endif

#define YYPACT_NINF -19

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-19)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      -7,    58,   -19,   -19,   -19,   -19,   -19,     4,   -19,   -19,
      -3,     1,   -19,    -7,    -7,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,   -19,    -7,    -1,
     -19,   -19,   -19,   -19,   -19,   -19,   -19,    -7,   -19,   -19,
     -19,    -7,   -19,   -19,   -19,   -19,    -7,   -19,   -19,    -7,
     -19,    -6,    -2,    -7,   -19,   -17,    -7,    -7,   -19,   -19,
      -7,   -19,   -19,     2,   -19
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     4,     6,     7,     8,     9,     0,     2,     3,
       0,     0,    27,     0,     0,    36,    33,    35,    34,    37,
      38,    45,    39,    40,    41,    42,    43,    44,    29,     0,
      10,    11,    12,    13,    14,    15,    16,     0,    30,    31,
      32,     0,     1,    21,    24,    26,     0,    28,     5,     0,
      17,     0,     0,     0,    18,     0,     0,     0,    25,    19,
       0,    20,    23,     0,    22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -19,   -19,     0,   -19,   -19,   -19,   -19,   -19,   -19,   -19,
     -19,   -19,   -19,   -18,   -19,   -19,   -19,   -19,   -19
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     7,    28,     9,    29,    30,    31,    32,    51,    33,
      52,    34,    35,    36,    37,    38,    39,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       8,     1,    55,    56,    42,    43,    60,    57,    48,    44,
      47,    64,     0,    45,    46,     0,     2,     3,     4,     5,
       6,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,     0,     0,
       0,    50,     0,     0,     0,     0,    53,     0,     0,    54,
       0,     0,     0,    59,     0,     0,    61,    62,     0,     0,
      63,    10,    11,    12,    13,    14,     1,     0,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,     2,     3,     4,     5,     6
};

static const yytype_int8 yycheck[] =
{
       0,     8,     8,     9,     0,     8,    23,     9,     9,     8,
      28,     9,    -1,    13,    14,    -1,    23,    24,    25,    26,
      27,    23,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      -1,    -1,    -1,    53,    -1,    -1,    56,    57,    -1,    -1,
      60,     3,     4,     5,     6,     7,     8,    -1,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     8,    23,    24,    25,    26,    27,    30,    31,    32,
       3,     4,     5,     6,     7,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    31,    33,
      34,    35,    36,    38,    40,    41,    42,    43,    44,    45,
      46,    47,     0,     8,     8,    31,    31,    42,     9,    31,
      31,    37,    39,    31,    31,     8,     9,     9,    23,    31,
      23,    31,    31,    31,     9
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    29,    30,    31,    31,    31,    32,    32,    32,    32,
      33,    33,    33,    33,    33,    33,    33,    34,    34,    35,
      36,    37,    37,    38,    39,    39,    40,    41,    42,    42,
      43,    43,    43,    44,    44,    44,    44,    45,    45,    46,
      46,    46,    46,    46,    46,    47
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     3,     4,
       5,     0,     5,     5,     0,     2,     2,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
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
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 68 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("START", "EXPR");
                                printf("\n---- Completed parsing ----\n\n");
                                return 0;
                            }
#line 1313 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("EXPR", "CONST");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1324 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 81 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("EXPR", "IDENT");
								bool found = findEntryInAnyScope(string((yyvsp[0].text)));
								if (!found) {
									yyerror("Undefined identifier");
                                    return 1;
								}
                                (yyval.typeInfo) = scopeStack.top().getEntryType(string((yyvsp[0].text)));
                            }
#line 1338 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 91 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("EXPR", "( PARENTHESIZED_EXPR )");
                                (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[-1].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[-1].typeInfo).returnType;
                            }
#line 1349 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 98 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "INTCONST");
                                (yyval.typeInfo).type = INT;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1360 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 105 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "STRCONST");
                                (yyval.typeInfo).type = STR;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1371 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 112 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "t");
                                (yyval.typeInfo).type = BOOL;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1382 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 119 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("CONST", "nil");
                                (yyval.typeInfo).type = BOOL;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1393 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 126 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "ARITHLOGIC_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1404 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 133 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "IF_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1415 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 140 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "LET_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1426 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 147 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "LAMBDA_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1437 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 154 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "PRINT_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1448 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 161 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "INPUT_EXPR");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1459 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 168 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PARENTHESIZED_EXPR", "EXPR_LIST");
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1470 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 175 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ARITHLOGIC_EXPR", "UN_OP EXPR");
                                if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                (yyval.typeInfo).type = BOOL;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1485 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 186 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                // add text attribute to N_BIN_OP
                                printRule("ARITHLOGIC_EXPR", "BIN_OP EXPR EXPR");
                                if (strcmp((yyvsp[-2].text), "*") == 0 || strcmp((yyvsp[-2].text), "/") == 0 ||
                                    strcmp((yyvsp[-2].text), "+") == 0 || strcmp((yyvsp[-2].text), "-") == 0)
                                {
									int intReducedTypeArg1 = INT & (yyvsp[-1].typeInfo).type;
									int intReducedTypeArg2 = INT & (yyvsp[0].typeInfo).type;
                                    if (intReducedTypeArg1 != INT) {
                                        yyerror("Arg 1 must be integer");
                                        return 1;
                                    } else if (intReducedTypeArg2 != INT) {
                                        yyerror("Arg 2 must be integer");
                                        return 1;
                                    }
                                    (yyval.typeInfo).type = INT;
                                    (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                    (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                } else if (strcmp((yyvsp[-2].text), "and") == 0 || strcmp((yyvsp[-2].text), "or") == 0) {
                                    if ((yyvsp[-1].typeInfo).type == FUNCTION) {
                                        yyerror("Arg 1 cannot be function");
                                        return 1;
                                    }
									int intReducedType = INT & (yyvsp[-1].typeInfo).type;
									int strReducedType = STR & (yyvsp[-1].typeInfo).type;
									int boolReducedType = BOOL & (yyvsp[-1].typeInfo).type;
                                    if (intReducedType == INT) {
                                        if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        (yyval.typeInfo).type = BOOL;
                                        (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                        (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                    } else if (strReducedType == STR) {
                                        if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        (yyval.typeInfo).type = BOOL;
                                        (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                        (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                    } else if (boolReducedType == BOOL) {
                                        if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                            yyerror("Arg 2 cannot be function");
                                            return 1;
                                        }
                                        (yyval.typeInfo).type = BOOL;
                                        (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                        (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                    }
                                } else if (strcmp((yyvsp[-2].text), "<") || strcmp((yyvsp[-2].text), ">") ||
                                           strcmp((yyvsp[-2].text), ">=") || strcmp((yyvsp[-2].text), "<=") ||
                                           strcmp((yyvsp[-2].text), "=") || strcmp((yyvsp[-2].text), "/=")) {
                                    if ((yyvsp[-1].typeInfo).type == FUNCTION) {
                                        yyerror("Arg 1 must be integer or string");
                                        return 1;
                                    } else if ((yyvsp[-1].typeInfo).type == BOOL) {
                                        yyerror("Arg 1 must be integer or string");
                                        return 1;
                                    }
									int intReducedTypeArg1 = INT & (yyvsp[-1].typeInfo).type;
									int strReducedTypeArg1 = STR & (yyvsp[-1].typeInfo).type;
                                    if (intReducedTypeArg1 == INT) {
										int intReducedTypeArg2 = INT & (yyvsp[0].typeInfo).type;
                                        if (intReducedTypeArg2 != INT) {
                                            yyerror("Arg 2 must be integer or string");
                                            return 1;
                                        }
                                        (yyval.typeInfo).type = BOOL;
                                        (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                        (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                    } else if (strReducedTypeArg1 == STR) {
										int strReducedTypeArg2 = STR & (yyvsp[0].typeInfo).type;
                                        if (strReducedTypeArg2 != STR) {
                                            yyerror("Arg 2 must be integer or string");
                                            return 1;
                                        }
                                        (yyval.typeInfo).type = BOOL;
                                        (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                        (yyval.typeInfo).returnType = NOT_APPLICABLE;
                                    }
                                }
                            }
#line 1574 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 271 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("IF_EXPR", "IF EXPR EXPR EXPR");

                                if ((yyvsp[-2].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                } else if ((yyvsp[-1].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return(1);
                                } else if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 3 cannot be function");
                                    return 1;
                                }
                                (yyval.typeInfo).type = (yyvsp[-1].typeInfo).type | (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1596 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 289 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("LET_EXPR", "let* ( ID_EXPR_LIST ) EXPR");
								endScope();
                                if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return 1;
                                }
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1612 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 301 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ID_EXPR_LIST", "epsilon");
                            }
#line 1620 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 305 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ID_EXPR_LIST", "ID_EXPR_LIST ( IDENT EXPR )");
								bool found = scopeStack.top().findEntry(string((yyvsp[-2].text)));
								printf("___Adding %s to symbol table\n", (yyvsp[-2].text));
								if (found) {
									yyerror("Multiply defined identifier");
                                    return 1;
								} else {
									scopeStack.top().addEntry(SymbolTableEntry(string((yyvsp[-2].text)), (yyvsp[-1].typeInfo)));
								}
                            }
#line 1636 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 317 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("LAMBDA_EXPR", "lambda ( ID_LIST ) EXPR");
                                (yyval.typeInfo).numParams = scopeStack.top().getNumParams();
                                endScope();
                                if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 2 cannot be function");
                                    return 1;
                                }
                                (yyval.typeInfo).type = FUNCTION;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).type;
                            }
#line 1652 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 329 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ID_LIST", "epsilon");
                            }
#line 1660 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 333 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ID_LIST", "ID_LIST IDENT");
								bool found = scopeStack.top().findEntry(string((yyvsp[0].text)));
                                printf("___Adding %s to symbol table\n", (yyvsp[0].text));
								if (found) {
									yyerror("Multiply defined identifier");
                                    return 1;
								} else {
									scopeStack.top().addEntry(SymbolTableEntry(string((yyvsp[0].text)), INT));
								}
                            }
#line 1676 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 345 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("PRINT_EXPR", "print EXPR");
                                if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    yyerror("Arg 1 cannot be function");
                                    return(1);
                                }
                                (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams;
                                (yyval.typeInfo).returnType = (yyvsp[0].typeInfo).returnType;
                            }
#line 1691 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 356 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("INPUT_EXPR", "input");
                                (yyval.typeInfo).type = INT_OR_STR;
                                (yyval.typeInfo).numParams = NOT_APPLICABLE;
                                (yyval.typeInfo).returnType = NOT_APPLICABLE;
                            }
#line 1702 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 363 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("EXPR_LIST", "EXPR EXPR_LIST");
                                if ((yyvsp[-1].typeInfo).type == FUNCTION) {
                                    if (exprListInt == false) {
                                        std::string s;
                                        std::stringstream out;
                                        out << "Arg " << ((yyvsp[-1].typeInfo).numParams - exprListIndex) << " must be integer";
                                        s = out.str();
                                        yyerror(s.c_str());
                                        return 1;
                                    }
                                    if ((yyvsp[-1].typeInfo).numParams > (yyvsp[0].typeInfo).numParams) {
                                        yyerror("Too few parameters in function call");
                                        return 1;
                                    } else if ((yyvsp[-1].typeInfo).numParams < (yyvsp[0].typeInfo).numParams) {
                                        yyerror("Too many parameters in function call");
                                        return 1;
                                    } else {
                                        (yyval.typeInfo).type == (yyvsp[-1].typeInfo).returnType;
                                    }
                                } else if ((yyvsp[-1].typeInfo).type == INT) {
                                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams + 1;
                                } else if ((yyvsp[-1].typeInfo).type != INT) {
                                    (yyval.typeInfo).numParams = (yyvsp[0].typeInfo).numParams + 1;
                                    exprListInt = false;
                                    exprListIndex = (yyval.typeInfo).numParams;
                                }
                            }
#line 1735 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 392 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("EXPR_LIST", "EXPR");
                                int intReducedType = INT & (yyvsp[0].typeInfo).type;
                                if ((yyvsp[0].typeInfo).type == FUNCTION) {
                                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).returnType;
                                } else if (intReducedType == INT) {
                                    (yyval.typeInfo).type = (yyvsp[0].typeInfo).type;
                                    exprListInt = true;
                                } else  {
                                    exprListInt = false;
                                    exprListIndex = 1;
                                }
                                (yyval.typeInfo).numParams = 1;
                            }
#line 1754 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 407 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "ARITH_OP");
                                (yyval.text) = (yyvsp[0].text);
                            }
#line 1763 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 412 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "LOG_OP");
                                (yyval.text) = (yyvsp[0].text);
                            }
#line 1772 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("BIN_OP", "REL_OP");
                                (yyval.text) = (yyvsp[0].text);
                            }
#line 1781 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 422 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "*");
                                (yyval.text) = setText("*");
                            }
#line 1790 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 427 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "-");
                                (yyval.text) = setText("-");
                            }
#line 1799 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "/");
                                (yyval.text) = setText("/");
                            }
#line 1808 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 437 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("ARITH_OP", "+");
                                (yyval.text) = setText("+");
                            }
#line 1817 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 442 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("LOG_OP", "and");
                                (yyval.text) = setText("and");
                            }
#line 1826 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 447 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("LOG_OP", "or");
                                (yyval.text) = setText("or");
                            }
#line 1835 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 452 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "<");
                                (yyval.text) = setText("<");
                            }
#line 1844 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 457 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", ">");
                                (yyval.text) = setText(">");
                            }
#line 1853 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 462 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "<=");
                                (yyval.text) = setText("<=");
                            }
#line 1862 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 467 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", ">=");
                                (yyval.text) = setText(">=");
                            }
#line 1871 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 472 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "=");
                                (yyval.text) = setText("=");
                            }
#line 1880 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 477 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("REL_OP", "/=");
                                (yyval.text) = setText("/=");
                            }
#line 1889 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 482 "schmitts_willarde.y" /* yacc.c:1646  */
    {
                                printRule("UN_OP", "not");
                            }
#line 1897 "schmitts_willarde.tab.c" /* yacc.c:1646  */
    break;


#line 1901 "schmitts_willarde.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 485 "schmitts_willarde.y" /* yacc.c:1906  */


#include "lex.yy.c"
extern FILE *yyin;

void printRule(const char *lhs, const char *rhs)
{
  printf("%s -> %s\n", lhs, rhs);
  return;
}

int yyerror(const char *s)
{
  printf("Line %d: %s\n", numLines, s);
  return(1);
}

void printTokenInfo(const char* tokenType, const char* lexeme)
{
  printf("TOKEN: %s  LEXEME: %s\n", tokenType, lexeme);
}

char* setText(string s) {
    char* cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    return cstr;
}

void beginScope() {
	scopeStack.push(SymbolTable());
	printf("\n___Entering new scope... \n\n");
}

void endScope() {
	scopeStack.pop();
	printf("\n___Exiting scope...\n\n");
}

bool findEntryInAnyScope(const string entry) {
	if (scopeStack.empty()) return false;
	bool found = scopeStack.top().findEntry(entry);
	if (found) {
		return true;
	} else {
		SymbolTable symbolTable = scopeStack.top();
		scopeStack.pop();
		found = findEntryInAnyScope(entry);
		scopeStack.push(symbolTable);
		return found;
	}
}

int main()
{
  do
  {
	yyparse();
  } while (!feof(yyin));

  return(0);
}
