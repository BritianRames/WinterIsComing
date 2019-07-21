/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.3.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/flex-bison/bwic.y" /* yacc.c:337  */

  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  extern FILE *yyin;
  extern int numlin;
  int yydebug = 0;
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

#line 90 "bwic.tab.c" /* yacc.c:337  */
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
#line 21 "src/flex-bison/bwic.y" /* yacc.c:352  */
 int number; char* string; 

#line 180 "bwic.tab.c" /* yacc.c:352  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BWIC_TAB_H_INCLUDED  */



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
typedef unsigned short yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short yytype_int16;
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
#  define YYSIZE_T unsigned
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
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
#define YYLAST   164

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  85
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

#define YYUNDEFTOK  2
#define YYMAXUTOK   298

/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  ((unsigned) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
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
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    89,    93,    94,    95,    95,    96,    97,
      98,   101,   102,   105,   105,   105,   105,   105,   108,   109,
     110,   113,   114,   115,   116,   119,   120,   121,   122,   123,
     126,   127,   128,   129,   130,   131,   132,   135,   136,   137,
     140,   141,   142,   143,   144,   145,   145,   146,   147,   151,
     151,   151,   152,   152,   152,   153,   153,   153,   154,   154,
     157,   158,   171,   171,   171,   171,   172,   174,   174,   174,
     174,   175,   175,   175,   175,   175,   178,   179,   180,   181,
     184,   185,   186,   187,   188,   189
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
  "functionCallParams", "aritmeticOperation", "$@7", "return", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "print", "else", "$@15",
  "$@16", "$@17", "controlStructure", "$@18", "$@19", "$@20", "$@21",
  "$@22", "$@23", "$@24", "logicalOperation", "logicalOperator", YY_NULLPTR
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

#define YYPACT_NINF -89

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-89)))

#define YYTABLE_NINF -72

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -89,     9,     5,   -89,   -22,     5,    -3,     1,   -89,    38,
      28,    41,    43,    51,   -89,    14,    75,   -89,   -89,    13,
      49,     5,     5,     5,     5,    83,    70,    15,   -19,    90,
      81,   -89,   104,    82,    48,   -89,   -89,   -89,   -89,   -89,
      84,    61,   108,   -89,    15,    15,    15,    15,   116,    89,
     -89,    95,   -89,   -89,   100,    15,    55,    55,   -89,   -89,
      -4,    97,   -89,   -89,    98,    80,   -89,   -89,   -89,     4,
     -89,    15,    91,   125,   -89,   -89,     4,    99,   101,   -89,
       4,   -89,   -89,   106,   105,     2,   -89,    17,   109,     2,
     -89,   103,   110,   -89,   -89,   -89,   111,   112,   -89,   114,
      90,    18,   -89,   113,     2,     2,   117,   -89,   -89,   -89,
     -89,   102,   102,   107,   -89,   -89,   -89,    18,   -89,    15,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    26,    27,
     -89,   -89,   115,   -89,   -89,   -89,   -89,   121,   118,   -89,
     119,   123,   -89,   120,     2,   -89,   126,     2,   -89,   -89,
     124,   127,   -89,   130,   -89,   -89,   131,   128,   -89,     2,
     129,   -89
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     6,     1,     0,     6,     0,     0,     3,     0,
       0,     0,     0,    11,     8,     0,     0,    31,    32,     0,
       0,     6,     6,     6,     6,     0,    47,     0,    48,    33,
       0,    47,     0,    48,     0,    13,     7,     4,     5,     9,
       0,     0,     0,    45,     0,     0,     0,     0,     0,     0,
      61,     0,    12,    44,     0,    39,    40,    41,    42,    43,
       0,     0,    14,    36,     0,    37,    35,    34,    60,    20,
      46,    39,     0,     0,    15,    38,    20,     0,     0,    18,
      20,    16,    19,     0,     0,    24,    29,     0,     0,    24,
      26,     0,     0,    25,    27,    28,     0,     0,    47,    48,
      55,     0,    23,     0,    24,    24,     0,    53,    45,    50,
      56,     0,     0,     0,    17,    21,    22,     0,    54,    39,
      51,    57,    80,    81,    84,    85,    82,    83,     0,     0,
      67,    72,     0,    78,    79,    77,    76,     0,     0,    59,
       0,     0,    68,     0,    24,    73,     0,    24,    69,    74,
      62,     0,    70,     0,    75,    63,     0,     0,    64,    24,
       0,    65
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -89,   -89,   -89,    96,   -89,    63,   -89,   -89,   -89,   -89,
     -89,   -57,   -88,   -89,    76,   -69,   -15,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,    86,   -89,   -89,   -89,
     -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,   -89,    23,
      32
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     8,     9,    90,    21,    51,    69,    78,
      83,    74,    91,    92,    93,    64,    65,    55,    94,   109,
     120,   107,   118,   110,   121,   119,    95,   152,   153,   156,
     159,    96,   137,   144,   150,    97,   138,   147,   151,   113,
     128
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,   102,    75,    66,    34,   -10,    86,    87,    15,     3,
      42,     4,    41,    72,     4,    43,   115,   116,    13,    79,
      31,    26,    31,    82,    98,   111,    16,    88,   -71,    56,
      57,    58,    59,   133,   135,    19,    67,    73,    89,    17,
      18,     5,     6,     7,    20,     6,     7,    27,    27,    27,
     132,    27,    32,    33,    28,    33,   146,    99,   112,   149,
      44,    45,    46,    47,    22,    10,   134,   136,    10,    46,
      47,   160,   100,    44,    45,    46,    47,    23,    11,    24,
      25,    11,    30,    50,    10,    10,    10,    10,    12,    35,
      40,    12,    44,    45,    46,    47,    53,    11,    11,    11,
      11,    14,    44,    45,    46,    47,   -30,    12,    12,    12,
      12,    48,    49,    71,    52,    54,    43,    36,    37,    38,
      39,   122,   123,   124,   125,   126,   127,    60,    61,    62,
      63,    76,    68,    70,    77,   103,    81,    84,   106,    80,
     131,    85,   130,   101,   129,     0,   104,   105,   108,   114,
     139,   117,   140,   141,   143,   142,   145,   155,   148,   154,
     -66,   161,   157,     0,   158
};

