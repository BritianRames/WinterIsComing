/* Ajustes iniciales */

%x COMMENT_BLOCK
%x COMMENT_LINE
%x STRING_STATE
%x CHECK_LVL

%option noyywrap

%{

    /* Declaraciones */

    //#include <string>

    #include "bwic.tab.h"

    int level = 0;
    int enter_special = 1;
    int numlin = 1;


    /* Declaraciones de funciones */

    int countSpaces(char* pattern);

%}

/* Definiciones regulares */

/* Expresiones regulares reutilizables */
letter                        [a-zA-Z_]
digit                         [0-9]

/* Palabras reservadas */
continue                      (continue)
break                         (break)
return                        (return)
fun                           (fun)

/* Valores segun el tipo de dato */
int_val                       {digit}+
/*real_val                      ({digit}+\.){digit}*|\.{digit}+*/
/*bool_val                      (true|false)*/
/*char_val                      [^']?|(\\[nrtvba0'"\\])*/
string_val                    [^"]*

/* Tipos de dato */
int_type                      (int)
real_type                     (real)
bool_type                     (bool)
string_type                   (string)
print_                        (print)

/* Expresiones regulares para estructuras de control y bucles */
if                            (if)
while                         (while)
else                          (else)
header_end                    :

/* Expresiones regulares delimitadoras */

/*context_tag                   [ ]*     */
/* Identificador */
id                            {letter}({letter}|{digit})*

%%
  /* if (enter_special) {*/
  /*  BEGIN(CHECK_LVL);*/
  /*  enter_special = 0;*/
  /*}*/


   /* Reglas de traducción */

   /* Cambios de ámbito */


"\n"                          {
                                //BEGIN(CHECK_LVL);
                                //yyless(0);
                                //printf("Nueva línea\n");
                                yylineno++;
                                printf("\n----END_OF_INSTRUCTION\n");
                                return END_OF_INSTRUCTION;
                              }

   /* Reglas para las palabras reservadas */
{continue}                    {
                                //printf("%s is a CONTINUE\n", yytext);
                                return CONTINUE;
                              }
{break}                       {
                                //printf("%s is a BREAK\n", yytext);
                                return BREAK;
                              }
{return}                      {
                                //printf("%s is a RETURN\n", yytext);
                                printf("----RETURN\n");
                                return RETURN;
                              }
{fun}                         {
                                printf("----FUN\n");
                                return FUN;
                              }
{print_}                       {
                                printf("----PRINT\n");
                                return PRINT;
                              }
"--"                          {return MINUSMINUS;}
"++"                          {return PLUSPLUS;}


   /* Reglas para los valores segun el tipo de dato */
{int_val}                     {
                                //TODO
                                //wic::data_value data_v;
                                //data_v.int_val = atoi(yytext);
                                yylval.number = atoi(yytext);
                                printf("\n----INT_VAL\n");
                                return INT_VAL;
                              }


   /* Reglas segun el tipo de dato */
{int_type}                    {
                                printf("\n----INT_TYPE\n"); 
                                return INT_TYPE;
                              }


   /* Regla de asignación */
"="                           {
                                //printf("%s is an ASSIGN\n", yytext);
                                printf("\n----ASSIGN\n");
                                return ASSIGN;
                              }


   /* Reglas para los operadores aritméticos */
"\+"                          {
                                //printf("%s is a SUM\n", yytext);
                                printf("\n----SUM\n");
                                return SUM;
                              }
"-"                           {
                                //printf("%s is a SUBSTRACT\n", yytext);
                                printf("\n----SUBSTRACT\n");
                                return SUBSTRACT;
                              }
"\*"                          {
                                //printf("%s is a PRODUCT\n", yytext);
                                printf("\n----PRODUCT\n");
                                return PRODUCT;
                              }
"/"                           {
                                //printf("%s is a DIVIDE\n", yytext);
                                printf("\n----DIVIDE\n");
                                return DIVIDE;
                              }



   /* Reglas para los operadores lógicos */
"&&"                          {
                                //printf("%s is a AND\n", yytext);
                                return AND;
                              }
"||"                          {
                                //printf("%s is a OR\n", yytext);
                                return OR;
                              }
"!"                           {
                                //printf("%s is a NOT\n", yytext);
                                return NOT;
                              }
"=="                          {
                                //printf("%s is a EQUALS\n", yytext);
                                printf("----EQUALS\n");
                                return EQUALS;
                              }
"!="                          {
                                //printf("%s is a NOT_EQUALS\n", yytext);
                                printf("----NOT_EQUALS\n");
                                return NOT_EQUALS;
                              }
">"                           {
                                //printf("%s is a GREATER\n", yytext);
                                printf("----GREATER\n");
                                return GREATER;
                              }
">="                          {
                                //printf("%s is a GREATER_EQUALS\n", yytext);
                                printf("----GREATER_EQUALS\n");
                                return GREATER_EQUALS;
                              }
"<"                           {
                                //printf("%s is a LESS\n", yytext);
                                printf("----LESS\n");
                                return LESS;
                              }
"<="                          {
                                //printf("%s is a LESS_EQUALS\n", yytext);
                                printf("----LESS_EQUALS\n");
                                return LESS_EQUALS;
                              }



   /* Expresiones regulares para estructuras de control y bucles */
{if}                          {
                                //printf("%s is an IF_CLAUSE\n", yytext);
                                printf("----IF_CLAUSE\n");
                                return IF_CLAUSE;
                              }
{header_end}                  {
                                //printf("%s is an HEADER_END\n", yytext);
                                printf("----HEADER_END\n");
                                return HEADER_END;
                              }
{while}                       {
                                //printf("%s is an FOR_WHILE_CLAUSE\n", yytext);
                                return WHILE_CLAUSE;
                              }

{else}                        {
                                printf("----ELSE_CLAUSE\n"); 
                                return ELSE_CLAUSE;
                              }

   /* Expresiones regulares delimitadoras */
"\["                          {
                                //printf("%s is an SQUARE_BRACKET_OPEN\n", yytext);
                                return SQUARE_BRACKET_OPEN;
                              }
"\]"                          {
                                //printf("%s is an SQUARE_BRACKET_CLOSE\n", yytext);
                                return SQUARE_BRACKET_CLOSE;

                              }
"\{"                          {
                                //printf("%s is an CURLY_BRACKET_OPEN\n", yytext);
                                return CURLY_BRACKET_OPEN;
                              }
"\}"                          {
                                //printf("%s is an CURLY_BRACKET_CLOSE\n", yytext);
                                return CURLY_BRACKET_CLOSE;
                              }
","                           {
                                //printf("%s is an COMMA\n", yytext);
                                printf("\n----COMMA\n");
                                return COMMA;
                              }
"\("                          {
                                //printf("%s is an PARENTESIS_OPEN\n", yytext);
                                return PARENTESIS_OPEN;
                              }
"\)"                          {
                                //printf("%s is an PARENTESIS_CLOSE\n", yytext);
                                return PARENTESIS_CLOSE;
                              }


  /* Identificador */
{id}                          {
                                //TODO
                                //std::string id = yytext;
                                //yylval = reinterpret_cast<void *>(new wic::ASTIDNode(id, wic::UNKNOWN));
                                yylval.string = strdup(yytext); 
                                printf("\n----ID\n");
                                return ID;
                              }

  /* Reglas para los strings */
\"                            {
                                BEGIN(STRING_STATE);
                                return QUOTE;
                              }
