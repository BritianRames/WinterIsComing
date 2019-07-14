/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    PRINT = 296
  };
#endif
/* Tokens.  */
#define CONTINUE 258
#define BREAK 259
#define RETURN 260
#define FUN 261
#define INT_VAL 262
#define STRING_VAL 263
#define INT_TYPE 264
#define STRING_TYPE 265
#define ASSIGN 266
#define SUM 267
#define SUBSTRACT 268
#define PRODUCT 269
#define DIVIDE 270
#define AND 271
#define OR 272
#define NOT 273
#define EQUALS 274
#define NOT_EQUALS 275
#define GREATER 276
#define GREATER_EQUALS 277
#define LESS 278
#define LESS_EQUALS 279
#define IF_CLAUSE 280
#define WHILE_CLAUSE 281
#define ELSE_CLAUSE 282
#define HEADER_END 283
#define SQUARE_BRACKET_OPEN 284
#define SQUARE_BRACKET_CLOSE 285
#define CURLY_BRACKET_OPEN 286
#define CURLY_BRACKET_CLOSE 287
#define COMMA 288
#define PARENTESIS_OPEN 289
#define PARENTESIS_CLOSE 290
#define END_OF_INSTRUCTION 291
#define OPEN_CONTEXT_TAG 292
#define CLOSE_CONTEXT_TAG 293
#define QUOTE 294
#define ID 295
#define PRINT 296

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 13 "bwic.y" /* yacc.c:1909  */
 int number; char* string; 

#line 139 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
