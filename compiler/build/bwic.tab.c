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
#line 1 "src/flex-bison/bwic.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  extern FILE *yyin;
  extern int numlin;
  int yydebug = 1;
  char* box ;
  void yyerror (char const*);
  char* stringWithNewline(char*);
  int miVariableA;
  int miVariableB;
  int else_l;
  int exit_l;
  int exit_l2;
  int while_l;
  bool marcador = true;

#line 86 "bwic.tab.c" /* yacc.c:339  */

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
   by #include "bwic.tab.h".  */
#ifndef YY_YY_BWIC_TAB_H_INCLUDED
# define YY_YY_BWIC_TAB_H_INCLUDED
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
    CONTINUE = 258,
    BREAK = 259,
    RETURN = 260,
    FUN = 261,
    INT_VAL = 262,
    STRING_VAL = 263,
    INT_TYPE = 264,
    STRING_TYPE = 265,
    ASSIGN = 266,
    SUM = 267,
    SUBSTRACT = 268,
    PRODUCT = 269,
    DIVIDE = 270,
    AND = 271,
    OR = 272,
    NOT = 273,
    EQUALS = 274,
    NOT_EQUALS = 275,
    GREATER = 276,
    GREATER_EQUALS = 277,
    LESS = 278,
    LESS_EQUALS = 279,
    IF_CLAUSE = 280,
    WHILE_CLAUSE = 281,
    ELSE_CLAUSE = 282,
    HEADER_END = 283,
    SQUARE_BRACKET_OPEN = 284,
    SQUARE_BRACKET_CLOSE = 285,
    CURLY_BRACKET_OPEN = 286,
    CURLY_BRACKET_CLOSE = 287,
    COMMA = 288,
    PARENTESIS_OPEN = 289,
    PARENTESIS_CLOSE = 290,
    END_OF_INSTRUCTION = 291,
    OPEN_CONTEXT_TAG = 292,
    CLOSE_CONTEXT_TAG = 293,
    QUOTE = 294,
    ID = 295,
    PRINT = 296,
    PLUSPLUS = 297,
    MINUSMINUS = 298
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 21 "src/flex-bison/bwic.y" /* yacc.c:355  */
 int number; char* string; 

#line 173 "bwic.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BWIC_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 190 "bwic.tab.c" /* yacc.c:358  */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   178

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    44,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    89,    89,    89,    93,    94,    95,    95,    96,    97,
      98,   101,   102,   105,   105,   105,   105,   105,   108,   109,
     110,   113,   114,   115,   116,   119,   120,   121,   122,   123,
     126,   127,   128,   129,   130,   131,   132,   133,   136,   137,
     138,   139,   141,   142,   143,   144,   145,   146,   147,   151,
     152,   153,   154,   154,   157,   160,   161,   162,   163,   166,
     167,   170,   170,   170,   171,   173,   173,   173,   173,   174,
     174,   174,   174,   174,   177,   198,   219,   240,   263,   264,
     265,   266,   267,   268
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CONTINUE", "BREAK", "RETURN", "FUN",
  "INT_VAL", "STRING_VAL", "INT_TYPE", "STRING_TYPE", "ASSIGN", "SUM",
  "SUBSTRACT", "PRODUCT", "DIVIDE", "AND", "OR", "NOT", "EQUALS",
  "NOT_EQUALS", "GREATER", "GREATER_EQUALS", "LESS", "LESS_EQUALS",
  "IF_CLAUSE", "WHILE_CLAUSE", "ELSE_CLAUSE", "HEADER_END",
  "SQUARE_BRACKET_OPEN", "SQUARE_BRACKET_CLOSE", "CURLY_BRACKET_OPEN",
  "CURLY_BRACKET_CLOSE", "COMMA", "PARENTESIS_OPEN", "PARENTESIS_CLOSE",
  "END_OF_INSTRUCTION", "OPEN_CONTEXT_TAG", "CLOSE_CONTEXT_TAG", "QUOTE",
  "ID", "PRINT", "PLUSPLUS", "MINUSMINUS", "' '", "$accept", "begin",
  "$@1", "root", "$@2", "declaration", "function", "$@3", "$@4", "$@5",
  "$@6", "params", "codeSet", "instruction", "assignation",
  "functionCallParams", "aritmeticOperation", "return", "$@7", "print",
  "printableElement", "text", "else", "$@8", "$@9", "controlStructure",
  "$@10", "$@11", "$@12", "$@13", "$@14", "$@15", "$@16",
  "logicalOperation", "logicalOperator", YY_NULLPTR
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
     295,   296,   297,   298,    32
};
# endif

