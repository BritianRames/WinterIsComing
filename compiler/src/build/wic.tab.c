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
#line 1 "flex-bison/wic.y" /* yacc.c:339  */


    /* Declaraciones */

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "../utils/termcolor.hpp"
    #include "../symbol-table/SymbolTable.hpp"
    #include "../code-generator/CodeGenerator.hpp"

    int yylex(void);
    void yyerror(char const *);

    extern int level;
    extern int yylineno;




#line 89 "wic.tab.c" /* yacc.c:339  */

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

/* In a future release of Bison, this section will be replaced
   by #include "wic.tab.h".  */
#ifndef YY_YY_WIC_TAB_H_INCLUDED
# define YY_YY_WIC_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NEW = 258,
    CONTINUE = 259,
    BREAK = 260,
    RETURN = 261,
    FUN = 262,
    GLOBAL = 263,
    STATIC = 264,
    INT_VAL = 265,
    REAL_VAL = 266,
    BOOL_VAL = 267,
    CHAR_VAL = 268,
    STRING_VAL = 269,
    INT_TYPE = 270,
    REAL_TYPE = 271,
    BOOL_TYPE = 272,
    CHAR_TYPE = 273,
    VOID = 274,
    ASSIGN = 275,
    SUM = 276,
    SUBSTRACT = 277,
    PRODUCT = 278,
    DIVIDE = 279,
    MODULUS = 280,
    POWER = 281,
    RADICAL = 282,
    INCREMENT = 283,
    DECREMENT = 284,
    AND = 285,
    OR = 286,
    NOT = 287,
    EQUALS = 288,
    NOT_EQUALS = 289,
    GREATER = 290,
    GREATER_EQUALS = 291,
    LESS = 292,
    LESS_EQUALS = 293,
    AND_BIT = 294,
    OR_BIT = 295,
    XOR_BIT = 296,
    LEFT_SHIFT = 297,
    RIGHT_SHIFT = 298,
    UNION = 299,
    DIFFERENCE = 300,
    INTERSECTION = 301,
    IF_CLAUSE = 302,
    FOR_WHILE_CLAUSE = 303,
    HEADER_END = 304,
    ELSE_IF_FOR_WHILE_CLAUSE = 305,
    SQUARE_BRACKET_OPEN = 306,
    SQUARE_BRACKET_CLOSE = 307,
    CURLY_BRACKET_OPEN = 308,
    CURLY_BRACKET_CLOSE = 309,
    ELEM_SEPARATOR = 310,
    PARETHESES_OPEN = 311,
    PARETHESES_CLOSE = 312,
    END_OF_INSTR = 313,
    OPEN_CONTEXT_TAG = 314,
    CLOSE_CONTEXT_TAG = 315,
    CHAR_QUOTE = 316,
    STRING_QUOTE = 317,
    ID = 318
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_WIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "wic.tab.c" /* yacc.c:358  */

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   570

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  95
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    88,    92,    96,   103,   110,   117,   118,
     119,   121,   122,   124,   130,   136,   142,   148,   155,   158,
     167,   168,   169,   170,   171,   172,   173,   174,   175,   177,
     185,   193,   194,   196,   208,   210,   215,   225,   228,   230,
     232,   234,   239,   242,   244,   246,   248,   263,   269,   271,
     273,   275,   277,   296,   305,   314,   315,   316,   317,   318,
     327,   336,   345,   354,   363,   372,   381,   390,   398,   399,
     400,   401,   402,   403,   404,   405,   406,   407,   409,   424,
     433,   442,   451,   453,   462,   463,   465,   466,   468,   474,
     482,   488,   496,   502,   509,   516
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NEW", "CONTINUE", "BREAK", "RETURN",
  "FUN", "GLOBAL", "STATIC", "INT_VAL", "REAL_VAL", "BOOL_VAL", "CHAR_VAL",
  "STRING_VAL", "INT_TYPE", "REAL_TYPE", "BOOL_TYPE", "CHAR_TYPE", "VOID",
  "ASSIGN", "SUM", "SUBSTRACT", "PRODUCT", "DIVIDE", "MODULUS", "POWER",
  "RADICAL", "INCREMENT", "DECREMENT", "AND", "OR", "NOT", "EQUALS",
  "NOT_EQUALS", "GREATER", "GREATER_EQUALS", "LESS", "LESS_EQUALS",
  "AND_BIT", "OR_BIT", "XOR_BIT", "LEFT_SHIFT", "RIGHT_SHIFT", "UNION",
  "DIFFERENCE", "INTERSECTION", "IF_CLAUSE", "FOR_WHILE_CLAUSE",
  "HEADER_END", "ELSE_IF_FOR_WHILE_CLAUSE", "SQUARE_BRACKET_OPEN",
  "SQUARE_BRACKET_CLOSE", "CURLY_BRACKET_OPEN", "CURLY_BRACKET_CLOSE",
  "ELEM_SEPARATOR", "PARETHESES_OPEN", "PARETHESES_CLOSE", "END_OF_INSTR",
  "OPEN_CONTEXT_TAG", "CLOSE_CONTEXT_TAG", "CHAR_QUOTE", "STRING_QUOTE",
  "ID", "$accept", "main", "input", "data_init", "array_init", "data_type",
  "instr", "params", "args", "fun_init", "fun_call", "while_instr",
  "while_middle_blocks", "while_end_block", "for_instr",
  "for_middle_blocks", "for_end_block", "if_instr", "if_middle_blocks",
  "if_end_block", "array_access", "expr", "term", "power", "factor",
  "data_value", "data_vector", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318
};
# endif

