%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include "../SymbolTable/symbolTable.h"
  extern FILE *yyin;
  extern int numlin;
  int yydebug = 1;
  void yyerror (char const*);
  char* stringWithNewline(char*);
%}

%union { int entero; char* string; }

%token <entero> ENTERO
%token <string> VARIABLE
%token <entero> VAR
%token <entero> ASIGN
%token <string> STRING
%token <entero> INT
%token <entero> FUNC
%token <string> FUNCNAME
%token <entero> WHILE
%token <entero> EQUAL
%token <entero> NOTEQUAL
%token <entero> WHEN
%token <entero> RETURN
%token <entero> PRINTLN
%token <entero> STRINGLITERAL
%token <entero> OPENCURLYBRACKET
%token <entero> CLOSECURLYBRACKET
%token <entero> OPENBRACKET
%token <entero> CLOSEBRACKET
%token <entero> ELSE
%token <entero> COLON
%token <entero> COMMA
%token <entero> BREAK
%token <entero> GREATEREQUAL
%token <entero> SMALLEREQUAL

%type <entero> exp
%type <entero> local
%type <entero> staticVars
%type <entero> statement
%type <entero> parameterList
%type <entero> functionParameters
%type <entero> functionWrap
%type <entero> function
%type <entero> functionHead
%type <entero> while
%type <entero> condition
%type <entero> when
%type <entero> block
%type <entero> inBlockStatement
%type <entero> functionCall
%type <entero> functionCallParameters
%type <entero> functionCallParameterList
%type <entero> return
%type <entero> statementList
%type <entero> println
%type <entero> stringLiteral

%left '<' '>' EQUAL NOTEQUAL
%left '-' '+'
%left '*' '/'

%%

begin : {
          printf("BEGIN\nL 0:\n\tR6 = R7;\n"); 
          printf("STAT(%d)\n", getStatSectionNumber()); 
          printf("\tSTR(%d, \"%%d\\n\");\n", 
          getStaticAddress()); 
          printf("CODE(%d)\n", getCodeSectionNumber());
        } 
        lista 
        {
          printf("\tGT(-2);\nEND\n");
        }
      ;

lista : statement lista
      | staticVars lista
      | functionWrap '\n' lista
      | error '\n' {printf(" en expresion\n");} lista
      |
      ;

staticVars : VAR VARIABLE ASIGN exp {printf("STAT(%d)\n", getStatSectionNumber());} '\n' { 
                insertVariable($<string>2, getStaticAddress()); printf("\tMEM(%d, 4);\n", 
                search($<string>2)->address); printf("CODE(%d)\n", getCodeSectionNumber()); 
                printf("\tI(%d) = R%d;\n", search($<string>2)->address, $<entero>4); freeRegister($<entero>4);
              }
           | VARIABLE ASIGN exp '\n' { printf("\tI(%d) = R%d;\n", search($<string>1)->address, $<entero>3); freeRegister($<entero>3);}
           ;

statement : while '\n'
          | when '\n'
          | functionCall '\n' {}
          | println '\n'
          | '\n' {}
          ;

statementList : statement statementList
              | local statementList
              | {}
              ;

local : VAR VARIABLE ASIGN exp '\n' {$<entero>$ = getRelativeAddress(); insertVariable($<string>2, $<entero>$); printf("\tR7 = R7 - 4;\n\tI(R6 - %d) = R%d;\n", $<entero>$, $<entero>4); freeRegister($<entero>4); }
      | VARIABLE ASIGN exp '\n' {writeCodeForVariableWrite($<entero>3, $<string>1); freeRegister($<entero>3);}
      ;

exp : exp '+' exp                     {printf("\tR%d = R%d + R%d;\n", $<entero>1, $<entero>1 ,$<entero>3); freeRegister($<entero>3);}
    | exp '-' exp                     {printf("\tR%d = R%d - R%d;\n", $<entero>1, $<entero>1 ,$<entero>3); freeRegister($<entero>3);}
    | exp '*' exp                     {printf("\tR%d = R%d * R%d;\n", $<entero>1, $<entero>1 ,$<entero>3); freeRegister($<entero>3);}
    | exp '/' exp                     {printf("\tR%d = R%d / R%d;\n", $<entero>1, $<entero>1 ,$<entero>3); freeRegister($<entero>3);}
    | OPENBRACKET exp CLOSEBRACKET    {$$ = $2;}
    | ENTERO                          {$<entero>$ = getRegister(); printf("\tR%d = %d;\n", $$, $1)}
    | VARIABLE                        {$$ = getRegister(); writeCodeForVariableRead($<entero>$, $<string>1)}
    | functionCall                    {$$ = getRegister(); printf("\tR%d = R5;\n", $$)}
    ;

functionWrap : {$<entero>$ = getLabel(); printf("\tGT(%d);\n", $<entero>$);} function {int reg = getRegister(); printf("\tR7 = R6;\n\tR6 = I(R7 + 4);\n\tR%d = I(R7);\n\tGT(R%d);\n", reg, reg); printf("L %d:\n", $<entero>1); freeRegister(reg);}

function : functionHead COLON INT OPENCURLYBRACKET '\n' {openScope();} statementList return {closeScope();} CLOSECURLYBRACKET
         | functionHead OPENCURLYBRACKET '\n' {openScope();} statementList {closeScope();} CLOSECURLYBRACKET
         | FUNC FUNCNAME {int label = getLabel(); insertFunction($<string>2, label); printf("L %d:\n\tR6 = R7;\n", label)} OPENCURLYBRACKET '\n' {openScope();} statementList {closeScope();} CLOSECURLYBRACKET
         ;

