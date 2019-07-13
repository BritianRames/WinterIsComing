%{
#include "../BISON/AnalizadorSintactico.tab.h"
int numlin = 1;
void error(char*, char);
%}

%option noyywrap

letra   [a-zA-Z]
digito  [0-9]
guionbajo _
letdig  {letra}|{digito}|{guionbajo}
comment #.*\n
greaterEqual (>=)
smallerEqual (<=)

%%
var                           return VAR;
is                            return ASIGN;
equal                         return EQUAL;
not                           return NOTEQUAL;
{greaterEqual}                return GREATEREQUAL;
{smallerEqual}                return SMALLEREQUAL;
when                          return WHEN;
else                          return ELSE;
while                         return WHILE;
\{                            return OPENCURLYBRACKET;
\}                            return CLOSECURLYBRACKET;
\(                            return OPENBRACKET;
\)                            return CLOSEBRACKET;
int                           return INT;
string                        return STRING;
\"[^"|\n]*\"                  { yylval.string = strdup(yytext); return STRINGLITERAL; }
println                       return PRINTLN;
return                        return RETURN;
func                          return FUNC;
:                             return COLON;
,                             return COMMA;
break                         return BREAK;
("+"|-)?{digito}+             { yylval.entero = atoi(yytext); return ENTERO; }
{letra}                       { yylval.string = strdup(yytext); return VARIABLE; }
{letra}{letdig}*              { yylval.string = strdup(yytext); return FUNCNAME; }
[-+*/<>]                      return yytext[0];
\n                            {numlin++; return yytext[0];}/* contin ́ua leyendo */
[ \t]                         |
{comment}                     |
ˆ.*                          /* ignora */
.                             error("caracter raro", yytext[0]);
<<EOF>>                       return 0; /* por defecto */
%%

void error(char* mens, char character) {
  printf("Error lexico en linea %i: %s [%c]\n",numlin,mens, character);
}

/*unsigned int getRegister() {
  return 1;
}

unsigned int getAddress() {
  return 90000;
}

void insertVariable(char* symbol, unsigned int address) {

}*/