#define YYPACT_NINF -95

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-95)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,   111,   111,   111,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,    44,   -40,    -2,    27,   271,   271,   188,    38,
      49,    64,    73,   -95,    22,   -95,    26,    24,   -95,   -95,
     -95,   -95,   -95,   413,    19,     0,   -95,   -95,   -95,    28,
     -95,    26,   -95,    26,   -95,   -95,   -95,   -95,   -95,    19,
     -12,    14,   524,   333,    41,    46,    52,   271,   -95,   -95,
     107,   271,    98,   -95,    99,    -4,   -95,    27,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    27,    72,    18,    87,    87,    87,
      87,    87,    67,   -95,   271,   -95,     3,   -95,   -95,   524,
      80,   -48,   271,   271,    81,   -95,    19,    19,    19,    19,
      19,    19,    19,    19,    19,    19,    19,    19,    19,    19,
      19,    19,    19,    19,    66,    77,   361,     0,     0,     0,
     -95,   -95,   111,   524,   -95,   -95,    78,   524,   524,   -95,
      79,    82,    86,    76,   -21,   -95,     3,     3,    83,   -95,
     111,   -25,    90,    94,     3,    92,   100,   -95,   -95,   -95,
      96,   -95,   101,   109,   112,   -95,     3,    84,   -95,   211,
     -95,   114,   151,   116,   497,   117,   441,   258,   -95,   271,
     113,   118,   115,   119,   120,   469,   307,   142,   144,   149,
     153,   154,   271,   155,     3,   150,     3,   159,   160,   387,
     -95,   164,     3,   165,     3,     3,   156,   -95,   166,   -95,
     167,   168,   170,   -95,   -95,   -95,     3,   171,   -95
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      28,     0,     0,     0,    88,    90,    92,    13,    14,    15,
      16,    17,     0,     0,     0,     0,     0,     0,    28,     0,
       0,    78,     0,     2,     0,    10,     7,     0,    26,    27,
      24,    23,    22,    25,    76,    82,    85,    87,    77,     0,
       8,     5,     9,     6,    89,    91,    55,    57,    78,    67,
      78,     0,    32,     0,     0,     0,     0,     0,    56,    58,
       0,     0,    20,     1,    18,     0,     3,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    95,     0,    86,    28,    93,    94,    52,
       0,     0,     0,     0,     0,    12,    53,    54,    65,    66,
      63,    64,    61,    62,    59,    60,    68,    69,    70,    71,
      72,    73,    74,    75,     0,     0,     0,    79,    80,    81,
      84,    83,     0,    31,     4,    51,     0,    21,    19,    11,
       0,     0,     0,     0,     0,    35,    28,    28,     0,    30,
       0,     0,     0,     0,    28,     0,     0,    34,    48,    38,
       0,    29,     0,    50,    40,    43,    28,     0,    46,     0,
      36,    45,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    28,     0,    28,     0,     0,     0,
      33,     0,    28,     0,    28,    28,     0,    49,     0,    39,
       0,     0,     0,    47,    37,    44,    28,     0,    42
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -94,   -95,    55,     2,   152,   -95,   169,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -16,   110,    16,   -15,   -95,   -95
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,   144,    51,    28,
      29,    30,   164,   170,    31,   171,   178,    32,   163,   168,
      62,    33,    34,    35,    36,    37,    38
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      52,    53,   134,    39,    41,    43,   104,    94,    57,   136,
       1,     2,     3,     4,     5,     6,    58,    59,     7,     8,
       9,    10,    11,    46,   156,    12,    90,    91,     4,     5,
       6,    13,    14,   157,   150,    15,   151,     4,     5,     6,
      12,    99,    87,    88,    89,    52,    13,    14,   105,    12,
      15,    55,   152,   153,    44,    45,    16,    40,    42,    17,
     160,    47,    18,    56,    19,    20,    21,   125,    93,    94,
     126,    16,   172,    63,    17,   130,   131,    65,   133,    19,
      20,    50,    66,    17,    57,    64,   137,   138,    19,    20,
      48,    92,    58,    59,     4,     5,     6,     4,     5,     6,
     201,    96,   203,   127,   128,   129,    12,    97,   208,    12,
     210,   211,    13,    14,    98,    60,    15,   100,   102,   103,
      61,   124,   217,   132,   140,    49,     7,     8,     9,    10,
      11,   173,   135,   139,   143,   141,   145,    16,   146,   149,
      17,   147,   154,    17,   148,    19,    20,    50,    19,    20,
     158,   174,   155,   176,   159,   161,   165,   179,   162,   167,
     166,   185,   169,   186,   177,   180,   182,   188,   190,   191,
      54,   187,     0,   189,     0,     0,   199,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,     1,     2,     3,     4,     5,
       6,   194,   195,     7,     8,     9,    10,    11,   196,   202,
      12,   197,   198,     0,   212,   200,    13,    14,   204,   205,
      15,     4,     5,     6,   207,   209,   213,   214,   215,   216,
     101,   218,     0,    12,     0,     0,     0,     0,     0,    13,
      14,    16,     0,    15,    17,     0,     0,     0,     0,    19,
      20,    21,     0,     0,     0,     0,     0,     0,     0,   175,
       0,     0,     0,     0,    16,     0,     0,    17,     4,     5,
       6,     0,    19,    20,    50,     0,     0,     0,     0,     0,
      12,     4,     5,     6,     0,     0,    13,    14,     0,     0,
      15,     0,     0,    12,     0,     0,     0,     0,     0,    13,
      14,     0,     0,    15,     0,     0,   184,     0,     0,     0,
       0,    16,     0,     0,    17,     0,     0,     0,     0,    19,
      20,    50,     0,     0,    16,     0,     0,    17,    67,    68,
       0,     0,    19,    20,    50,     0,     0,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    67,    68,     0,     0,     0,     0,
       0,     0,     0,    69,    70,   193,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
       0,     0,    67,    68,     0,     0,     0,     0,     0,     0,
      95,    69,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    67,    68,
     142,     0,     0,     0,     0,     0,     0,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    67,    68,   206,     0,     0,     0,
       0,     0,     0,    69,    70,     0,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    67,    68,     0,     0,     0,     0,     0,     0,
       0,    69,    70,     0,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,     0,   183,
      67,    68,     0,     0,     0,     0,     0,     0,     0,    69,
      70,     0,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,     0,   192,    67,    68,
       0,     0,     0,     0,     0,     0,     0,    69,    70,     0,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,   181,    67,    68,     0,     0,     0,
       0,     0,     0,     0,    69,    70,     0,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84
};