<STRING_STATE>{string_val}    {
                                //TODO
                                //wic::data_value data_v ;
                                //data_v.str_val = new char[yyleng];
                                //data_v.str_val = strcpy(data_v.str_val, yytext);
                                //yylval = reinterpret_cast<void *>(new wic::ASTLeafNode(wic::STRING, &data_v));
                                //yylval.string = strdup(yytext);
                                printf("----STRING_VAL\n");
                                return STRING_VAL;
                              }
<STRING_STATE>\"              {
                                BEGIN(INITIAL);
                                printf("----QUOTE\n");
                                return QUOTE;
                              }


  /* Reglas para los comentarios */
\.\.                          { BEGIN(COMMENT_LINE); }
<COMMENT_LINE>.+              { }
<COMMENT_LINE>\n              {
                                yylineno++;
                                BEGIN(INITIAL);
                              }
<COMMENT_LINE><<EOF>>         /* Do error */


",\."                         { BEGIN(COMMENT_BLOCK); }
<COMMENT_BLOCK>"\.,"          {
                                BEGIN(INITIAL);
                              }
<COMMENT_BLOCK>[^\n]
<COMMENT_BLOCK>\n             { yylineno++; }
<COMMENT_BLOCK><<EOF>>        /* Do error */


"\t"+                          {
                                //printf("Esto es un tabulado\n");
                              }
" "                           {
                                //printf("Esto es un espacio\n");
                              }

   /* Unknowns & errors */
.                             {
                                printf("<%s> is an unknown\n", yytext);
                              }

%%

/* Funciones y declaraciones auxiliares */

int countSpaces(char* pattern) {
  int i = 0;
  int numSpaces = 0;
  int total = 0;
  while (pattern[i] != '\0') {
    if (pattern[i] == ' ') numSpaces++;
    if ((numSpaces % 4) == 0 && numSpaces > 0) total++;
    i++;
  }
  return total;
}
