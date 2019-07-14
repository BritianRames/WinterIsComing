%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
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
%token <number> ELSE_CLAUSE
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
%token <number> QUOTE
%token <string> ID
%token <number> PRINT



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


%start begin
%%

begin : {printf("Welcome to wic\n");} root
      ;


root : declaration END_OF_INSTRUCTION root
     | assignation END_OF_INSTRUCTION root
     | function root
     | END_OF_INSTRUCTION root
     | /* EMPTY */
     ;

declaration : INT_TYPE ID {printf("DECLARACION VARIABLE\n");/*insertVariable($<string>2);*/}
            ;

function : FUN ID {printf("COMIENZA FUNCION \n");/*insertFunction($<string>2);*/} PARENTESIS_OPEN {/*openScope();*/} params {/*closeScope();*/} PARENTESIS_CLOSE {/*openScope();*/} CURLY_BRACKET_OPEN END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE END_OF_INSTRUCTION {printf("FINALIZA FUN\n");/*closingScope();*/} 
         ;

params : INT_TYPE ID params {printf("DECLARACION PARAMETROS\n");/*insertVariable($<string>2);*/}
       | COMMA INT_TYPE ID params
       | /* EMPTY */
       ;

codeSet : instruction END_OF_INSTRUCTION codeSet
        | controlStructure codeSet
        | END_OF_INSTRUCTION codeSet
        | /* EMPTY */
        ;

instruction : assignation 
            | declaration 
            | aritmeticOperation
            | return 
            | print 
            | BREAK {/*breakCode();*/}
            ;

assignation : ID ASSIGN INT_VAL {printf("ASIGNACION VALOR\n");/*generateAssignStaticValueToVariableCode($<string>1,$<number>3);*/}
            | ID ASSIGN ID  {printf("ASIGNACION VARIABLE\n");/*generateAssignStaticVriableToVariableCode($<string>1,$<string>3);*/}
            | ID ASSIGN ID PARENTESIS_OPEN {printf("ASIGNACION LLAMADA FUNCION\n");/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE 
            | ID ASSIGN aritmeticOperation
            ;  

functionCallParams : INT_VAL {printf("PARAMETRO ENTERO\n");/*setParamsValue($<number>1);*/}
                   | ID {printf("PARAMETRO VARIABLE\n");/*setParamsValueFromVariable($<string>1);*/}
                   | INT_VAL COMMA functionCallParams {printf("PARAMETRO ENTERO COMMA\n");/*setParamsValue($<number>1);*/}
                   | ID COMMA functionCallParams {printf("PARAMETRO VARIABLE COMMA\n");/*setParamsValueFromVariable($<string>1);*/}

aritmeticOperation : aritmeticOperation SUBSTRACT aritmeticOperation {/*$$ = substract($<number>1,$<number>3);*/}
            | aritmeticOperation SUM aritmeticOperation {/*$$ = add($<number>1,$<number>3);*/}
            | aritmeticOperation PRODUCT aritmeticOperation {/*$$ = multiply($<number>1, $<number>3);*/}
            | aritmeticOperation DIVIDE aritmeticOperation {/*$$ = divide($<number>1, $<number>3);*/}
            | PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE {$$ = $<number>2;}
            | INT_VAL {$$ = $<number>1;}
            | ID 
            ;

return : RETURN ID {/*returnVariable($<number>2);*/}
       | RETURN INT_VAL {/*returnValue($<number>2);*/}
       | RETURN aritmeticOperation {/*returnValue($<number>2);*/}
       | RETURN ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE {printf("TERMINA LLAMADA FUNCION\n");}
       ; 

print : PRINT PARENTESIS_OPEN printableElement PARENTESIS_CLOSE 
      ; 

printableElement : ID {/*printVariable($<number>1);*/}
                 | QUOTE text QUOTE {/*printText($<number>1);*/}
                 | printableElement SUM printableElement {/*printLineJump();*/}
                 ;

text : STRING_VAL {$$ = $<number>1;}
     | ' '  {$$ = $<number>1;}
     ;

controlStructure : IF_CLAUSE PARENTESIS_OPEN {/*openScope();*/} logicalOperation {/*closingScope();*/} PARENTESIS_CLOSE  CURLY_BRACKET_OPEN {/*openScope();*/} END_OF_INSTRUCTION codeSet {/*closingScope();*/} CURLY_BRACKET_CLOSE ELSE_CLAUSE CURLY_BRACKET_OPEN codeSet CURLY_BRACKET_CLOSE {printf("ESTRUCTURA CONTROL ELSE_CLAUSE TERMINADA");}
                 | structuresWord PARENTESIS_OPEN {/*openScope();*/} logicalOperation {/*closingScope();*/} PARENTESIS_CLOSE  CURLY_BRACKET_OPEN {/*openScope();*/} END_OF_INSTRUCTION codeSet {/*closingScope();*/} CURLY_BRACKET_CLOSE {printf("ESTRUCTURA CONTROL TERMINADA");}
                 ;

structuresWord : IF_CLAUSE {/*startIf();*/}
               | WHILE_CLAUSE {/*startWhile();*/}
               ;

logicalOperation : ID logicalOperator ID {/*logicalOperate(($<number>1),($<number>3),($<string>1));*/}
                 | ID logicalOperator INT_VAL {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 | INT_VAL logicalOperator INT_VAL {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 | INT_VAL logicalOperator ID {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 ;

logicalOperator : EQUALS {/*$$ = "eq";*/}
                | NOT_EQUALS {/*$$ = "neq";*/}
                | GREATER {/*$$ = "gt";*/}
                | LESS {/*$$ = "mt";*/}
                | GREATER_EQUALS {/*$$ = "ge";*/}
                | LESS_EQUALS {/*$$ = "me";*/}
                ;

%%

int main(int argc, char** argv) {
  if (argc>1) yyin=fopen(argv[1],"r");
  yyparse();
}


void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