static const yytype_int16 yycheck[] =
{
      15,    89,    71,     7,    19,     0,     4,     5,    11,     0,
      29,     9,    27,     9,     9,    34,   104,   105,    40,    76,
       7,     7,     7,    80,     7,     7,    29,    25,    26,    44,
      45,    46,    47,     7,     7,    34,    40,    33,    36,    42,
      43,    36,    40,    41,     6,    40,    41,    34,    34,    34,
     119,    34,    39,    40,    40,    40,   144,    40,    40,   147,
      12,    13,    14,    15,    36,     2,    40,    40,     5,    14,
      15,   159,    87,    12,    13,    14,    15,    36,     2,    36,
      29,     5,     7,    35,    21,    22,    23,    24,     2,    40,
       7,     5,    12,    13,    14,    15,    35,    21,    22,    23,
      24,     5,    12,    13,    14,    15,    36,    21,    22,    23,
      24,    30,     8,    33,    30,     7,    34,    21,    22,    23,
      24,    19,    20,    21,    22,    23,    24,    11,    39,    34,
      30,    40,    35,    35,     9,    32,    35,    31,    26,    40,
     117,    36,    35,    34,   112,    -1,    36,    36,    34,    36,
      35,    34,    31,    35,    31,    36,    36,    27,    32,    32,
      36,    32,    31,    -1,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     9,    36,    40,    41,    48,    49,
      50,    59,    71,    40,    48,    11,    29,    42,    43,    34,
       6,    51,    36,    36,    36,    29,     7,    34,    40,    61,
       7,     7,    39,    40,    61,    40,    48,    48,    48,    48,
       7,    61,    29,    34,    12,    13,    14,    15,    30,     8,
      35,    52,    30,    35,     7,    62,    61,    61,    61,    61,
      11,    39,    34,    30,    60,    61,     7,    40,    35,    53,
      35,    33,     9,    33,    56,    60,    40,     9,    54,    56,
      40,    35,    56,    55,    31,    36,     4,     5,    25,    36,
      50,    57,    58,    59,    63,    71,    76,    80,     7,    40,
      61,    34,    57,    32,    36,    36,    26,    66,    34,    64,
      68,     7,    40,    84,    36,    57,    57,    34,    67,    70,
      65,    69,    19,    20,    21,    22,    23,    24,    85,    85,
      35,    84,    60,     7,    40,     7,    40,    77,    81,    35,
      31,    35,    36,    31,    78,    36,    57,    82,    32,    57,
      79,    83,    72,    73,    32,    27,    74,    31,    36,    75,
      57,    32
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    47,    46,    48,    48,    49,    48,    48,    48,
      48,    50,    50,    52,    53,    54,    55,    51,    56,    56,
      56,    57,    57,    57,    57,    58,    58,    58,    58,    58,
      59,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    61,    61,    61,    64,
      65,    63,    66,    67,    63,    68,    69,    63,    70,    63,
      71,    71,    73,    74,    75,    72,    72,    77,    78,    79,
      76,    80,    81,    82,    83,    76,    84,    84,    84,    84,
      85,    85,    85,    85,    85,    85
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     3,     3,     0,     3,     2,     3,
       0,     2,     5,     0,     0,     0,     0,    14,     3,     4,
       0,     3,     3,     2,     0,     1,     1,     1,     1,     1,
       3,     2,     2,     3,     6,     6,     6,     1,     3,     0,
       3,     3,     3,     3,     3,     0,     5,     1,     1,     0,
       0,     4,     0,     0,     4,     0,     0,     4,     0,     6,
       6,     4,     0,     0,     0,     8,     0,     0,     0,     0,
      12,     0,     0,     0,     0,    12,     3,     3,     3,     3,
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
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
  unsigned long yylno = yyrline[yyrule];
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
                       &yyvsp[(yyi + 1) - (yynrhs)]
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

  if (! yyres)
    return yystrlen (yystr);

  return (YYSIZE_T) (yystpcpy (yyres, yystr) - yyres);
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
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
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
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yynewstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  *yyssp = (yytype_int16) yystate;

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = (YYSIZE_T) (yyssp - yyss + 1);

# if defined yyoverflow
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
# else /* defined YYSTACK_RELOCATE */
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printf("Welcome to wic\n"); qInitialization();}
#line 1393 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 3:
#line 89 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {goToExit();closeScopeInSymbolTable();qEnding();}
#line 1399 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 6:
#line 95 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {if(marcador){jumpMain(); marcador = false;}}
#line 1405 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 11:
#line 101 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertVariableInSymbolTable((yyvsp[0].string)); declarationGlobalVariable((yyvsp[0].string));}
#line 1411 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 12:
#line 102 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    { insertArrayInSymbolTable((yyvsp[-3].string), (yyvsp[-1].number)); }
#line 1417 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 13:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertFunctionSymbolTable((yyvsp[0].string)); if(strcmp("main", (yyvsp[0].string))==0){mainFunction();}else{function((yyvsp[0].string));}}
#line 1423 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 14:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {openScopeInSymbolTable();}
#line 1429 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 15:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {closeScopeInSymbolTable();}
#line 1435 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 16:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {openScopeInSymbolTable();}
#line 1441 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 17:
#line 105 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {closeScopeInSymbolTable();}
#line 1447 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 18:
#line 108 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertParameterInSymbolTable((yyvsp[-1].string));}
#line 1453 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 19:
#line 109 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertParameterInSymbolTable((yyvsp[-1].string));}
#line 1459 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 29:
#line 123 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {/*breakCode();*/}
#line 1465 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 30:
#line 126 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {assignValueToVariable((yyvsp[-2].string),(yyvsp[0].number));}
#line 1471 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 31:
#line 127 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertVariableValueInStack((yyvsp[-1].string)); insertValueInStack(1); add();assignR0ToVariable((yyvsp[-1].string));}
#line 1477 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 32:
#line 128 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertVariableValueInStack((yyvsp[-1].string)); insertValueInStack(1); substract();assignR0ToVariable((yyvsp[-1].string));}
#line 1483 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 33:
#line 129 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {assignR0ToVariable((yyvsp[-2].string));}
#line 1489 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 40:
#line 140 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {add();}
#line 1495 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 41:
#line 141 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {substract();}
#line 1501 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 42:
#line 142 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {product();}
#line 1507 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 43:
#line 143 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {division();}
#line 1513 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 45:
#line 145 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {saveR7inR4();}
#line 1519 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 46:
#line 145 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {functionCall((yyvsp[-4].string));}
#line 1525 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 47:
#line 146 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertValueInStack((yyvsp[0].number));}
#line 1531 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 48:
#line 147 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {insertVariableValueInStack((yyvsp[0].string));}
#line 1537 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 49:
#line 151 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++variable");}
#line 1543 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 50:
#line 151 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {putVariableInR0((yyvsp[-1].number));}
#line 1549 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 51:
#line 151 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {functionReturn();}
#line 1555 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 52:
#line 152 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++value");}
#line 1561 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 53:
#line 152 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {putValueInR0((yyvsp[-1].number));}
#line 1567 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 54:
#line 152 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {functionReturn();}
#line 1573 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 55:
#line 153 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++operation");}
#line 1579 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 56:
#line 153 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {putOperationResultInR0((yyvsp[-1].number));}
#line 1585 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 57:
#line 153 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {functionReturn();}
#line 1591 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 58:
#line 154 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {/*functionCall($<string>1,$<string>3);*/}
#line 1597 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 59:
#line 154 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printf("TERMINA LLAMADA FUNCION\n");}
#line 1603 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 60:
#line 157 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printString((yyvsp[-1].string));}
#line 1609 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 61:
#line 158 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printR0();}
#line 1615 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 62:
#line 171 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {pushClauseIFE(printGoToFinalEstructureElse());}
#line 1621 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 63:
#line 171 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printLabelInstruction(popClauseIF());}
#line 1627 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 64:
#line 171 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {openScopeInSymbolTable();}
#line 1633 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 65:
#line 171 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {closeScopeInSymbolTable(); printLabelInstruction(popClauseIFE());}
#line 1639 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 66:
#line 172 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printLabelInstruction(popClauseIF());}
#line 1645 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 67:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {pushClauseIF(printHeaderOfClauseInstruction());}
#line 1651 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 68:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {openScopeInSymbolTable();}
#line 1657 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 69:
#line 174 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {closeScopeInSymbolTable();}
#line 1663 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 71:
#line 175 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    { int label = _getNextLabel(); printLabelInstruction(label); pushClauseWI(label);}
#line 1669 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 72:
#line 175 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {int label = printHeaderOfClauseInstruction(); pushClauseWE(label);}
#line 1675 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 73:
#line 175 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {openScopeInSymbolTable();}
#line 1681 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 74:
#line 175 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {printClause();generateGoToWhile(popClauseWI());}
#line 1687 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 75:
#line 175 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {closeScopeInSymbolTable(); printClause(); printLabelInstruction(popClauseWE());}
#line 1693 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 76:
#line 178 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {logicalVariableToVariable((yyvsp[-2].string), (yyvsp[0].string), (yyvsp[-1].string));}
#line 1699 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 77:
#line 179 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    { logicalVariableToValue((yyvsp[-2].string), (yyvsp[0].number), (yyvsp[-1].string));}
#line 1705 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 78:
#line 180 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    { logicalValueToValue((yyvsp[-2].number), (yyvsp[0].number),(yyvsp[-1].string));}
#line 1711 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 79:
#line 181 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    { logicalVariableToValue((yyvsp[0].string), (yyvsp[-2].number), (yyvsp[-1].string));}
#line 1717 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 80:
#line 184 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = "==";}
#line 1723 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 81:
#line 185 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = "!=";}
#line 1729 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 82:
#line 186 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = "<";}
#line 1735 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 83:
#line 187 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = "<=";}
#line 1741 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 84:
#line 188 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = ">";}
#line 1747 "bwic.tab.c" /* yacc.c:1652  */
    break;

  case 85:
#line 189 "src/flex-bison/bwic.y" /* yacc.c:1652  */
    {(yyval.number) = ">=";}
#line 1753 "bwic.tab.c" /* yacc.c:1652  */
    break;


#line 1757 "bwic.tab.c" /* yacc.c:1652  */
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
#line 192 "src/flex-bison/bwic.y" /* yacc.c:1918  */


void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

