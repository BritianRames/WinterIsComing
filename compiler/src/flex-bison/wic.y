%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include "../symbol-table/SymbolTableManager.h"
  #include "../code-generator/CodeGeneratorManager.h"
  extern FILE *yyin;
  extern int numlin;
  int yydebug = 1;
  void yyerror (char const*);
  char* stringWithNewline(char*);
%}

%union { int number; char* string; }
//////////NOTA PARA TODO EL MUNDO (FUTURO) - > CREO QUE AL FINAL DE UNA INSTRUCCION QUE LE SIGUE UN CLOSE CONTEXT TAG, NO SE IMPRIME END_OF_INSTRUCTION
%token <number> CONTINUE
%token <number> BREAK
%token <number> RETURN
%token <number> FUN
%token <number> INT_VAL
%token <string> STRING_VAL
%token <number> INT_TYPE
%token <number> STRING_TYPE //TODO
%token <number> ASSIGN
%token <number> SUM
%token <number> SUBSTRACT
%token <number> PRODUCT
%token <number> DIVIDE
%token <number> AND
%token <number> OR
%token <number> NOT
%token <number> EQUALS
%token <number> NOT_EQUALS
%token <number> GREATER
%token <number> GREATER_EQUALS
%token <number> LESS
%token <number> LESS_EQUALS
%token <number> IF_CLAUSE
%token <number> WHILE_CLAUSE //RETOCAR EN EL LEXICO
%token <number> HEADER_END
%token <number> SQUARE_BRACKET_OPEN
%token <number> SQUARE_BRACKET_CLOSE
%token <number> CURLY_BRACKET_OPEN
%token <number> CURLY_BRACKET_CLOSE
%token <number> COMMA // RETOCAR FLEX
%token <number> PARENTESIS_OPEN
%token <number> PARENTESIS_CLOSE
%token <number> END_OF_INSTRUCTION
%token <number> OPEN_CONTEXT_TAG
%token <number> CLOSE_CONTEXT_TAG
%token <number> STRING_QUOTE
%token <string> ID
%token <string> ID

%type <number> begin
%type <number> root
%type <number> declaration
%type <number> function
%type <number> params
%type <number> codeSet
%type <number> instruction
%type <number> assignation
%type <number> functionCallParams
%type <number> aritmeticOperation
%type <number> return
%type <number> print
%type <number> printableElement
%type <number> text
%type <number> controlStructure
%type <number> structuresWord
%type <number> logicalOperation
%type <number> logicalOperator

%type <number> begin
%start begin
%%

begin : {printf("Welcome to wic");} root
      ;


root : declaration 
     | function
     ;

declaration : INT_TYPE ID END_OF_INSTRUCTION {insertVariableInSymbolTable($<string>2);}
            ;

function : FUN ID {insertFunctionInSymbolTable($<string>2);} PARENTESIS_OPEN {openScopeInSymbolTable();} params {closeScopeInSymbolTable();} PARENTESIS_CLOSE {openScopeInSymbolTable();} HEADER_END END_OF_INSTRUCTION OPEN_CONTEXT_TAG codeSet CLOSE_CONTEXT_TAG {closeScopeInSymbolTable();} 
         ;

params : INT_TYPE ID params {insertVariableInSymbolTable($<string>2);}
       | COMMA INT_TYPE ID params
       | ''
       ;

codeSet : declaration codeSet
        | instruction codeSet
        | controlStructure codeSet
        | declaration
        | instruction
        | controlStructure
        ;

instruction : assignation
            | aritmeticOperation END_OF_INSTRUCTION
            | return END_OF_INSTRUCTION
            | print END_OF_INSTRUCTION
            | BREAK END_OF_INSTRUCTION{generateBreak();}
            | CONTINUE END_OF_INSTRUCTION{generateContinue();}
            ;

assignation : ID '=' INT_VAL END_OF_INSTRUCTION{generateAssignStaticValueToVariableCode($<string>1,$<number>3);}
            | ID '=' ID END_OF_INSTRUCTION {generateAssignStaticVriableToVariableCode($<string>1,$<string>3);}
            | ID '=' ID PARENTESIS_OPEN functionCallParams PARENTESIS_CLOSE END_OF_INSTRUCTION {generateFunctionCall($<string>1,$<string>3);}
            ;  

functionCallParams : INT_VAL {generateSaveValueParam($<number>1);}
                   | ID {generateSaveVariableParam($<string>1);}
                   | INT_VAL COMMA {generateSaveValueParam($<number>1);} functionCallParams
                   | ID COMMA {generateSaveVariableParam($<string>1);} functionCallParams

