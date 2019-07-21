%{
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
%token <number> PLUSPLUS
%token <number> MINUSMINUS



%type <number> root
%type <number> declaration
%type <number> function
%type <number> params
%type <number> codeSet
%type <number> instruction
%type <number> assignation
%type <number> functionCallParams
%type <number> return
%type <number> print
%type <number> printableElement
%type <number> text
%type <number> controlStructure
%type <number> logicalOperation
%type <number> logicalOperator

%left SUM SUBSTRACT
%left PRODUCT DIVIDE

%start begin
%%

begin : {printf("Welcome to wic\n"); qInitialization();} root {goToExit();closeScopeInSymbolTable();qEnding();}
      ;


root : declaration END_OF_INSTRUCTION root
     | assignation END_OF_INSTRUCTION root
     | {if(marcador){jumpMain(); marcador = false;}} function root
     | END_OF_INSTRUCTION root
     | print END_OF_INSTRUCTION root
     | /* EMPTY */
     ;

declaration : INT_TYPE ID {insertVariableInSymbolTable($<string>2); declarationGlobalVariable($<string>2);}
            | INT_TYPE ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE { insertArrayInSymbolTable($<string>2, $<number>4); }
            ;

function : FUN ID {insertFunctionSymbolTable($<string>2); if(strcmp("main", $<string>2)==0){mainFunction();}else{function($<string>2);}} PARENTESIS_OPEN {openScopeInSymbolTable();} params {closeScopeInSymbolTable();} PARENTESIS_CLOSE {openScopeInSymbolTable();} CURLY_BRACKET_OPEN END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE END_OF_INSTRUCTION {closeScopeInSymbolTable();}
         ;

params : INT_TYPE ID params {insertParameterInSymbolTable($<string>2);}
       | COMMA INT_TYPE ID params {insertParameterInSymbolTable($<string>3);}
       | /* EMPTY */
       ;

codeSet : instruction END_OF_INSTRUCTION codeSet
        | controlStructure END_OF_INSTRUCTION codeSet
        | END_OF_INSTRUCTION codeSet
        | /* EMPTY */
        ;

instruction : assignation
            | declaration
            | return
            | print
            | BREAK {/*breakCode();*/}
            ;

assignation : ID ASSIGN INT_VAL {assignValueToVariable($<string>1,$<number>3);}
            | ID PLUSPLUS    {insertVariableValueInStack($<string>1); insertValueInStack(1); add();assignR0ToVariable($<string>1);}
            | ID MINUSMINUS   {insertVariableValueInStack($<string>1); insertValueInStack(1); substract();assignR0ToVariable($<string>1);}
            | ID ASSIGN aritmeticOperation {assignR0ToVariable($<string>1);}
            | ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE ASSIGN ID 
            | ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE ASSIGN INT_VAL 
            | ID ASSIGN ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE
            ;  

functionCallParams : aritmeticOperation
	    | aritmeticOperation COMMA functionCallParams
	    |
	    ;

aritmeticOperation :  aritmeticOperation SUM aritmeticOperation {add();}
                  |   aritmeticOperation SUBSTRACT aritmeticOperation {substract();}
                  |   aritmeticOperation PRODUCT aritmeticOperation {product();}
                  |   aritmeticOperation DIVIDE aritmeticOperation {division();}
                  |   PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE
            	  |   ID PARENTESIS_OPEN {saveR7inR4();} functionCallParams PARENTESIS_CLOSE {functionCall($<string>1);}
                  |   INT_VAL {insertValueInStack($<number>1);}
                  |   ID  {insertVariableValueInStack($<string>1);}    
                  ;


return : RETURN ID {printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++variable");}{putVariableInR0($<number>2);}{functionReturn();}
       | RETURN INT_VAL {printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++value");}{putValueInR0($<number>2);}{functionReturn();}
       | RETURN aritmeticOperation {printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++operation");}{putOperationResultInR0($<number>2);}{functionReturn();}
       | RETURN ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE {printf("TERMINA LLAMADA FUNCION\n");}
       ; 

print : PRINT PARENTESIS_OPEN QUOTE STRING_VAL QUOTE PARENTESIS_CLOSE {printString($<string>5);}
	  | PRINT PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE {printR0();}
      ; 

printableElement : ID {printVariable($<string>1);}
                 | QUOTE text QUOTE {/*generatePrintString($<string>2);*/}
                 | printableElement SUM printableElement
		 		 | INT_VAL {printValue($<number>1);}
                 ;

text : STRING_VAL {$$ = $<string>1;}
     | ' '  {$$ = $<number>1;}
     ;

else : {pushClauseIFE(printGoToFinalEstructureElse());} ELSE_CLAUSE {printLabelInstruction(popClauseIF());} CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); printLabelInstruction(popClauseIFE());}
      | {printLabelInstruction(popClauseIF());}
      ;
controlStructure : IF_CLAUSE PARENTESIS_OPEN logicalOperation PARENTESIS_CLOSE {pushClauseIF(printHeaderOfClauseInstruction());} CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet CURLY_BRACKET_CLOSE {closeScopeInSymbolTable();} else
                 | { int label = _getNextLabel(); printLabelInstruction(label); pushClauseWI(label);} WHILE_CLAUSE PARENTESIS_OPEN logicalOperation {int label = printHeaderOfClauseInstruction(); pushClauseWE(label);} PARENTESIS_CLOSE CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet {printClause();generateGoToWhile(popClauseWI());} CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); printClause(); printLabelInstruction(popClauseWE());}
				 ;

logicalOperation : ID logicalOperator ID {logicalVariableToVariable($<string>1, $<string>3, $<string>2);}
                 | ID logicalOperator INT_VAL { logicalVariableToValue($<string>1, $<number>3, $<string>2);}
                 | INT_VAL logicalOperator INT_VAL { logicalValueToValue($<number>1, $<number>3,$<string>2);}
                 | INT_VAL logicalOperator ID { logicalVariableToValue($<string>3, $<number>1, $<string>2);}
                 ;

logicalOperator : EQUALS {$$ = "==";}
                | NOT_EQUALS {$$ = "!=";}
                | LESS {$$ = "<";}
                | LESS_EQUALS {$$ = "<=";}
                | GREATER {$$ = ">";}
                | GREATER_EQUALS {$$ = ">=";}
                ;

%%

void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