static const yytype_int16 yycheck[] =
{
      16,    17,    96,     1,     2,     3,    10,    55,    20,    57,
       7,     8,     9,    10,    11,    12,    28,    29,    15,    16,
      17,    18,    19,    63,    49,    22,    26,    27,    10,    11,
      12,    28,    29,    58,    55,    32,    57,    10,    11,    12,
      22,    57,    23,    24,    25,    61,    28,    29,    52,    22,
      32,    13,   146,   147,    10,    11,    53,     2,     3,    56,
     154,    63,    59,    14,    61,    62,    63,    49,    54,    55,
      86,    53,   166,     0,    56,    90,    91,    51,    94,    61,
      62,    63,    58,    56,    20,    63,   102,   103,    61,    62,
      63,    63,    28,    29,    10,    11,    12,    10,    11,    12,
     194,    60,   196,    87,    88,    89,    22,    61,   202,    22,
     204,   205,    28,    29,    62,    51,    32,    10,    20,    20,
      56,    49,   216,    56,    58,    15,    15,    16,    17,    18,
      19,    47,    52,    52,   132,    58,    58,    53,    59,    63,
      56,    59,    59,    56,    58,    61,    62,    63,    61,    62,
      60,   167,   150,   169,    60,    63,    60,     6,    58,    50,
      59,   177,    50,   179,    50,    49,    49,    49,    49,    49,
      18,    58,    -1,    58,    -1,    -1,   192,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,     7,     8,     9,    10,    11,
      12,    59,    58,    15,    16,    17,    18,    19,    59,    59,
      22,    58,    58,    -1,    58,    60,    28,    29,    59,    59,
      32,    10,    11,    12,    60,    60,    60,    60,    60,    59,
      61,    60,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    53,    -1,    32,    56,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    53,    -1,    -1,    56,    10,    11,
      12,    -1,    61,    62,    63,    -1,    -1,    -1,    -1,    -1,
      22,    10,    11,    12,    -1,    -1,    28,    29,    -1,    -1,
      32,    -1,    -1,    22,    -1,    -1,    -1,    -1,    -1,    28,
      29,    -1,    -1,    32,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    61,
      62,    63,    -1,    -1,    53,    -1,    -1,    56,    21,    22,
      -1,    -1,    61,    62,    63,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    21,    22,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    58,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      -1,    -1,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      57,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    21,    22,
      49,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    21,    22,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    21,    22,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    -1,    48,
      21,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,
      31,    -1,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    -1,    48,    21,    22,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,    -1,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    21,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    15,    16,    17,
      18,    19,    22,    28,    29,    32,    53,    56,    59,    61,
      62,    63,    65,    66,    67,    68,    69,    70,    73,    74,
      75,    78,    81,    85,    86,    87,    88,    89,    90,    69,
      68,    69,    68,    69,    10,    11,    63,    63,    63,    86,
      63,    72,    85,    85,    70,    13,    14,    20,    28,    29,
      51,    56,    84,     0,    63,    51,    58,    21,    22,    30,
      31,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    23,    24,    25,
      26,    27,    63,    54,    55,    57,    60,    61,    62,    85,
      10,    72,    20,    20,    10,    52,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    49,    49,    85,    87,    87,    87,
      88,    88,    56,    85,    66,    52,    57,    85,    85,    52,
      58,    58,    49,    69,    71,    58,    59,    59,    58,    63,
      55,    57,    66,    66,    59,    69,    49,    58,    60,    60,
      66,    63,    58,    82,    76,    60,    59,    50,    83,    50,
      77,    79,    66,    47,    85,    48,    85,    50,    80,     6,
      49,    47,    49,    48,    48,    85,    85,    58,    49,    58,
      49,    49,    48,    58,    59,    58,    59,    58,    58,    85,
      60,    66,    59,    66,    59,    59,    49,    60,    66,    60,
      66,    66,    58,    60,    60,    60,    59,    66,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    75,    76,    76,    77,
      77,    78,    79,    79,    80,    80,    81,    82,    82,    83,
      83,    84,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    86,    86,
      86,    86,    86,    87,    87,    87,    88,    88,    89,    89,
      89,    89,    89,    89,    89,    90
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     4,     2,     2,     1,     2,     2,
       1,     4,     3,     1,     1,     1,     1,     1,     2,     4,
       2,     4,     1,     1,     1,     1,     1,     1,     0,     4,
       2,     3,     1,    14,     7,     5,     9,     9,     0,     7,
       0,    10,    10,     0,     7,     0,     9,     9,     0,     7,
       0,     3,     3,     3,     3,     2,     2,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     1,     1,     1,     3,
       3,     3,     1,     3,     3,     1,     3,     1,     1,     2,
       1,     2,     1,     3,     3,     3
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
#line 82 "flex-bison/wic.y" /* yacc.c:1646  */
    {
		main_->add_body(main_body);
		ast->tree_build(main_);
		ast->to_code(cg);
	    }
#line 1509 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 88 "flex-bison/wic.y" /* yacc.c:1646  */
    {
			    ASTNode* node = reinterpret_cast<ASTNode *>((yyvsp[-1]));
			    main_body->add_instr(node);
			  }
#line 1518 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "flex-bison/wic.y" /* yacc.c:1646  */
    {wic::ASTBodyNode* body_ = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[-3]));
					       wic::ASTNode* instr = reinterpret_cast<wic::ASTNode* >((yyvsp[-1]));
					       body_->add_instr(instr);}