#define YYPACT_NINF -96

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-96)))

#define YYTABLE_NINF -70

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -96,     9,     4,   -96,   -28,     4,    43,     5,   -96,    30,
      13,    38,    39,    49,   -96,    17,    72,   -96,   -96,     7,
      42,     4,     4,     4,     4,    76,    51,    21,   -11,   102,
      59,   -96,    -1,   -96,    -4,   -96,   -96,   -96,   -96,   -96,
      60,   -96,   -96,    56,   111,     8,    21,    21,    21,    21,
     108,   -96,   -96,    81,     7,   -96,    87,   -96,   -96,    92,
      90,    91,    93,    45,    45,   -96,   -96,    18,   -96,   -96,
     -96,   -96,     8,     8,   -96,   -96,   -96,     2,   -96,   -96,
      85,   117,   -96,     2,    94,    95,   -96,     2,   -96,   -96,
      96,    97,     1,   -96,    22,    98,     1,   -96,    99,   100,
     -96,   -96,   -96,   101,   103,   -96,   104,   102,    23,   -96,
     105,     1,     1,   106,   -96,    89,    89,   107,   -96,   -96,
     -96,    23,     8,   -96,   -96,   -96,   -96,   -96,   -96,    25,
      26,   -96,   109,   110,   -96,   -96,   -96,   -96,   112,   -96,
     -96,   113,   115,   -96,   114,     1,   -96,   116,     1,   -96,
     -96,   118,   119,   -96,   120,   -96,   121,   122,   -96,     1,
     123,   -96
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     0,     6,     0,     0,     3,     0,
       0,     0,     0,    11,     8,     0,     0,    31,    32,     0,
       0,     6,     6,     6,     6,     0,    47,     0,    48,    34,
       0,    58,     0,    55,     0,    13,     7,     4,     5,     9,
       0,    47,    48,     0,     0,     0,     0,     0,     0,     0,
       0,    59,    60,     0,     0,    54,     0,    12,    46,     0,
      38,    39,     0,    42,    43,    44,    45,     0,    56,    57,
      14,    37,     0,     0,    33,    36,    35,    20,    40,    41,
       0,     0,    15,    20,     0,     0,    18,    20,    16,    19,
       0,     0,    24,    29,     0,     0,    24,    26,     0,     0,
      25,    27,    28,     0,     0,    47,    48,    51,     0,    23,
       0,    24,    24,     0,    52,     0,     0,     0,    17,    21,
      22,     0,     0,    78,    79,    82,    83,    80,    81,     0,
       0,    65,     0,     0,    76,    77,    75,    74,     0,    70,
      53,     0,     0,    66,     0,    24,    71,     0,    24,    67,
      72,    61,     0,    68,     0,    73,     0,     0,    62,    24,
       0,    63
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -96,   -96,   -96,    83,   -96,    71,   -96,   -96,   -96,   -96,
     -96,   -49,   -95,   -96,    75,   -70,   -27,   -96,   -96,    79,
     124,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,   -96,
     -96,   -96,   -96,    14,    37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    97,    21,    56,    77,    85,
      90,    82,    98,    99,   100,    62,    29,   101,   122,   102,
      34,    53,   153,   154,   159,   103,   138,   145,   151,   104,
     142,   148,   152,   117,   129
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,   109,    78,    79,   -10,    93,    94,    51,    54,     3,
       4,    80,    13,     4,    31,    60,   119,   120,    44,    63,
      64,    65,    66,    45,    26,    75,    95,   -69,    41,   105,
     115,    55,   134,   136,    86,    81,    20,    96,    89,    19,
       5,     6,     7,    52,     6,     7,    32,    33,    61,    22,
     147,    27,   133,   150,    15,    27,    27,    28,    76,    48,
      49,    42,   106,   116,   160,   135,   137,   107,    46,    47,
      48,    49,    16,    10,    23,    24,    10,    11,    25,    30,
      11,    12,    35,    40,    12,    17,    18,   -30,    14,    50,
      57,    58,    10,    10,    10,    10,    11,    11,    11,    11,
      12,    12,    12,    12,    36,    37,    38,    39,   123,   124,
     125,   126,   127,   128,    46,    47,    48,    49,    59,    67,
      68,    70,    71,    72,    73,    83,    84,    91,    74,   113,
      88,   110,   108,    92,    87,   132,   111,   112,   114,     0,
     121,   118,   131,   141,   139,   140,   144,   156,   149,   143,
     146,   155,   157,   130,   -64,   161,     0,     0,   158,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    69
};

