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

%type <number> begin
%start begin
%%

begin : {printf("Welcome to wic");} root
      ;


root : declaration 
     | function
     ;

declaration : INT VARIABLE SEMICOLON {insertVariable($<string>2);}
            ;

function : INT VARIABLE {insertFunction($<string>2);} OPENINGBRACKET {openScope();} params {closeScope();} CLOSINGBRACKET OPENINGCURLYBRACKET {openScope();} codeSet {closingScope();} CLOSINGCURLYBRACKET 
         ;

params : INT VARIABLE COMMA params {insertVariable($<string>2);}
       | INT VARIABLE {insertVariable($<string>2);}
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
            | aritmeticOperation SEMICOLON
            | return SEMICOLON
            | print SEMICOLON
            | BREAK SEMICOLON {breakCode();}
            ;

assignation : VARIABLE '=' NUMBER SEMICOLON {generateAssignStaticValueToVariableCode($<string>1,$<number>3);}
            | VARIABLE '=' VARIABLE SEMICOLON {generateAssignStaticVriableToVariableCode($<string>1,$<string>3);}
            | VARIABLE '=' VARIABLE OPENINGBRACKET {functionCall($<string>1,$<string>3);} functionCallParams CLOSINGBRACKET SEMICOLON 
            ;  

functionCallParams : NUMBER {setParamsValue($<number>1);}
                   | VARIABLE {setParamsValueFromVariable($<string>1);}
                   | NUMBER COMMA functionCallParams {setParamsValue($<number>1);}
                   | VARIABLE COMMA functionCallParams {setParamsValueFromVariable($<string>1);}

aritmeticOperation : aritmeticOperation '-' aritmeticOperation {$$ = substract($<number>1,$<number>3);}
            | aritmeticOperation '+' aritmeticOperation {$$ = add($<number>1,$<number>3);}
            | aritmeticOperation '*' aritmeticOperation {$$ = multiply($<number>1, $<number>3);}
            | aritmeticOperation '/' aritmeticOperation {$$ = divide($<number>1, $<number>3);}
            | OPENINGBRACKET aritmeticOperation CLOSINGBRACKET {$$ = $<number>2;}
            | NUMBER {$$ = $<number>1;}
            ;

return : RETURN VARIABLE {returnVariable($<number>2);}
       | RETURN NUMBER {returnValue($<number>2);}
       | RETURN aritmeticOperation {returnValue($<number>2);}
       | RETURN VARIABLE OPENINGBRACKET {functionCall($<string>1,$<string>3);} functionCallParams CLOSINGBRACKET SEMICOLON
       ; 

print : PRINT OPENINGBRACKET printableElement CLOSINGBRACKET 
      ;

printableElement : VARIABLE {printVariable($<number>1);)}
                 | QUOTE text QUOTE {printText(($<number>1);)}
                 | printableElement '+' printableElement {printLineJump();}
                 ;

text : TEXT {$$ = $<number>1;}
     | ' '  {$$ = $<number>1;}
     ;

controlStructure : structuresWord OPENINGBRACKET {openScope();} logicalOperation {closingScope();} CLOSINGBRACKET OPENINGCURLYBRACKET {openScope();} codeSet {closingScope();} CLOSINGCURLYBRACKET
                 ;

structuresWord : IF {startIf();}
               | ELSE {startElse();}
               | WHILE {startWhile();}
               ;

logicalOperation : VARIABLE logicalOperator VARIABLE {logicalOperate(($<number>1),($<number>3),($<string>1))}
                 | VARIABLE logicalOperator NUMBER {logicalOperate(($<number>1),($<number>3),($<string>1))}
                 | NUMBER logicalOperator NUMBER {logicalOperate(($<number>1),($<number>3),($<string>1))}
                 | NUMBER logicalOperator VARIABLE {logicalOperate(($<number>1),($<number>3),($<string>1))}
                 ;

logicalOperator : EQUAL {$$ = "eq"}
                | NOTEQUAL {$$ = "neq"}
                | GREATER {$$ = "gt"}
                | MINOR {$$ = "mt"}
                | GREATEREQUAL {$$ = "ge"}
                | MINOREQUAL {$$ = "me"}
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