#line 1526 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 96 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[0]));
						    entry_d->var.global = true;
						    entry_d->var.stat = false;
						    entry_d->var.local = false;
						    (yyval) = entry_d;
						  }
#line 1538 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 103 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[0]));
						    entry_d->var.global = false;
						    entry_d->var.stat = true;
						    entry_d->var.local = false;
						    (yyval) = entry_d;
    						  }
#line 1550 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 110 "flex-bison/wic.y" /* yacc.c:1646  */
    {
    						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[0]));
    						    entry_d->var.global = false;
    						    entry_d->var.stat = false;
    						    entry_d->var.local = true;
    						    (yyval) = entry_d;
     						  }
#line 1562 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 124 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::INT;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
						  }
#line 1573 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 130 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::REAL;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
						  }
#line 1584 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 136 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::BOOL;
						    entry_d->var.size = 1;
						    (yyval) = entry_d;
						  }
#line 1595 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 142 "flex-bison/wic.y" /* yacc.c:1646  */
    {
    						    wic::entry_data* entry_d = new wic::entry_data();
    						    entry_d->var.type = wic::CHAR;
    						    entry_d->var.size = 1;
    						    (yyval) = entry_d;
    						  }
#line 1606 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 148 "flex-bison/wic.y" /* yacc.c:1646  */
    {
    						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::VOID;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
    						  }
