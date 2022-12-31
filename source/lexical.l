%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern nb_ligne;
extern nb_colone;

#include"ts.h" 
#include"syntaxique.tab.h"
#include"other.h"

extern YYSTYPE yylval;

%}

lettreMaj [A-Z]
lettreMin [a-z]
chiffre [0-9]
signe [-+]

idf ({lettreMaj}|{lettreMin}|_)({lettreMaj}|{lettreMin}|_|{chiffre})*
char '({lettreMaj}|{lettreMin}|{chiffre})'
int \({signe}?{chiffre}+\)|{chiffre}+
float \({signe}?{chiffre}+\.{chiffre}+\)|{chiffre}+\.{chiffre}+
bool ("true"|"false")

comment #.*

%%
if      {
            printf("IF\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_if;
        } 
else    {
            printf("ELSE\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_else;
        }
for     {
            printf("FOR\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_for;
        }
while   {
            printf("WHILE\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_while;
        }
in      {
            printf("IN\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_in;
        }
range   {
            printf("RANGE\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_range;
        }
int     {
            printf("INT\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            yylval.type = INT;
            return mc_int;
        }
float   {
            printf("FLOAT\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            yylval.type = FLOAT;
            return mc_float;
        }
char    {
            printf("CHAR\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            yylval.type = CHAR;
            return mc_char;
        }
bool    {
            printf("BOOL\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            yylval.type = BOOL;
            return mc_bool;
        }
and     {
            printf("AND\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_and;
        }
or      {
            printf("OR\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_or;
        }
not     {
            printf("NOT\n");
            nb_colone += strlen(yytext);
            Find_TS(yytext, "MC", "", 0, EM);
            return mc_not;
        }

{int}   {   printf("%f : int\n", re_atof(yytext, strlen(yytext)));
            nb_colone += strlen(yytext);
            Find_TS(yytext, "entier", "int",re_atof(yytext, strlen(yytext)), EV);
            yylval.valtype.val.I = (int) re_atof(yytext, strlen(yytext));
            yylval.valtype.type=INT;
            return integer;
        }
{float} {   printf("%f : float\n", re_atof(yytext, strlen(yytext)));
            nb_colone += strlen(yytext);
            Find_TS(yytext, "reel", "float", re_atof(yytext, strlen(yytext)), EV);
            yylval.valtype.val.F = re_atof(yytext, strlen(yytext));
            yylval.valtype.type = FLOAT;
            return real;
        }
{char}  {   printf("%s : char\n", yytext);
            nb_colone += strlen(yytext);
            Find_TS(yytext, "character", "char", 0, EV);
            yylval.valtype.val.C = strdup(yytext)[1];
            yylval.valtype.type = CHAR;
            return character;
        }
{bool}  {   printf("%s : bool\n", yytext);
            nb_colone += strlen(yytext);
            Find_TS(yytext, "booleen", "bool", 0, EV);
            if(strcmp(yytext, "true")==0)
            {
                yylval.valtype.val.B = true;
            }else{
                yylval.valtype.val.B = false;
            }
            yylval.valtype.type = BOOL;
            return booleen;
        }
{idf}   {   printf("%s : idf\n", yytext);
            nb_colone += strlen(yytext);
            Find_TS(yytext, "identifier", "", 0, EV);
            yylval.str = (char *) strdup(yytext);
            return idf;
        }
{comment}   {printf("%s : comment\n", yytext);}

"<="    {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return lessOrEqual;
        }
">="    {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return greatOrEqual;
        }
"<"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return less;
        }
">"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return great;
        }
"=="    {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return equal;
        }
"!="    {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return notEqual;
        }

"+"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return pls;
        }
"-"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return min;
        }
"/"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return divs;
        } 
"*"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return mul;
        }

":"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return colon;
        }
","     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return comma;
        }
"="     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return assign;
        }
"("     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return openParenthesis;
        }
")"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return closeParenthesis;
        }
"["     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return openBracket;
        }
"]"     {
            nb_colone += strlen(yytext);
            Find_TS(yytext, "SP", "", 0, ES);
            return closeBracket;
        }

[ \t] {nb_colone += strlen(yytext);}
\n {nb_ligne++; nb_colone = 1;}
. {printf("ERREUR LEXICAL: line %d, colonne %d, entite: %s\n",nb_ligne,nb_colone,yytext);}
%%
