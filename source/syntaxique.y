%{
    int nb_ligne = 1;
    int nb_colone = 1;
%}

%token  mc_if mc_else mc_for mc_while mc_in mc_range mc_int mc_float mc_char mc_bool mc_and mc_or mc_not
        colon comma assign openParenthesis closeParenthesis openBracket closeBracket
        integer real character booleen idf
        lessOrEqual greatOrEqual less great equal notEqual
        pls min divs mul
%right  assign
%right  mc_not
%left   mc_and mc_or
%left   lessOrEqual greatOrEqual less great equal notEqual
%left   pls min
%left   mul divs

%%
Prog    : Instruction Prog
        |
        { printf("Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
Instruction     : Declaration 
                | Assignment 
                | IF
                | WHILE
                | FOR
;

Declaration     : type idf DecAssignment
                | type idf DecNext
                | type idf tab
;
DecNext : comma DecNextAssignment
        |
;
DecNextAssignment       : idf DecAssignment DecNext
                        | idf DecNext
;
DecAssignment   : assign ValType
;
Assignment      : idf assign ValType
                | idf openBracket intOridf closeBracket assign ValType
;
ValType : arithmeticOperand
        | logicOperand
        | character
;

intOridf        : integer
                | idf
;
type    : mc_int
        | mc_float
        | mc_char
        | mc_bool
;
tab     : openBracket integer closeBracket
;

IF      : mc_if openParenthesis logicOperand closeParenthesis colon Instruction
        | mc_if openParenthesis logicOperand closeParenthesis colon Instruction ELSE
;
ELSE    : mc_else colon Instruction
;
WHILE   : mc_while openParenthesis logicOperand closeParenthesis colon Instruction
;
FOR     : mc_for idf mc_in forType colon Instruction
;
forType : range
        | idf
;
range   : mc_range openParenthesis integer comma integer closeParenthesis
;

logicExpression : logicOperand mc_and logicOperand
                | logicOperand mc_or logicOperand
                | mc_not logicOperand
;

comparisonExpression    : arithmeticOperand equal arithmeticOperand
                        | arithmeticOperand notEqual arithmeticOperand
                        | arithmeticOperand lessOrEqual arithmeticOperand
                        | arithmeticOperand greatOrEqual arithmeticOperand
                        | arithmeticOperand less arithmeticOperand
                        | arithmeticOperand great arithmeticOperand
;

arithmeticExpression    : arithmeticOperand mul arithmeticOperand
                        | arithmeticOperand divs arithmeticOperand
                        | arithmeticOperand pls arithmeticOperand
                        | arithmeticOperand min arithmeticOperand
;

arithmeticOperand       : idf
                        | integer
                        | real
                        | arithmeticExpression
                        | openParenthesis arithmeticOperand closeParenthesis
;

logicOperand    : idf
                | booleen
                | comparisonExpression
                | logicExpression
                | openParenthesis logicOperand closeParenthesis
;

%%

main()
{
        Init_TS();
        yyparse();
        Print_TS();
}
yywrap()
{

}
int yyerror (char *msg )
{ 
        printf ("ERREUR SYNTAXIQUE: ligne %d, colonne %d \n",nb_ligne,nb_colone); 
        return 1; 
}