#line 1617 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 155 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						    (yyval) = ast->tree_build((yyvsp[-1]), (yyvsp[0]));
						  }
#line 1625 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 158 "flex-bison/wic.y" /* yacc.c:1646  */
    {
    						    wic::ASTNode* id = ast->tree_build((yyvsp[-3]), (yyvsp[-2]));

    						    wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));
    						    wic::ASTAssignNode* assign = new wic::ASTAssignNode(id->get_data_type(), id, expr);
    						    (yyval) = ast->tree_build(assign);
    						    ast->print();
    						    std::cout << std::endl;
    						  }
#line 1639 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 167 "flex-bison/wic.y" /* yacc.c:1646  */
    { printf("Término (VectorVal)");}
#line 1645 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 169 "flex-bison/wic.y" /* yacc.c:1646  */
    {(yyval) = ((yyvsp[0]));}
#line 1651 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 171 "flex-bison/wic.y" /* yacc.c:1646  */
    {(yyval) = ((yyvsp[0]));}
#line 1657 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 172 "flex-bison/wic.y" /* yacc.c:1646  */
    { (yyval) = ((yyvsp[0])); }
#line 1663 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 173 "flex-bison/wic.y" /* yacc.c:1646  */
    { (yyval) =((yyvsp[0])); }
#line 1669 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 177 "flex-bison/wic.y" /* yacc.c:1646  */
    {
        										wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[-1]));
        										wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[0]));
        										id->set_data_type(entry_d->var.type);
												wic::ASTParamNode* params = reinterpret_cast<wic::ASTParamNode *>((yyvsp[-3]));
												params->add_params(id);
												(yyval) = ast->tree_build(params);
											}
