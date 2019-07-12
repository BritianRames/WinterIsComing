
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "wic.y"


    /* Declaraciones */

    #include <math.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <iostream>

    #include "../utils/termcolor.hpp"
    #include "../symbol-table/SymbolTableManager.h"
    #include "../code-generator/CodeGeneratorManager.h"

    int yylex(void);
    void yyerror(char const *);

    extern int level;
    extern int yylineno;





/* Line 189 of yacc.c  */
#line 97 "wic.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 202 "wic.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

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
/* YYNRULES -- Number of states.  */
#define YYNSTATES  219

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   318

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     8,    13,    16,    19,    21,    24,
      27,    29,    34,    38,    40,    42,    44,    46,    48,    51,
      56,    59,    64,    66,    68,    70,    72,    74,    76,    77,
      82,    85,    89,    91,   106,   114,   120,   130,   140,   141,
     149,   150,   161,   172,   173,   181,   182,   192,   202,   203,
     211,   212,   216,   220,   224,   228,   231,   234,   237,   240,
     244,   248,   252,   256,   260,   264,   268,   272,   275,   279,
     283,   287,   291,   295,   299,   303,   307,   309,   311,   313,
     317,   321,   325,   327,   331,   335,   337,   341,   343,   345,
     348,   350,   353,   355,   359,   363
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      65,     0,    -1,    66,    -1,    70,    58,    -1,    59,    70,
      60,    66,    -1,     8,    69,    -1,     9,    69,    -1,    69,
      -1,     8,    68,    -1,     9,    68,    -1,    68,    -1,    69,
      51,    10,    52,    -1,    69,    51,    52,    -1,    15,    -1,
      16,    -1,    17,    -1,    18,    -1,    19,    -1,    67,    63,
      -1,    67,    63,    20,    85,    -1,    63,    84,    -1,    63,
      84,    20,    85,    -1,    81,    -1,    78,    -1,    75,    -1,
      85,    -1,    73,    -1,    74,    -1,    -1,    71,    55,    69,
      63,    -1,    69,    63,    -1,    72,    55,    85,    -1,    85,
      -1,     7,    69,    63,    56,    71,    57,    49,    58,    59,
      66,     6,    85,    58,    60,    -1,     7,    69,    63,    56,
      71,    57,    58,    -1,    63,    56,    72,    57,    58,    -1,
      85,    48,    49,    58,    59,    66,    60,    76,    77,    -1,
      76,    50,    85,    48,    49,    58,    59,    66,    60,    -1,
      -1,    50,    48,    49,    58,    59,    66,    60,    -1,    -1,
      85,    48,    85,    49,    58,    59,    66,    60,    79,    80,
      -1,    79,    50,    85,    48,    85,    49,    58,    59,    66,
      60,    -1,    -1,    50,    48,    49,    58,    59,    66,    60,
      -1,    -1,    85,    47,    49,    58,    59,    66,    60,    82,
      83,    -1,    82,    50,    85,    47,    49,    58,    59,    66,
      60,    -1,    -1,    50,    47,    49,    58,    59,    66,    60,
      -1,    -1,    51,    10,    52,    -1,    63,    20,    85,    -1,
      85,    21,    86,    -1,    85,    22,    86,    -1,    28,    63,
      -1,    63,    28,    -1,    29,    63,    -1,    63,    29,    -1,
      85,    37,    86,    -1,    85,    38,    86,    -1,    85,    35,
      86,    -1,    85,    36,    86,    -1,    85,    33,    86,    -1,
      85,    34,    86,    -1,    85,    30,    86,    -1,    85,    31,
      86,    -1,    32,    86,    -1,    85,    39,    86,    -1,    85,
      40,    86,    -1,    85,    41,    86,    -1,    85,    42,    86,
      -1,    85,    43,    86,    -1,    85,    44,    86,    -1,    85,
      45,    86,    -1,    85,    46,    86,    -1,    86,    -1,    90,
      -1,    63,    -1,    86,    23,    87,    -1,    86,    24,    87,
      -1,    86,    25,    87,    -1,    87,    -1,    87,    27,    88,
      -1,    87,    26,    88,    -1,    88,    -1,    56,    85,    57,
      -1,    89,    -1,    10,    -1,    22,    10,    -1,    11,    -1,
      22,    11,    -1,    12,    -1,    61,    13,    61,    -1,    62,
      14,    62,    -1,    53,    72,    54,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    87,    91,    95,   102,   109,   116,   117,
     118,   120,   121,   123,   129,   135,   141,   147,   154,   157,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   176,
     184,   192,   193,   195,   207,   209,   214,   224,   227,   229,
     231,   233,   238,   241,   243,   245,   247,   262,   268,   270,
     272,   274,   276,   295,   304,   313,   314,   315,   316,   317,
     326,   335,   344,   353,   362,   371,   380,   389,   397,   398,
     399,   400,   401,   402,   403,   404,   405,   406,   408,   423,
     432,   441,   450,   452,   461,   462,   464,   465,   467,   473,
     481,   487,   495,   501,   508,   515
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
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
  "data_value", "data_vector", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
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

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
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

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
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

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    22,    23,    24,    25,    26,    27,   144,    51,    28,
      29,    30,   164,   170,    31,   171,   178,    32,   163,   168,
      62,    33,    34,    35,    36,    37,    38
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -95
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

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -95,   -95,   -94,   -95,    55,     2,   152,   -95,   169,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -16,   110,    16,   -15,   -95,   -95
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
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

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

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