static const yytype_int16 yycheck[] =
{
      27,    96,    72,    73,     0,     4,     5,     8,    12,     0,
       9,     9,    40,     9,     7,     7,   111,   112,    29,    46,
      47,    48,    49,    34,     7,     7,    25,    26,     7,     7,
       7,    35,     7,     7,    83,    33,     6,    36,    87,    34,
      36,    40,    41,    44,    40,    41,    39,    40,    40,    36,
     145,    34,   122,   148,    11,    34,    34,    40,    40,    14,
      15,    40,    40,    40,   159,    40,    40,    94,    12,    13,
      14,    15,    29,     2,    36,    36,     5,     2,    29,     7,
       5,     2,    40,     7,     5,    42,    43,    36,     5,    30,
      30,    35,    21,    22,    23,    24,    21,    22,    23,    24,
      21,    22,    23,    24,    21,    22,    23,    24,    19,    20,
      21,    22,    23,    24,    12,    13,    14,    15,     7,    11,
      39,    34,    30,    33,    33,    40,     9,    31,    35,    26,
      35,    32,    34,    36,    40,   121,    36,    36,    34,    -1,
      34,    36,    35,    31,    35,    35,    31,    27,    32,    36,
      36,    32,    31,   116,    36,    32,    -1,    -1,    36,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     9,    36,    40,    41,    48,    49,
      50,    59,    64,    40,    48,    11,    29,    42,    43,    34,
       6,    51,    36,    36,    36,    29,     7,    34,    40,    61,
       7,     7,    39,    40,    65,    40,    48,    48,    48,    48,
       7,     7,    40,    61,    29,    34,    12,    13,    14,    15,
      30,     8,    44,    66,    12,    35,    52,    30,    35,     7,
       7,    40,    60,    61,    61,    61,    61,    11,    39,    65,
      34,    30,    33,    33,    35,     7,    40,    53,    60,    60,
       9,    33,    56,    40,     9,    54,    56,    40,    35,    56,
      55,    31,    36,     4,     5,    25,    36,    50,    57,    58,
      59,    62,    64,    70,    74,     7,    40,    61,    34,    57,
      32,    36,    36,    26,    34,     7,    40,    78,    36,    57,
      57,    34,    63,    19,    20,    21,    22,    23,    24,    79,
      79,    35,    78,    60,     7,    40,     7,    40,    71,    35,
      35,    31,    75,    36,    31,    72,    36,    57,    76,    32,
      57,    73,    77,    67,    68,    32,    27,    31,    36,    69,
      57,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    48,    48,    48,
      48,    50,    50,    52,    53,    54,    55,    51,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    59,    60,    60,
      60,    60,    61,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    62,    64,    65,    65,    65,    65,    66,
      66,    68,    69,    67,    67,    71,    72,    73,    70,    74,
      75,    76,    77,    70,    78,    78,    78,    78,    79,    79,
      79,    79,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     0,     3,     2,     3,
       0,     2,     5,     0,     0,     0,     0,    14,     3,     4,
       0,     3,     3,     2,     0,     1,     1,     1,     1,     1,
       3,     2,     2,     6,     3,     6,     6,     6,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1,     2,
       2,     2,     0,     6,     4,     1,     3,     3,     1,     1,
       1,     0,     0,     7,     0,     0,     0,     0,    12,     0,
       0,     0,     0,    12,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1
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
#line 89 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {printf("Welcome to wic\n"); qInitialization();}
#line 1388 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 89 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {goToExit();closeScopeInSymbolTable();qEnding();}
#line 1394 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 95 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {if(marcador){jumpMain(); marcador = false;}}
#line 1400 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 101 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertVariableInSymbolTable((yyvsp[0].string)); declarationGlobalVariable((yyvsp[0].string));}
#line 1406 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 102 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    { insertArrayInSymbolTable((yyvsp[-3].string), (yyvsp[-1].number)); }
#line 1412 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertFunctionSymbolTable((yyvsp[0].string)); if(strcmp("main", (yyvsp[0].string))==0){mainFunction();}}
#line 1418 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {openScopeInSymbolTable();}
#line 1424 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {closeScopeInSymbolTable();}
#line 1430 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {openScopeInSymbolTable();}
#line 1436 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {closeScopeInSymbolTable();}
#line 1442 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 108 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*insertVariable($<string>2);*/}
#line 1448 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 123 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*breakCode();*/}
#line 1454 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 126 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {assignValueToVariable((yyvsp[-2].string),(yyvsp[0].number));}
#line 1460 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 127 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertVariableValueInStack((yyvsp[-1].string)); insertValueInStack(1); add();assignR0ToVariable((yyvsp[-1].string));}
#line 1466 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 128 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertVariableValueInStack((yyvsp[-1].string)); insertValueInStack(1); substract();assignR0ToVariable((yyvsp[-1].string));}
#line 1472 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 130 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {assignR0ToVariable((yyvsp[-2].string));}
#line 1478 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 141 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {add();}
#line 1484 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 142 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {substract();}
#line 1490 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 143 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {product();}
#line 1496 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 144 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {division();}
#line 1502 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 146 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertValueInStack((yyvsp[0].number));}
#line 1508 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 147 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {insertVariableValueInStack((yyvsp[0].string));}
#line 1514 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 151 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*returnVariable($<number>2);*/}
#line 1520 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 152 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*returnValue($<number>2);*/}
#line 1526 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 153 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*returnValue($<number>2);*/}
#line 1532 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 154 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*functionCall($<string>1,$<string>3);*/}
#line 1538 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 154 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {printf("TERMINA LLAMADA FUNCION\n");}
#line 1544 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 160 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*generatePrintVariable($<string>1);*/}
#line 1550 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 161 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*generatePrintString($<string>2);*/}
#line 1556 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 163 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {printValue((yyvsp[0].number));}
#line 1562 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 166 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].string);}
#line 1568 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 167 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = (yyvsp[0].number);}
#line 1574 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 170 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*exit_l2 = exit_l; exit_l = _getNextLabel(); generateGoToInstruction(exit_l); generateLabelInstruction(exit_l2);*/}
#line 1580 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 170 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*openScopeInSymbolTable();*/}
#line 1586 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 170 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*closeScopeInSymbolTable(); generateLabelInstruction(exit_l);*/}
#line 1592 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 171 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*generateLabelInstruction(exit_l);*/}
#line 1598 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 173 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*exit_l = generateHeaderOfClauseInstruction();*/}
#line 1604 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 173 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {openScopeInSymbolTable();}
#line 1610 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 173 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {closeScopeInSymbolTable(); }
#line 1616 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/* while_l = _getNextLabel(); generateLabelInstruction(while_l);*/}
#line 1622 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*exit_l = generateHeaderOfClauseInstruction();*/}
#line 1628 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {openScopeInSymbolTable();}
#line 1634 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*generateGoToInstruction(while_l);*/}
#line 1640 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {/*closeScopeInSymbolTable(); generateLabelInstruction(exit_l);*/}
#line 1646 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 177 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].number)) {
					   	case 1:
							/*generateEqualsVariableToVariable($<string>1, $<string>3);*/
					   		break;
						case 2:
							/*generateNotEqualsVariableToVariable($<string>1, $<string>3);*/
							break;
						case 3:
							/*generateLessVariableToVariable($<string>1, $<string>3);*/
							break;
						case 4:
							/*generateLessEqualsVariableToVariable($<string>1, $<string>3);*/
							break;
						case 5:
							/*generateGreaterVariableToVariable($<string>1, $<string>3);*/
							break;
						case 6:
						default:
							/*generateGreaterEqualsVariableToVariable($<string>1, $<string>3);*/
							break;
					    } }