#line 1682 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 185 "flex-bison/wic.y" /* yacc.c:1646  */
    {
						wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[-1]));
        				wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[0]));
        				id->set_data_type(entry_d->var.type);
						wic::ASTParamNode* params = new wic::ASTParamNode(id);
						(yyval) = ast->tree_build(params);
					}
#line 1694 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 198 "flex-bison/wic.y" /* yacc.c:1646  */
    {
        wic::ASTNode* id = ast->tree_build((yyvsp[-12]),(yyvsp[-11]));
		printf("HOLA MUNDO\n");
		wic::ASTParamNode* param = reinterpret_cast<wic::ASTParamNode *>((yyvsp[-9]));
		wic::ASTBodyNode* body = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[-4]));
		wic::ASTIDNode* expr = reinterpret_cast<wic::ASTIDNode *>((yyvsp[-2]));
		wic::ASTReturnNode* ret = new wic::ASTReturnNode(expr);
		wic::ASTFunctionNode* func = new wic::ASTFunctionNode(id->get_id(),id->get_data_type(),param,body,ret);
		(yyval) = ast->tree_build(func);
     }
#line 1709 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 211 "flex-bison/wic.y" /* yacc.c:1646  */
    {

								}
#line 1717 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 251 "flex-bison/wic.y" /* yacc.c:1646  */
    {
      		     wic::ASTRelationalNode* expr = reinterpret_cast<wic::ASTRelationalNode *>((yyvsp[-8]));
      		     wic::ASTBodyNode* input = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[-3]));
      		     wic::ASTIfNode* ifmid_= reinterpret_cast<wic::ASTIfNode *>((yyvsp[-1]));
		     wic::ASTBodyNode* else_ = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[0]));

		     wic::ASTIfNode* if_ = new wic::ASTIfNode(expr, input, else_);
		     if_->add_mid_block(ifmid_);

		     (yyval) = ast->tree_build(if_);
		   }
#line 1733 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 264 "flex-bison/wic.y" /* yacc.c:1646  */
    {
        					  wic::ASTRelationalNode* expr = reinterpret_cast<wic::ASTRelationalNode *>((yyvsp[-6]));
      						  wic::ASTBodyNode* input = reinterpret_cast<wic::ASTBodyNode* >((yyvsp[-1]));
      						  (yyval) = new wic::ASTIfNode(expr, input);
      					       }
#line 1743 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 272 "flex-bison/wic.y" /* yacc.c:1646  */
    { (yyval) = ((yyvsp[-2])); }
#line 1749 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 278 "flex-bison/wic.y" /* yacc.c:1646  */
    {
					    wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[-2]));

					    if (!id->is_registered()) {
						std::cout << termcolor::red << termcolor::bold
							<< "[!] Error: " << termcolor::reset << "\'" << id->get_id()
							<< "\' was not declared in this scope"
							<< std::endl;
						exit(-1);
				    	}

				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));
				    	wic::ASTAssignNode* assign = new wic::ASTAssignNode(id->get_data_type(), id, term);

				 	(yyval) = ast->tree_build(assign);
					lst->show(id->get_id());

			  	}
#line 1772 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 297 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

				    	wic::ASTSumNode* sum = new wic::ASTSumNode(expr, term);
				 	sum->to_code(cg);
				    	(yyval) = ast->tree_build(sum);
				}
#line 1785 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 306 "flex-bison/wic.y" /* yacc.c:1646  */
    {
                                	wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
                                        wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

                                        wic::ASTSubNode* sub = new wic::ASTSubNode(expr, term);

                                        (yyval) = ast->tree_build(sub);
			  	}
#line 1798 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 319 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTLessNode* less = new wic::ASTLessNode(expr, term);

 					(yyval) = ast->tree_build(less);
 				}
#line 1811 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 328 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTLessEqualNode* less_equal = new wic::ASTLessEqualNode(expr, term);

 					(yyval) = ast->tree_build(less_equal);
 				}
#line 1824 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 337 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTGreaterNode* greater = new wic::ASTGreaterNode(expr, term);

 					(yyval) = ast->tree_build(greater);
 				}
