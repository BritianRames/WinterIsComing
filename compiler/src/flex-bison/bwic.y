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

begin : {printf("Welcome to wic\n"); generateQInitialization();} root {generateGoToExit();closeScopeInSymbolTable();generateQEnding();}
      ;


root : declaration END_OF_INSTRUCTION root
     | assignation END_OF_INSTRUCTION root
     | {if(marcador){generatePrintJumpMain(); marcador = false;}} function root
     | END_OF_INSTRUCTION root
	 | print END_OF_INSTRUCTION root
     | /* EMPTY */
     ;

declaration : INT_TYPE ID {
                            printf("-----------------------------DECLARACION VARIABLE %s------------------------------------------------------------------------------\n", $2);

                            insertVariableInSymbolTable($<string>2);
                          }
            | INT_TYPE ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE { insertArrayInSymbolTable($<string>2, $<number>4); generateCreateArray($<string>2); }
            ;

function : FUN ID {printf("COMIENZA FUNCION \n"); insertFunctionSymbolTable($<string>2); if(strcmp("main", $<string>2)==0){generateMainFunction();}} PARENTESIS_OPEN {openScopeInSymbolTable();} params {closeScopeInSymbolTable();} PARENTESIS_CLOSE {openScopeInSymbolTable();} CURLY_BRACKET_OPEN END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE END_OF_INSTRUCTION {printf("FINALIZA FUN\n");closeScopeInSymbolTable();}
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
            | return
            | print
            | BREAK {/*breakCode();*/}
            ;

assignation : ID ASSIGN INT_VAL {
                                  printf("ASIGNACION VALOR\n"); 
                                  generateAssignValueToVariableCode($<string>1,$<number>3);
                                }
            | ID ASSIGN ID      {
                                  printf("ASIGNACION VARIABLE\n"); 
                                  generateAssignVariableToVariableCode($<string>1,$<string>3);
                                }
            | ID ASSIGN ID PARENTESIS_OPEN {printf("ASIGNACION LLAMADA FUNCION\n");/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE
            | ID ASSIGN aritmeticOperation { generateAssignOperationResultToVariable($<string>1);}
            | ID SQUARE_BRACKET_OPEN INT_VAL SQUARE_BRACKET_CLOSE ASSIGN aritmeticOperation { generateArrayAssignValue($<string>1,$<number>3,$<number>6); }
            ;  

functionCallParams : INT_VAL {printf("PARAMETRO ENTERO\n");/*setParamsValue($<number>1);*/}
                   | ID {printf("PARAMETRO VARIABLE\n");/*setParamsValueFromVariable($<string>1);*/}
                   | INT_VAL COMMA functionCallParams {printf("PARAMETRO ENTERO COMMA\n");/*setParamsValue($<number>1);*/}
                   | ID COMMA functionCallParams {printf("PARAMETRO VARIABLE COMMA\n");/*setParamsValueFromVariable($<string>1);*/}

aritmeticOperation :  aritmeticOperation SUM aritmeticOperation {generateAddValue();}
                  |   aritmeticOperation SUBSTRACT aritmeticOperation {generateSubstractValue();}
                  |   aritmeticOperation PRODUCT aritmeticOperation {generateProductValue();}
                  |   aritmeticOperation DIVIDE aritmeticOperation {generateDivisionValue();}
                  |   PARENTESIS_OPEN aritmeticOperation PARENTESIS_CLOSE
                  |   INT_VAL { printf("EL NUMERO ES: ");printf("%d\n",$<number>1);generateInsertOnStack($<number>1);printf("ADIOS\n");}
                  |   ID      { generateInsertOnStackVARIABLE($<string>1);}
                  ;


return : RETURN ID {/*returnVariable($<number>2);*/}
       | RETURN INT_VAL {/*returnValue($<number>2);*/}
       | RETURN aritmeticOperation {/*returnValue($<number>2);*/}
       | RETURN ID PARENTESIS_OPEN {/*functionCall($<string>1,$<string>3);*/} functionCallParams PARENTESIS_CLOSE {printf("TERMINA LLAMADA FUNCION\n");}
       ; 

print : PRINT PARENTESIS_OPEN printableElement PARENTESIS_CLOSE 
      ; 

printableElement : ID {generatePrintVariable($<string>1);}
                 | QUOTE text QUOTE {generatePrintString($<string>2);}
                 | printableElement SUM printableElement
				 | INT_VAL {generatePrintValue($<string>1);}
                 ;

text : STRING_VAL {$$ = $<string>1;}
     | ' '  {$$ = $<number>1;}
     ;

controlStructure : IF_CLAUSE PARENTESIS_OPEN logicalOperation PARENTESIS_CLOSE CURLY_BRACKET_OPEN END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE
                 | IF_CLAUSE PARENTESIS_OPEN logicalOperation PARENTESIS_CLOSE {else_l = generateHeaderOfClauseInstruction();} CURLY_BRACKET_OPEN {openScopeInSymbolTable();} END_OF_INSTRUCTION codeSet CURLY_BRACKET_CLOSE {exit_l = _getNextLabel(); generateGoToInstruction(exit_l); closeScopeInSymbolTable();} ELSE_CLAUSE CURLY_BRACKET_OPEN END_OF_INSTRUCTION {openScopeInSymbolTable(); generateLabelInstruction(else_l);} codeSet CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); generateLabelInstruction(exit_l);}
                 | { while_l = _getNextLabel(); generateLabelInstruction(while_l);} WHILE_CLAUSE PARENTESIS_OPEN logicalOperation PARENTESIS_CLOSE {exit_l = generateHeaderOfClauseInstruction();} CURLY_BRACKET_OPEN {openScopeInSymbolTable();} END_OF_INSTRUCTION codeSet {generateGoToInstruction(while_l);} CURLY_BRACKET_CLOSE {closeScopeInSymbolTable(); generateLabelInstruction(exit_l);}
                 ;