aritmeticOperation : aritmeticOperation '-' aritmeticOperation {$$ = generateSubstract($<number>1,$<number>3);}
            | aritmeticOperation '+' aritmeticOperation {$$ = generateAdd($<number>1,$<number>3);}
            | aritmeticOperation '*' aritmeticOperation {$$ = generateMultiply($<number>1, $<number>3);}
            | aritmeticOperation '/' aritmeticOperation {$$ = generateDivide($<number>1, $<number>3);}
            | PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE {$$ = $<number>2;}
            | INT_VAL {$$ = $<number>1;}
            ;

return : RETURN ID {generateReturnVariable($<number>2);}
       | RETURN INT_VAL {generateReturnValue($<number>2);}
       | RETURN aritmeticOperation {generateReturnValue($<number>2);}
       | RETURN ID PARENTESIS_OPEN {generateFunctionCall($<string>1,$<string>3);} functionCallParams PARENTESIS_CLOSE END_OF_INSTRUCTION
       ; 

print : PRINT PARENTESIS_OPEN printableElement PARENTESIS_CLOSE 
      ; 

printableElement : ID {generatePrintVariable($<number>1);)}
                 | QUOTE text QUOTE {generatePrintString(($<number>2);)}
                 | printableElement '+' printableElement {generatePrintLineJump();}
                 ;

text : STRING_VAL {$$ = $<string>1;}
     | ' '  {$$ = $<string>1;}
     ;

controlStructure : structuresWord PARENTESIS_OPEN {openScopeInSymbolTable();} logicalOperation {closeScopeInSymbolTable();} PARENTESIS_CLOSE CURLY_BRACKET_OPEN {openScopeInSymbolTable();} codeSet {closeScopeInSymbolTable();} CLOSINGCURLYBRACKET
                 ;

structuresWord : IF {generateIfHeader();}
               | ELSE {generateIfMiddle();}
               | WHILE {generateWhileHeader();}
               ;

logicalOperation : ID EQUALS ID {generateEquals(0,1,($<string>1),($<string>3));}
                 | ID EQUALS INT_VAL {generateEquals(0,1,($<string>1),($<number>3));}
                 | INT_VAL EQUALS INT_VAL {generateEquals(0,1,($<number>1),($<number>3));}
                 | INT_VAL EQUALS ID {generateEquals(0,1,($<number>1),($<string>3));}
				 | ID NOT_EQUALS ID {generateNotEquals(0,1,($<string>1),($<string>3));}
                 | ID NOT_EQUALS INT_VAL {generateNotEquals(0,1,($<string>1),($<number>3));}
                 | INT_VAL NOT_EQUALS INT_VAL {generateNotEquals(0,1,($<number>1),($<number>3));}
                 | INT_VAL NOT_EQUALS ID {generateNotEquals(0,1,($<number>1),($<string>3));}
				 | ID GREATER ID {generateGreater(0,1,($<string>1),($<string>3));}
                 | ID GREATER INT_VAL {generateGreater(0,1,($<string>1),($<number>3));}
                 | INT_VAL GREATER INT_VAL {generateGreater(0,1,($<number>1),($<number>3));}
                 | INT_VAL GREATER ID {generateGreater(0,1,($<number>1),($<string>3));}
				 | ID LESS ID {generateLess(0,1,($<string>1),($<string>3));}
                 | ID LESS INT_VAL {generateLess(0,1,($<string>1),($<number>3));}
                 | INT_VAL LESS INT_VAL {generateLess(0,1,($<number>1),($<number>3));}
                 | INT_VAL LESS ID {generateLess(0,1,($<number>1),($<string>3));}
				 | ID GREATER_EQUALS ID {generateGreaterEquals(0,1,($<string>1),($<string>3));}
                 | ID GREATER_EQUALS INT_VAL {generateGreaterEquals(0,1,($<string>1),($<number>3));}
                 | INT_VAL GREATER_EQUALS INT_VAL {generateGreaterEquals(0,1,($<number>1),($<number>3));}
                 | INT_VAL GREATER_EQUALS ID {generateGreaterEquals(0,1,($<number>1),($<string>3));}
				 | ID LESS_EQUALS ID {generateLessEquals(0,1,($<string>1),($<string>3));}
                 | ID LESS_EQUALS INT_VAL {generateLessEquals(0,1,($<string>1),($<number>3));}
                 | INT_VAL LESS_EQUALS INT_VAL {generateLessEquals(0,1,($<number>1),($<number>3));}
                 | INT_VAL LESS_EQUALS ID {generateLessEquals(0,1,($<number>1),($<string>3));}
                 ;

%%

int main(int argc, char** argv) {
  printf("Hola");
  if (argc>1) yyin=fopen(argv[1],"r");
  yyparse();
}


void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}