#line 1837 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 346 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTGreaterEqualNode* greater_equal = new wic::ASTGreaterEqualNode(expr, term);

 					(yyval) = ast->tree_build(greater_equal);
 				}
#line 1850 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 355 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTEqualNode* equal = new wic::ASTEqualNode(expr, term);

 					(yyval) = ast->tree_build(equal);
 				}
#line 1863 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 364 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTNotEqualNode* not_equal = new wic::ASTNotEqualNode(expr, term);

 					(yyval) = ast->tree_build(not_equal);
 				}
#line 1876 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 373 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTAndNode* and_ = new wic::ASTAndNode(expr, term);

 					(yyval) = ast->tree_build(and_);
 				}
#line 1889 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 382 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTOrNode* or_ = new wic::ASTOrNode(expr, term);

 					(yyval) = ast->tree_build(or_);
 				}
#line 1902 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 391 "flex-bison/wic.y" /* yacc.c:1646  */
    {
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

 					wic::ASTNotNode* not_ = new wic::ASTNotNode(term);

 					(yyval) = ast->tree_build(not_);
 				}
#line 1914 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 406 "flex-bison/wic.y" /* yacc.c:1646  */
    { (yyval) = ((yyvsp[0])); }
#line 1920 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 410 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[0]));
				    	std::cout << "Factor : ID (name=" << id->get_id() << ")" << std::endl;

				    	if (!id->is_registered())
				    	{
						std::cout << termcolor::red << termcolor::bold
							<< "[!] Error: " << termcolor::reset << "\'" << id->get_id()
      						  	<< "\' was not declared in this scope"
      						  	<< std::endl;
      						  	exit(-1);
				    	}
				    		(yyval) = ast->tree_build(id);
			  	}
#line 1939 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 425 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

				    	wic::ASTProdNode* prod = new wic::ASTProdNode(term, power);

				    	(yyval) = ast->tree_build(prod);
			  	}
#line 1952 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 434 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

				    	wic::ASTDivNode* div = new wic::ASTDivNode(term, power);

				    	(yyval) = ast->tree_build(div);
			  	}
#line 1965 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 443 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

				    	wic::ASTModNode* mod = new wic::ASTModNode(term, power);

				    	(yyval) = ast->tree_build(mod);
			  	}
#line 1978 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 454 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[-2]));
				    	wic::ASTNode* factor = reinterpret_cast<wic::ASTNode *>((yyvsp[0]));

				    	wic::ASTRadicalNode* radical = new wic::ASTRadicalNode(power, factor);

				    	(yyval) = ast->tree_build(radical);
			  	}
#line 1991 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 469 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[0]));
				    	std::cout << "Factor : INT(value=" << node->get_data_value().int_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2001 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 475 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[0]));
				    	int val = -node->get_data_value().int_val;
				    	node->set_data_value((void*)&val);
				    	std::cout << "Factor: NEG_INT(value=" << node->get_data_value().int_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2013 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 483 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[0]));
				    	std::cout << "Factor : REAL(value=" << node->get_data_value().real_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2023 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 489 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[0]));
				    	float val = -node->get_data_value().real_val;
				    	node->set_data_value((void*)&val);
				    	std::cout << "Factor: NEG_REAL(value=" << node->get_data_value().real_val << ")" << std::endl;
					(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2035 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 497 "flex-bison/wic.y" /* yacc.c:1646  */
    {
			    		wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[0]));
				    	std::cout << "Factor : BOOL(value=" << node->get_data_value().bool_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
				}
#line 2045 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 503 "flex-bison/wic.y" /* yacc.c:1646  */
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[-1]));
				    	std::cout << "Factor : CHAR(value=" << node->get_data_value().char_val << ",ascii="
					    << (int)node->get_data_value().char_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2056 "wic.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 510 "flex-bison/wic.y" /* yacc.c:1646  */
    {
			    		wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[-1]));
				    	std::cout << "Factor : STRING(value=" << node->get_data_value().str_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	}
#line 2066 "wic.tab.c" /* yacc.c:1646  */
    break;


#line 2070 "wic.tab.c" /* yacc.c:1646  */
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
#line 518 "flex-bison/wic.y" /* yacc.c:1906  */
