/* Ajustes iniciales */

%x COMMENT_BLOCK
%x COMMENT_LINE
%x CHAR_STATE
%x STRING_STATE
%x CHECK_LVL

%option noyywrap

%{

    /* Declaraciones */

    //#include <string>

    #include "y.tab.h"

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
char_type                     (char)

/* Expresiones regulares para estructuras de control y bucles */
if                            (\?){1}
while                         (\?){2}
header_end                    :

/* Expresiones regulares delimitadoras */

context_tag                   [ ]*
/* Identificador */
id                            {letter}({letter}|{digit})*

%%
  if (enter_special) {
    BEGIN(CHECK_LVL);
    enter_special = 0;
  }


   /* Reglas de traducción */

   /* Cambios de ámbito */

<CHECK_LVL>\n?{context_tag}    {
                                //printf("Procesando... \n<%s>\n", yytext);
                                int level_change = countSpaces(yytext);
                                //printf("%d\n", level_change);

                                if (level < level_change) {
                                  level++;
                                  if (level != level_change) yyless(0);
                                  //printf("Level <OPEN_CONTEXT_TAG> : %d\n", level);
                                  return OPEN_CONTEXT_TAG;
                                } else if (level > level_change) {
                                   level--;
                                   if (level != level_change) yyless(0);
                                   //printf("Level <CLOSE_CONTEXT_TAG> : %d\n", level);
                                   return CLOSE_CONTEXT_TAG;
                                }
                                //printf("Level : %d\n", level);
                                BEGIN(INITIAL);
                              }
<CHECK_LVL><<EOF>>            {
                                if (level > 0) {
                                  level--;
                                  return CLOSE_CONTEXT_TAG;
                                } else return 0;
                              }
<CHECK_LVL>[^ \n]             {
                                printf("Vamos para atrás\n");
                                BEGIN(INITIAL);
                                yyless(0);
                              }
<<EOF>>                       {
                                BEGIN(CHECK_LVL);
                              }
"\n"                          {
                                BEGIN(CHECK_LVL);
                                yyless(0);
                                printf("Nueva línea\n");
                                yylineno++;
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
                                return RETURN;
                              }
{fun}                         {
                                return FUN;
                              }


   /* Reglas para los valores segun el tipo de dato */
{int_val}                     {
                                //TODO
                                //wic::data_value data_v;
                                //data_v.int_val = atoi(yytext);
                                return INT_VAL;
                              }


   /* Reglas segun el tipo de dato */
{int_type}                    {
                                return INT_TYPE;
                              }


   /* Regla de asignación */
"="                           {
                                //printf("%s is an ASSIGN\n", yytext);
                                return ASSIGN;
                              }


   /* Reglas para los operadores aritméticos */
"\+"                          {
                                //printf("%s is a SUM\n", yytext);
                                return SUM;
                              }
"-"                           {
                                //printf("%s is a SUBSTRACT\n", yytext);
                                return SUBSTRACT;
                              }
"\*"                          {
                                //printf("%s is a PRODUCT\n", yytext);
                                return PRODUCT;
                              }
"/"                           {
                                //printf("%s is a DIVIDE\n", yytext);
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
                                return EQUALS;
                              }
"!="                          {
                                //printf("%s is a NOT_EQUALS\n", yytext);
                                return NOT_EQUALS;
                              }
">"                           {
                                //printf("%s is a GREATER\n", yytext);
                                return GREATER;
                              }
">="                          {
                                //printf("%s is a GREATER_EQUALS\n", yytext);
                                return GREATER_EQUALS;
                              }
"<"                           {
                                //printf("%s is a LESS\n", yytext);
                                return LESS;
                              }
"<="                          {
                                //printf("%s is a LESS_EQUALS\n", yytext);
                                return LESS_EQUALS;
                              }



   /* Expresiones regulares para estructuras de control y bucles */
{if}                          {
                                //printf("%s is an IF_CLAUSE\n", yytext);
                                return IF_CLAUSE;
                              }
{header_end}                  {
                                //printf("%s is an HEADER_END\n", yytext);
                                return HEADER_END;
                              }
{while}                       {
                                //printf("%s is an FOR_WHILE_CLAUSE\n", yytext);
                                return WHILE_CLAUSE;
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
                                return ID;
                              }

  /* Reglas para los strings */
\"                            {
                                BEGIN(STRING_STATE);
                                return STRING_QUOTE;
                              }
<STRING_STATE>{string_val}    {
                                //TODO
                                //wic::data_value data_v ;
                                //data_v.str_val = new char[yyleng];
                                //data_v.str_val = strcpy(data_v.str_val, yytext);
                                //yylval = reinterpret_cast<void *>(new wic::ASTLeafNode(wic::STRING, &data_v));
                                return STRING_VAL;
                              }
<STRING_STATE>\"              {
                                BEGIN(INITIAL);
                                return STRING_QUOTE;
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
                                printf("Esto es un tabulado\n");
                              }
" "                           {
                                printf("Esto es un espacio");
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
