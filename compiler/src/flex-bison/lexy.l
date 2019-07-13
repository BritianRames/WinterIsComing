%{ int numlin = 1;
void error(char*);
%}

letra [a-zA-Z]
digito [0-9]
guion [-|_]
letdig {letra}|{digito}|{guion}
comment //.*\n
greater >
minor <
greaterequal >=
minorequal <=

%%

int 							          {return INT;}
== 								          return EQUAL;
!=													return NOTEQUAL;
{greater}                   return GREATER;
{minor} 								    return MINOR;
{greaterequal} 							return GREATEREQUAL;
{minorequal} 								return MINOREQUAL;
! 								          return OPPOSITE;
if 								          return IF;
else							          return ELSE;
while         							return WHILE;
\{						          		return OPENINGCURLYBRACKET;
\}          								return CLOSINGCURLYBRACKET;
\(					          			return OPENINGBRACKET;
\)                         	return CLOSINGBRACKET;
\"													return QUOTE;	
print                     	return PRINT;
return                     	return RETURN;
func                       	return FUNC;
,                          	return COMMA;
;                          	return SEMICOLON;
string                      return STRING;
break                      	return BREAK;

{digito}+ 				          { yylval.num = atoi(yytext); return NUMBER; }
{letra}{letdig}*						{ yylval.string = strdup(yytext); return VARIABLE; }
{letdig}*										{ yylval.string = strdup(yytext); return TEXT; }
[-+*/] 							        return yytext[0];
\n 								          {numlin++; /* continua leyendo */}
[ \t] |
ˆ#.* 							          /* ignora */
. 								          error("caracter raro");
<<EOF>> 						        return 0;   /* por defecto */

%%

void error(char* mens) {
	printf("Error lexico en linea %i: %s\n",numlin,mens);
}