logicalOperation : ID logicalOperator ID { switch($2) {
					   	case 1:
							generateEqualsVariableToVariable($<string>1, $<string>3);
					   		break;
						case 2:
							generateNotEqualsVariableToVariable($<string>1, $<string>3);
							break;
						case 3:
							generateLessVariableToVariable($<string>1, $<string>3);
							break;
						case 4:
							generateLessEqualsVariableToVariable($<string>1, $<string>3);
							break;
						case 5:
							generateGreaterVariableToVariable($<string>1, $<string>3);
							break;
						case 6:
						default:
							generateGreaterEqualsVariableToVariable($<string>1, $<string>3);
							break;
					    } }
                 | ID logicalOperator INT_VAL { switch($2) {
						   case 1:
						   	generateEqualsValueToVariable($<string>1, $<number>3);
						   	break;
						   case 2:
						   	generateNotEqualsValueToVariable($<string>1, $<number>3);
						   	break;
						   case 3:
						   	generateLessValueToVariable($<string>1, $<number>3);
						   	break;
						   case 4:
						   	generateLessEqualsValueToVariable($<string>1, $<number>3);
						   	break;
						   case 5:
						   	generateGreaterValueToVariable($<string>1, $<number>3);
						   	break;
						   case 6:
						   default:
						   	generateGreaterEqualsValueToVariable($<string>1, $<number>3);
						   	break;
					        } }
                 | INT_VAL logicalOperator INT_VAL { switch($2) {
							   case 1:
								generateEqualsValueToValue($<number>1, $<number>3);
								break;
							   case 2:
								generateNotEqualsValueToValue($<number>1, $<number>3);
								break;
							   case 3:
								generateLessValueToValue($<number>1, $<number>3);
								break;
							   case 4:
								generateLessEqualsValueToValue($<number>1, $<number>3);
								break;
							   case 5:
								generateGreaterValueToValue($<number>1, $<number>3);
								break;
							   case 6:
							   default:
								generateGreaterEqualsValueToValue($<number>1, $<number>3);
								break;
							} }
                 | INT_VAL logicalOperator ID { switch($2) {
						   case 1:
							generateEqualsValueToVariable($<number>1, $<string>3);
							break;
						   case 2:
							generateNotEqualsValueToVariable($<number>1, $<string>3);
							break;
						   case 3:
							generateLessValueToVariable($<number>1, $<string>3);
							break;
						   case 4:
							generateLessEqualsValueToVariable($<number>1, $<string>3);
							break;
						   case 5:
							generateGreaterValueToVariable($<number>1, $<string>3);
							break;
						   case 6:
						   default:
							generateGreaterEqualsValueToVariable($<number>1, $<string>3);
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

