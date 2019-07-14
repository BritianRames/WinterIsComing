%{
  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  #include <stdbool.h>
  #include "../symbol-table/SymbolTableManager.h"
  

  extern FILE *yyin;
  extern int numlin;
  int yydebug = 1;
  void yyerror (char const*);
  char* stringWithNewline(char*);
  void printTree();
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

begin : {printf("Welcome to wic");} root
      ;


root : {printTreeElement("root");} declaration root
     | {printTreeElement("root");} assignation root
     | {printTreeElement("root");} function root 
     | {printTreeElement("root");} END_OF_INSTRUCTION root
     | /* EMPTY */
     ;

declaration : {printTreeElement("declaration");} INT_TYPE ID END_OF_INSTRUCTION {/*insertVariable($<string>2);*/}
            ;

function : {printTreeElement("function");} FUN ID {/*insertFunction($<string>2);*/} PARENTESIS_OPEN {/*openScope();*/} params {/*closeScope();*/} PARENTESIS_CLOSE {/*openScope();*/} CURLY_BRACKET_OPEN END_OF_INSTRUCTION OPEN_CONTEXT_TAG codeSet CLOSE_CONTEXT_TAG CURLY_BRACKET_CLOSE {/*closingScope();*/} 
         ;

params : {printTreeElement("params");} INT_TYPE ID params {/*insertVariable($<string>2);*/}
       | {printTreeElement("params");} COMMA INT_TYPE ID params 
       | {printTreeElement("params");} /* EMPTY */
       ;

codeSet : {printTreeElement("codeSet");} declaration codeSet
        | {printTreeElement("codeSet");} instruction codeSet
        | {printTreeElement("codeSet");} controlStructure codeSet
        | {printTreeElement("codeSet");} declaration
        | {printTreeElement("codeSet");} instruction
        | {printTreeElement("codeSet");} controlStructure
        ;

instruction : {printTreeElement("instruction");} assignation 
            | {printTreeElement("instruction");} aritmeticOperation END_OF_INSTRUCTION
            | {printTreeElement("instruction");} return END_OF_INSTRUCTION
            | {printTreeElement("instruction");} print END_OF_INSTRUCTION
            | {printTreeElement("instruction");} BREAK END_OF_INSTRUCTION{/*breakCode();*/}
            ;

assignation : {printTreeElement("assignation");} ID '=' INT_VAL END_OF_INSTRUCTION{/*generateAssignStaticValueToVariableCode($<string>1,$<number>3);*/}
            | {printTreeElement("assignation");} ID '=' ID END_OF_INSTRUCTION {/*generateAssignStaticVriableToVariableCode($<string>1,$<string>3);*/} 
            | {printTreeElement("assignation");} ID '=' ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE END_OF_INSTRUCTION 
            ;  

functionCallParams : {printTreeElement("functionCallParams");} INT_VAL {/*setParamsValue($<number>1);*/} 
                   | {printTreeElement("functionCallParams");} ID {/*setParamsValueFromVariable($<string>1);*/}
                   | {printTreeElement("functionCallParams");} INT_VAL COMMA functionCallParams {/*setParamsValue($<number>1);*/} 
                   | {printTreeElement("functionCallParams");} ID COMMA functionCallParams {/*setParamsValueFromVariable($<string>1);*/}

aritmeticOperation : {printTreeElement("aritmeticOperation");} aritmeticOperation '-' aritmeticOperation {/*$$ = substract($<number>1,$<number>3);*/}
            | {printTreeElement("aritmeticOperation");} aritmeticOperation '+' aritmeticOperation {/*$$ = add($<number>1,$<number>3);*/}
            | {printTreeElement("aritmeticOperation");} aritmeticOperation '*' aritmeticOperation {/*$$ = multiply($<number>1, $<number>3);*/}
            | {printTreeElement("aritmeticOperation");} aritmeticOperation '/' aritmeticOperation {/*$$ = divide($<number>1, $<number>3);*/}
            | {printTreeElement("aritmeticOperation");} PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE {/*$$ = $<number>2;*/}
            | {printTreeElement("aritmeticOperation");} INT_VAL {/*$$ = $<number>1;*/}
            ;

return : {printTreeElement("return");} RETURN ID {/*returnVariable($<number>2);*/}
       | {printTreeElement("return");} RETURN INT_VAL {/*returnValue($<number>2);*/}
       | {printTreeElement("return");} RETURN aritmeticOperation {/*returnValue($<number>2);*/}
       | {printTreeElement("return");} RETURN ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE END_OF_INSTRUCTION
       ; 

print : {printTreeElement("print");} PRINT PARENTESIS_OPEN printableElement PARENTESIS_CLOSE
      ; 

printableElement : {printTreeElement("printableElement");} ID {/*printVariable($<number>1);*/}
                 | {printTreeElement("printableElement");} QUOTE text QUOTE {/*printText($<number>1);*/}
                 | {printTreeElement("printableElement");} printableElement '+' printableElement {/*printLineJump();*/}
                 ;

text : {printTreeElement("text")} STRING_VAL {/*$$ = $<number>1;*/}
     | {printTreeElement("text")} ' ' {/*$$ = $<number>1;*/}
     ;

controlStructure : {printTreeElement("controlStructure")} structuresWord PARENTESIS_OPEN {/*openScope();*/} logicalOperation {/*closingScope();*/} PARENTESIS_CLOSE  CURLY_BRACKET_OPEN {/*openScope();*/} OPEN_CONTEXT_TAG codeSet {/*closingScope();*/} CLOSE_CONTEXT_TAG CURLY_BRACKET_CLOSE
                 ;

structuresWord : {printTreeElement("structuresWord")} IF_CLAUSE {/*startIf();*/}
               | {printTreeElement("structuresWord")} WHILE_CLAUSE {/*startWhile();*/}
               ;

logicalOperation : {printTreeElement("logicalOperation");} ID logicalOperator ID {/*logicalOperate(($<number>1),($<number>3),($<string>1));*/}
                 | {printTreeElement("logicalOperation");} ID logicalOperator INT_VAL {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 | {printTreeElement("logicalOperation");} INT_VAL logicalOperator INT_VAL  {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 | {printTreeElement("logicalOperation");} INT_VAL logicalOperator ID  {/*logicalOperate(($<number>1),($<number>3),($<string>1))*/}
                 ;

logicalOperator : {printTreeElement("logicalOperator");} EQUALS {$$ = "eq";}
                | {printTreeElement("logicalOperator");} NOT_EQUALS {$$ = "neq";}
                | {printTreeElement("logicalOperator");} GREATER {$$ = "gt";}
                | {printTreeElement("logicalOperator");} LESS {$$ = "mt";}
                | {printTreeElement("logicalOperator");} GREATER_EQUALS {$$ = "ge";}
                | {printTreeElement("logicalOperator");} LESS_EQUALS {$$ = "me";}
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

void printTreeElement(char* name){
  for(int i = 0, i < getCurrentScopeFromSymbolTable(); i++){
    printf("+");
  }
  printf("%s\n", name);
}