/* Line 1455 of yacc.c  */
#line 82 "wic.y"
    {
		printf("main");
	    ;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 87 "wic.y"
    {
			    ASTNode* node = reinterpret_cast<ASTNode *>((yyvsp[(1) - (2)]));
			    main_body->add_instr(node);
			  ;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 91 "wic.y"
    {wic::ASTBodyNode* body_ = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[(1) - (4)]));
					       wic::ASTNode* instr = reinterpret_cast<wic::ASTNode* >((yyvsp[(3) - (4)]));
					       body_->add_instr(instr);;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 95 "wic.y"
    {
						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[(2) - (2)]));
						    entry_d->var.global = true;
						    entry_d->var.stat = false;
						    entry_d->var.local = false;
						    (yyval) = entry_d;
						  ;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 102 "wic.y"
    {
						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[(2) - (2)]));
						    entry_d->var.global = false;
						    entry_d->var.stat = true;
						    entry_d->var.local = false;
						    (yyval) = entry_d;
    						  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 109 "wic.y"
    {
    						    wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[(1) - (1)]));
    						    entry_d->var.global = false;
    						    entry_d->var.stat = false;
    						    entry_d->var.local = true;
    						    (yyval) = entry_d;
     						  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 123 "wic.y"
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::INT;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
						  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 129 "wic.y"
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::REAL;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
						  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 135 "wic.y"
    {
						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::BOOL;
						    entry_d->var.size = 1;
						    (yyval) = entry_d;
						  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 141 "wic.y"
    {
    						    wic::entry_data* entry_d = new wic::entry_data();
    						    entry_d->var.type = wic::CHAR;
    						    entry_d->var.size = 1;
    						    (yyval) = entry_d;
    						  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 147 "wic.y"
    {
    						    wic::entry_data* entry_d = new wic::entry_data();
						    entry_d->var.type = wic::VOID;
						    entry_d->var.size = 4;
						    (yyval) = entry_d;
    						  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 154 "wic.y"
    {
						    (yyval) = ast->tree_build((yyvsp[(1) - (2)]), (yyvsp[(2) - (2)]));
						  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 157 "wic.y"
    {
    						    wic::ASTNode* id = ast->tree_build((yyvsp[(1) - (4)]), (yyvsp[(2) - (4)]));

    						    wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(4) - (4)]));
    						    wic::ASTAssignNode* assign = new wic::ASTAssignNode(id->get_data_type(), id, expr);
    						    (yyval) = ast->tree_build(assign);
    						    ast->print();
    						    std::cout << std::endl;
    						  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 166 "wic.y"
    { printf("Término (VectorVal)");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 168 "wic.y"
    {(yyval) = ((yyvsp[(1) - (1)]));;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 170 "wic.y"
    {(yyval) = ((yyvsp[(1) - (1)]));;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 171 "wic.y"
    { (yyval) = ((yyvsp[(1) - (1)])); ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 172 "wic.y"
    { (yyval) =((yyvsp[(1) - (1)])); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 176 "wic.y"
    {
        										wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[(3) - (4)]));
        										wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[(4) - (4)]));
        										id->set_data_type(entry_d->var.type);
												wic::ASTParamNode* params = reinterpret_cast<wic::ASTParamNode *>((yyvsp[(1) - (4)]));
												params->add_params(id);
												(yyval) = ast->tree_build(params);
											;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 184 "wic.y"
    {
						wic::entry_data* entry_d = reinterpret_cast<wic::entry_data *>((yyvsp[(1) - (2)]));
        				wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[(2) - (2)]));
        				id->set_data_type(entry_d->var.type);
						wic::ASTParamNode* params = new wic::ASTParamNode(id);
						(yyval) = ast->tree_build(params);
					;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 197 "wic.y"
    {
        wic::ASTNode* id = ast->tree_build((yyvsp[(2) - (14)]),(yyvsp[(3) - (14)]));
		printf("HOLA MUNDO\n");
		wic::ASTParamNode* param = reinterpret_cast<wic::ASTParamNode *>((yyvsp[(5) - (14)]));
		wic::ASTBodyNode* body = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[(10) - (14)]));
		wic::ASTIDNode* expr = reinterpret_cast<wic::ASTIDNode *>((yyvsp[(12) - (14)]));
		wic::ASTReturnNode* ret = new wic::ASTReturnNode(expr);
		wic::ASTFunctionNode* func = new wic::ASTFunctionNode(id->get_id(),id->get_data_type(),param,body,ret);
		(yyval) = ast->tree_build(func);
     ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 210 "wic.y"
    {

								;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 250 "wic.y"
    {
      		     wic::ASTRelationalNode* expr = reinterpret_cast<wic::ASTRelationalNode *>((yyvsp[(1) - (9)]));
      		     wic::ASTBodyNode* input = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[(6) - (9)]));
      		     wic::ASTIfNode* ifmid_= reinterpret_cast<wic::ASTIfNode *>((yyvsp[(8) - (9)]));
		     wic::ASTBodyNode* else_ = reinterpret_cast<wic::ASTBodyNode *>((yyvsp[(9) - (9)]));

		     wic::ASTIfNode* if_ = new wic::ASTIfNode(expr, input, else_);
		     if_->add_mid_block(ifmid_);

		     (yyval) = ast->tree_build(if_);
		   ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 263 "wic.y"
    {
        					  wic::ASTRelationalNode* expr = reinterpret_cast<wic::ASTRelationalNode *>((yyvsp[(3) - (9)]));
      						  wic::ASTBodyNode* input = reinterpret_cast<wic::ASTBodyNode* >((yyvsp[(8) - (9)]));
      						  (yyval) = new wic::ASTIfNode(expr, input);
      					       ;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 271 "wic.y"
    { (yyval) = ((yyvsp[(5) - (7)])); ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 277 "wic.y"
    {
					    wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[(1) - (3)]));

					    if (!id->is_registered()) {
						std::cout << termcolor::red << termcolor::bold
							<< "[!] Error: " << termcolor::reset << "\'" << id->get_id()
							<< "\' was not declared in this scope"
							<< std::endl;
						exit(-1);
				    	}

				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));
				    	wic::ASTAssignNode* assign = new wic::ASTAssignNode(id->get_data_type(), id, term);

				 	(yyval) = ast->tree_build(assign);
					lst->show(id->get_id());

			  	;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 296 "wic.y"
    {
				    	wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

				    	wic::ASTSumNode* sum = new wic::ASTSumNode(expr, term);
				 	sum->to_code(cg);
				    	(yyval) = ast->tree_build(sum);
				;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 305 "wic.y"
    {
                                	wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
                                        wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

                                        wic::ASTSubNode* sub = new wic::ASTSubNode(expr, term);

                                        (yyval) = ast->tree_build(sub);
			  	;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 318 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTLessNode* less = new wic::ASTLessNode(expr, term);

 					(yyval) = ast->tree_build(less);
 				;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 327 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTLessEqualNode* less_equal = new wic::ASTLessEqualNode(expr, term);

 					(yyval) = ast->tree_build(less_equal);
 				;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 336 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTGreaterNode* greater = new wic::ASTGreaterNode(expr, term);

 					(yyval) = ast->tree_build(greater);
 				;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 345 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTGreaterEqualNode* greater_equal = new wic::ASTGreaterEqualNode(expr, term);

 					(yyval) = ast->tree_build(greater_equal);
 				;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 354 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTEqualNode* equal = new wic::ASTEqualNode(expr, term);

 					(yyval) = ast->tree_build(equal);
 				;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 363 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTNotEqualNode* not_equal = new wic::ASTNotEqualNode(expr, term);

 					(yyval) = ast->tree_build(not_equal);
 				;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 372 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTAndNode* and_ = new wic::ASTAndNode(expr, term);

 					(yyval) = ast->tree_build(and_);
 				;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 381 "wic.y"
    {
 					wic::ASTNode* expr = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

 					wic::ASTOrNode* or_ = new wic::ASTOrNode(expr, term);

 					(yyval) = ast->tree_build(or_);
 				;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 390 "wic.y"
    {
 					wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(2) - (2)]));

 					wic::ASTNotNode* not_ = new wic::ASTNotNode(term);

 					(yyval) = ast->tree_build(not_);
 				;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 405 "wic.y"
    { (yyval) = ((yyvsp[(1) - (1)])); ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 409 "wic.y"
    {
				    	wic::ASTIDNode* id = reinterpret_cast<wic::ASTIDNode *>((yyvsp[(1) - (1)]));
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
			  	;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 424 "wic.y"
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

				    	wic::ASTProdNode* prod = new wic::ASTProdNode(term, power);

				    	(yyval) = ast->tree_build(prod);
			  	;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 433 "wic.y"
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

				    	wic::ASTDivNode* div = new wic::ASTDivNode(term, power);

				    	(yyval) = ast->tree_build(div);
			  	;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 442 "wic.y"
    {
				    	wic::ASTNode* term = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

				    	wic::ASTModNode* mod = new wic::ASTModNode(term, power);

				    	(yyval) = ast->tree_build(mod);
			  	;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 453 "wic.y"
    {
				    	wic::ASTNode* power = reinterpret_cast<wic::ASTNode *>((yyvsp[(1) - (3)]));
				    	wic::ASTNode* factor = reinterpret_cast<wic::ASTNode *>((yyvsp[(3) - (3)]));

				    	wic::ASTRadicalNode* radical = new wic::ASTRadicalNode(power, factor);

				    	(yyval) = ast->tree_build(radical);
			  	;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 468 "wic.y"
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(1) - (1)]));
				    	std::cout << "Factor : INT(value=" << node->get_data_value().int_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 474 "wic.y"
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(2) - (2)]));
				    	int val = -node->get_data_value().int_val;
				    	node->set_data_value((void*)&val);
				    	std::cout << "Factor: NEG_INT(value=" << node->get_data_value().int_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 482 "wic.y"
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(1) - (1)]));
				    	std::cout << "Factor : REAL(value=" << node->get_data_value().real_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 488 "wic.y"
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(2) - (2)]));
				    	float val = -node->get_data_value().real_val;
				    	node->set_data_value((void*)&val);
				    	std::cout << "Factor: NEG_REAL(value=" << node->get_data_value().real_val << ")" << std::endl;
					(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 496 "wic.y"
    {
			    		wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(1) - (1)]));
				    	std::cout << "Factor : BOOL(value=" << node->get_data_value().bool_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
				;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 502 "wic.y"
    {
				    	wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(2) - (3)]));
				    	std::cout << "Factor : CHAR(value=" << node->get_data_value().char_val << ",ascii="
					    << (int)node->get_data_value().char_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 509 "wic.y"
    {
			    		wic::ASTLeafNode* node = reinterpret_cast<wic::ASTLeafNode *>((yyvsp[(2) - (3)]));
				    	std::cout << "Factor : STRING(value=" << node->get_data_value().str_val << ")" << std::endl;
				    	(yyval) = reinterpret_cast<void *>(node);
			  	;}
    break;



/* Line 1455 of yacc.c  */
#line 2275 "wic.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 517 "wic.y"