#line 1672 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 198 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].number)) {
						   case 1:
						   	/*generateEqualsValueToVariable($<string>1, $<number>3);*/
						   	break;
						   case 2:
						   	/*generateNotEqualsValueToVariable($<string>1, $<number>3);*/
						   	break;
						   case 3:
						   	/*generateLessValueToVariable($<string>1, $<number>3);*/
						   	break;
						   case 4:
						   	/*generateLessEqualsValueToVariable($<string>1, $<number>3);*/
						   	break;
						   case 5:
						   	/*generateGreaterValueToVariable($<string>1, $<number>3);*/
						   	break;
						   case 6:
						   default:
						   	/*generateGreaterEqualsValueToVariable($<string>1, $<number>3);*/
						   	break;
					        } }
#line 1698 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 219 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].number)) {
							   case 1:
								/*generateEqualsValueToValue($<number>1, $<number>3);*/
								break;
							   case 2:
								/*generateNotEqualsValueToValue($<number>1, $<number>3);*/
								break;
							   case 3:
								/*generateLessValueToValue($<number>1, $<number>3);*/
								break;
							   case 4:
								/*generateLessEqualsValueToValue($<number>1, $<number>3);*/
								break;
							   case 5:
								/*generateGreaterValueToValue($<number>1, $<number>3);*/
								break;
							   case 6:
							   default:
								/*generateGreaterEqualsValueToValue($<number>1, $<number>3);*/
								break;
							} }
