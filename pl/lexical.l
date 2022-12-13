%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int nb_ligne=1;
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
if {printf("IF\n");}
else {printf("ELSE\n");}
for {printf("FOR\n");}
while {printf("WHILE\n");}
in {printf("IN\n");}
range {printf("RANGE\n");}
int {printf("INT\n");}
float {printf("FLOAT\n");}
char {printf("CHAR\n");}
bool {printf("BOOL\n");}
and {printf("AND\n");}
or {printf("OR\n");}
not {printf("NOT\n");}

{int} {printf("%s : int\n", yytext);}
{float} {printf("%s : float\n", yytext);}
{char} {printf("%s : char\n", yytext);}
{bool} {printf("%s : bool\n", yytext);}
{idf} {printf("%s : idf\n", yytext);}
{comment} {printf("%s : comment\n", yytext);}

"<="
">="
"<"
">"
"=="
"!="

"+"
"-"
"/"
"*"

":"
","
"="
"("
")"
"["
"]"

[ \t]
\n {nb_ligne++;}
. {printf("ERREUR LEXICAL, line %d, colonne NaN, entite: %s\n",nb_ligne,yytext);}
%%
int main() 
{  
   yyin = fopen( "exemple.txt", "r" );
   
   if (yyin==NULL) printf("ERROR \n");
	else yylex();  
   
   return 0; 
}
