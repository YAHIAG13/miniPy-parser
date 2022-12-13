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
%left   pls min
%left   mc_and mc_or
%left   mul divs

%%
Prog  : Instruction Prog
      |
      { printf("Le programme est correcte syntaxiquement\n"); YYACCEPT; }
;
Instruction : Declaration 
            | Assignment 
            | IF
            | WHILE
            | FOR
;
Declaration : type idf DecAssignment
            | type idf DecNext
            | type idf tab
;
DecNext: comma DecNextAssignment
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
ValType : operand
        | character
;

intOridf  : integer
          | idf
;

IF: mc_if openParenthesis ConditionGroup closeParenthesis colon Instruction
  | mc_if openParenthesis ConditionGroup closeParenthesis colon Instruction ELSE
;
ELSE: mc_else colon Instruction
;

WHILE: mc_while openParenthesis ConditionGroup closeParenthesis colon Instruction
;

FOR: mc_for idf mc_in forType colon Instruction
;
forType : range
        | idf
;

ConditionGroup: ConditionGroup logicOperatorBin ConditionGroup
              | mc_not ConditionGroup
              | Condition
;
Condition : logicExpression
          | comparisonExpression
;
logicExpression : logicOperand logicOperatorBin logicOperand
                | mc_not logicOperand
                | logicOperand
;
comparisonExpression: operand comparisonOperator operand
;

arithmeticExpression: operand arithmeticOperator operand
;
operand : integer
        | real
        | idf
        | openParenthesis arithmeticExpression closeParenthesis
        | arithmeticExpression
        | Condition
        | openParenthesis Condition closeParenthesis
;

logicOperand: booleen|idf|
;
logicOperatorBin: mc_and|mc_or;
comparisonOperator: lessOrEqual|greatOrEqual|less|great|equal|notEqual;
arithmeticOperator: pls|min|divs|mul;
type: mc_int|mc_float|mc_char|mc_bool;
tab: openBracket integer closeBracket;
range: mc_range openParenthesis integer comma integer closeParenthesis;
%%

main()
{
  yyparse();
}
yywrap()
{}
int yyerror (char *msg ) { 
  printf ("ERREUR SYNTAXIQUE:S ligne %d, colonne %d \n",nb_ligne,nb_colone); 
  return 1; 
}