#line 1724 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 240 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    { switch((yyvsp[-1].number)) {
						   case 1:
							/*generateEqualsValueToVariable($<number>1, $<string>3);*/
							break;
						   case 2:
							/*generateNotEqualsValueToVariable($<number>1, $<string>3);*/
							break;
						   case 3:
							/*generateLessValueToVariable($<number>1, $<string>3);*/
							break;
						   case 4:
							/*generateLessEqualsValueToVariable($<number>1, $<string>3);*/
							break;
						   case 5:
							/*generateGreaterValueToVariable($<number>1, $<string>3);*/
							break;
						   case 6:
						   default:
							/*generateGreaterEqualsValueToVariable($<number>1, $<string>3);*/
							break;
						} }
#line 1750 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 263 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 1;}
#line 1756 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 264 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 2;}
#line 1762 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 265 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 3;}
#line 1768 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 266 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 4;}
#line 1774 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 267 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 5;}
#line 1780 "bwic.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 268 "src/flex-bison/bwic.y" /* yacc.c:1646  */
    {(yyval.number) = 6;}
#line 1786 "bwic.tab.c" /* yacc.c:1646  */
    break;


#line 1790 "bwic.tab.c" /* yacc.c:1646  */
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
#line 271 "src/flex-bison/bwic.y" /* yacc.c:1906  */


//int main(int argc, char** argv) {
//  if (argc>1) yyin=fopen(argv[1],"r");
//  yyparse();
//}


void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

