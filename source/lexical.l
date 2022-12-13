%{

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern nb_ligne;
extern nb_colone;

#include"syntaxique.tab.h"

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
if {printf("IF\n");         nb_colone += strlen(yytext); return mc_if;}
else {printf("ELSE\n");     nb_colone += strlen(yytext); return mc_else;}
for {printf("FOR\n");       nb_colone += strlen(yytext); return mc_for;}
while {printf("WHILE\n");   nb_colone += strlen(yytext); return mc_while;}
in {printf("IN\n");         nb_colone += strlen(yytext); return mc_in;}
range {printf("RANGE\n");   nb_colone += strlen(yytext); return mc_range;}
int {printf("INT\n");       nb_colone += strlen(yytext); return mc_int;}
float {printf("FLOAT\n");   nb_colone += strlen(yytext); return mc_float;}
char {printf("CHAR\n");     nb_colone += strlen(yytext); return mc_char;}
bool {printf("BOOL\n");     nb_colone += strlen(yytext); return mc_bool;}
and {printf("AND\n");       nb_colone += strlen(yytext); return mc_and;}
or {printf("OR\n");         nb_colone += strlen(yytext); return mc_or;}
not {printf("NOT\n");       nb_colone += strlen(yytext); return mc_not;}

{int} {printf("%s : int\n", yytext);        nb_colone += strlen(yytext); return integer;}
{float} {printf("%s : float\n", yytext);    nb_colone += strlen(yytext); return real;}
{char} {printf("%s : char\n", yytext);      nb_colone += strlen(yytext); return character;}
{bool} {printf("%s : bool\n", yytext);      nb_colone += strlen(yytext); return booleen;}
{idf} {printf("%s : idf\n", yytext);        nb_colone += strlen(yytext); return idf;}
{comment} {printf("%s : comment\n", yytext);}

"<=" {nb_colone += strlen(yytext);  return lessOrEqual;}
">=" {nb_colone += strlen(yytext);  return greatOrEqual;}
"<" {nb_colone += strlen(yytext);   return less;}
">" {nb_colone += strlen(yytext);   return great;}
"==" {nb_colone += strlen(yytext);  return equal;}
"!=" {nb_colone += strlen(yytext);  return notEqual;}

"+" {nb_colone += strlen(yytext);   return pls;}
"-" {nb_colone += strlen(yytext);   return min;}
"/" {nb_colone += strlen(yytext);   return divs;} 
"*" {nb_colone += strlen(yytext);   return mul;}

":" {nb_colone += strlen(yytext);   return colon;}
"," {nb_colone += strlen(yytext);   return comma;}
"=" {nb_colone += strlen(yytext);   return assign;}
"(" {nb_colone += strlen(yytext);   return openParenthesis;}
")" {nb_colone += strlen(yytext);   return closeParenthesis;}
"[" {nb_colone += strlen(yytext);   return openBracket;}
"]" {nb_colone += strlen(yytext);   return closeBracket;}

[ \t] {nb_colone += strlen(yytext);}
\n {nb_ligne++; nb_colone = 1;}
. {printf("ERREUR LEXICAL: line %d, colonne %d, entite: %s\n",nb_ligne,nb_colone,yytext);}
%%