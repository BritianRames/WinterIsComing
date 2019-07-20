%{
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

function : FUN ID {insertFunctionSymbolTable($<string>2); if(strcmp("main", $<string>2)==0){mainFunction();}} PARENTESIS_OPEN {openScopeInSymbolTable();} params {closeScopeInSymbolTable();} PARENTESIS_CLOSE {openScopeInSymbolTable();} CURLY_BRACKET_OPEN END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE END_OF_INSTRUCTION {closeScopeInSymbolTable();}
         ;

params : INT_TYPE ID params {/*insertVariable($<string>2);*/}
       | COMMA INT_TYPE ID params
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

functionCallParams : INT_VAL 
                   | ID 
                   | INT_VAL COMMA functionCallParams 
                   | ID COMMA functionCallParams

aritmeticOperation :  aritmeticOperation SUM aritmeticOperation {add();}
                  |   aritmeticOperation SUBSTRACT aritmeticOperation {substract();}
                  |   aritmeticOperation PRODUCT aritmeticOperation {product();}
                  |   aritmeticOperation DIVIDE aritmeticOperation {division();}
                  |   PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE
				  |   ID{/*guardamos r7 en r1*/} PARENTESIS_OPEN functionCallParams PARENTESIS_CLOSE
                  |   INT_VAL {insertValueInStack($<number>1);}
                  |   ID  {insertVariableValueInStack($<string>1);}    
                  ;


return : RETURN ID {/*returnVariable($<number>2);*/}
       | RETURN INT_VAL {/*returnValue($<number>2);*/}
       | RETURN aritmeticOperation {/*returnValue($<number>2);*/}
       | RETURN ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE {printf("TERMINA LLAMADA FUNCION\n");}
       ; 

print : PRINT PARENTESIS_OPEN printableElement PARENTESIS_CLOSE 
      ; 

printableElement : ID {/*generatePrintVariable($<string>1);*/}
                 | QUOTE text QUOTE {/*generatePrintString($<string>2);*/}
                 | printableElement SUM printableElement
				     | INT_VAL {printValue($<number>1);}
                 ;

text : STRING_VAL {$$ = $<string>1;}
     | ' '  {$$ = $<number>1;}
     ;

else : {exit_l = printGoToFinalEstructureElse();} ELSE_CLAUSE {printLabelInstruction(else_l);} CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); printLabelInstruction(exit_l);}
      | {printLabelInstruction(else_l);}
      ;
controlStructure : IF_CLAUSE PARENTESIS_OPEN logicalOperation PARENTESIS_CLOSE {else_l = printHeaderOfClauseInstruction();} CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet CURLY_BRACKET_CLOSE {closeScopeInSymbolTable();} else
                 | { $<number>$ = _getNextLabel();} WHILE_CLAUSE  {printLabelInstruction($<number>1);} PARENTESIS_OPEN logicalOperation {exit_l2 = printHeaderOfClauseInstruction();} PARENTESIS_CLOSE CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable();} codeSet {generateGoToWhile($<number>1);} CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); printLabelInstruction(exit_l2);}
                 ;

logicalOperation : ID logicalOperator ID { switch($2) {
					   	case 1:
							/*valueEqualsToVariable($<string>1, $<string>3);*/
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
                 | ID logicalOperator INT_VAL { switch($2) {
						   case 1:
						   	valueEqualsToVariable($<string>1, $<number>3);
						   	break;
						   case 2:
						   	valueNotEqualToVariable($<string>1, $<number>3);
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
                 | INT_VAL logicalOperator INT_VAL { switch($2) {
							   case 1:
								valueEqualsToValue($<number>1, $<number>3);
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
                 | INT_VAL logicalOperator ID { switch($2) {
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
                 ;

logicalOperator : EQUALS {$$ = 1;}
                | NOT_EQUALS {$$ = 2;}
                | LESS {$$ = 3;}
                | LESS_EQUALS {$$ = 4;}
                | GREATER {$$ = 5;}
                | GREATER_EQUALS {$$ = 6;}
                ;

%%

//int main(int argc, char** argv) {
//  if (argc>1) yyin=fopen(argv[1],"r");
//  yyparse();
//}


void yyerror (char const *s) {
  fprintf (stderr, "ERROR SINTACTICO [%d]: %s\n", numlin, s);
}