functionHead : FUNC FUNCNAME {int label = getLabel(); insertFunction($<string>2, label); printf("L %d:\n\tR6 = R7;\n", label)} OPENBRACKET functionParameters CLOSEBRACKET
             ;

functionParameters : parameterList
                   | {}
                   ;

parameterList : VARIABLE COLON INT COMMA parameterList {insertParameter($<string>1, $<entero>5); $$ = $<entero>5 + 4}
              | VARIABLE COLON INT {insertParameter($<string>1, 8); $$ = 12}
              ;

while : {$<entero>$ = getLabel();} {$<entero>$ = getLabel(); openLoop($<entero>$); printf("L %d:\n", $<entero>1);}  WHILE block {printf("\tGT(%d);\n", $<entero>1); printf("L %d:\n", $<entero>2);}

when : {$<entero>$ = getLabel();} {$<entero>$ = getLabel();} WHEN block {printf("\tGT(%d);\n", $<entero>1);} {printf("L %d:\n", $<entero>2);} elseBlock {printf("L %d:\n", $<entero>1);}
     ;

block : OPENBRACKET condition CLOSEBRACKET {printf("\tIF(!R%d) GT(%d);\n", $<entero>2, $<entero>-1); freeRegister($<entero>2)} OPENCURLYBRACKET {openScope();} '\n' inBlockStatement CLOSECURLYBRACKET {$<entero>$ = closeScope(); printf("\tR7 = R7 + %d;\n", $<entero>$);}
      ;

elseBlock : ELSE OPENCURLYBRACKET {openScope();} '\n' inBlockStatement CLOSECURLYBRACKET {$<entero>$ = closeScope(); printf("\tR7 = R7 + %d;\n", $<entero>$);}
          |
          ;

condition : exp EQUAL exp {printf("\tR%d = R%d == R%d;\n", $1, $1, $3); freeRegister($3);}
          | exp NOTEQUAL exp {printf("\tR%d = R%d != R%d;\n", $1, $1, $3); freeRegister($3);}
          | exp '<' exp {printf("\tR%d = R%d < R%d;\n", $1, $1, $3); freeRegister($3);}
          | exp '>' exp {printf("\tR%d = R%d > R%d;\n", $1, $1, $3); freeRegister($3);}
          | exp GREATEREQUAL exp {printf("\tR%d = R%d >= R%d;\n", $1, $1, $3); freeRegister($3);}
          | exp SMALLEREQUAL exp {printf("\tR%d = R%d <= R%d;\n", $1, $1, $3); freeRegister($3);}
          ;

inBlockStatement : statementList
                 | statementList return
                 | statementList BREAK {printf("\tR7 = R7 + %d;\n\tGT(%d)\n", getStackSpaceToRecoverOnBreak(), getMostInnerLoop());} statementList
                 ;

return : RETURN exp  '\n' {printf("\tR5 = R%d;\n", $<entero>2); printf("\tR7 = R6;\n\tR6 = I(R7 + 4);\n\tR%d = I(R7);\n\tGT(R%d);\n", $<entero>2, $<entero>2); freeRegister($<entero>2);}
       ;

functionCall : FUNCNAME OPENBRACKET {$<entero>$ = parameterSpace($<string>1) + 8; printf("\tR7 = R7 - %d;\n", $<entero>$ + 20); saveRegisters($<entero>$);} functionCallParameters CLOSEBRACKET {$<entero>$ = getLabel(); printf("\tI(R7 + 4) = R6;\n\tI(R7) = %d;\n\tGT(%d);\nL %d:\n", $<entero>$, search($<string>1)->label, $<entero>$); recoverRegisters($<entero>3); printf("\tR7 = R7 + %d;\n", $<entero>3 + 20);}

functionCallParameters : functionCallParameterList
                       | {}
                       ;

functionCallParameterList : exp COMMA functionCallParameterList {printf("\tI(R7 + %d) = R%d;\n", $<entero>3, $<entero>1); $$ = $<entero>3 + 4; freeRegister($<entero>1);}
                          | exp {printf("\tI(R7 + %d) = R%d;\n", 8, $<entero>1); $$ = 12; freeRegister($<entero>1);}
                          ;

println: PRINTLN OPENBRACKET {saveRegisters(8);} exp {$<entero>$ = getLabel();} {freeRegister($<entero>4);} CLOSEBRACKET {printf("\tR3 = R%d;\n\tR0 = %d;\n\tR1 = 73724;\n\tR2 = R3;\n\tGT(-12);\nL %d:\n", $<entero>4, $<entero>5, $<entero>5); recoverRegisters(8);}
       | PRINTLN OPENBRACKET {saveRegisters(8);} stringLiteral {$<entero>$ = getLabel();} CLOSEBRACKET {printf("\tR0 = %d;\n\tR1 = %d;\n\tGT(-12);\nL %d:\n", $<entero>5, $<entero>4, $<entero>5); recoverRegisters(8);}
       ;

stringLiteral : STRINGLITERAL {$<entero>$ = getStaticAddressForString($<string>1); printf("STAT(%d)\n", getStatSectionNumber()); printf("\tSTR(%d, %s);\n", $<entero>$, stringWithNewline($<string>1)); printf("CODE(%d)\n", getCodeSectionNumber());} {$$ = $<entero>2;}

%%

int main(int argc, char** argv) {
  if (argc>1) yyin=fopen(argv[1],"r");
  yyparse();
}

void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

char* stringWithNewline(char* string) {
  char* result = malloc(strlen(string) - 1);
  result = strncpy(result, string, strlen(string) - 1);
  result = strcat(result, "\\n");
  result = strcat(result, "\"");
  return result;
}
