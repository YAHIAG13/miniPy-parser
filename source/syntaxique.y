%{
    int nb_ligne = 1;
    int nb_colone = 1;
    int num_errors = 0;
    int yyerror();
        
%}
%code requires {
        #include"tv.h"
}
%union
{
        char type;
        char *str;
        struct vt valtype;   
}
%token  mc_if mc_else mc_for mc_while mc_in mc_range mc_and mc_or mc_not
%token  <type>  mc_int mc_float mc_char mc_bool 
%token  colon comma assign openParenthesis closeParenthesis openBracket closeBracket
%token  <str>   idf
%token  lessOrEqual greatOrEqual less great equal notEqual
%token  pls min divs mul
%token  <valtype>   integer real character booleen

%type   <valtype>   Val logicExpression Operand arithmeticExpression comparisonExpression
%type   <type>      type

%right  assign
%right  mc_not
%left   mc_and mc_or
%left   lessOrEqual greatOrEqual less great equal notEqual
%left   pls min
%left   mul divs

%%
Prog    : Instruction Prog
        |
;
Instruction     : Declaration 
                | Assignment 
                | IF
                | WHILE
                | FOR
;
Declaration     : type ListDeclaration
                | type idf tab
                
;
ListDeclaration : idf comma ListDeclaration
                | idf assign Val comma ListDeclaration
                | idf
                | idf assign Val
;
Assignment      : idf assign Val
                {
                        if(get_sym($1)==NULL)
                        {
                                printf("idf new dec\n");
                                put_sym($1);
                                install_type($1, $3.type);
                                install_value($1, $3);
                        }else{
                                printf("idf exists\n");
                                if(get_sym($1)->type==$3.type)
                                {
                                        install_value($1, $3);
                                }else{
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d type incompatibe\n", nb_ligne, nb_colone);YYABORT;
                                }
                        }
                }
                | idf openBracket intOridf closeBracket assign Val
;
Val     : Operand 
        {
                $$=$1;
        }
        | character {$$=$1;}
;

intOridf        : integer
                | idf
;
type    : mc_int {$$ = $1;}
        | mc_float {$$ = $1;}
        | mc_char {$$ = $1;}
        | mc_bool {$$ = $1;}
;
tab     : openBracket integer closeBracket
;

IF      : mc_if openParenthesis Operand closeParenthesis colon Instruction
        | mc_if openParenthesis Operand closeParenthesis colon Instruction ELSE
;
ELSE    : mc_else colon Instruction
;
WHILE   : mc_while openParenthesis Operand closeParenthesis colon Instruction
;
FOR     : mc_for idf mc_in forType colon Instruction
;
forType : range
        | idf
;
range   : mc_range openParenthesis integer comma integer closeParenthesis
;

logicExpression : Operand mc_and Operand
                {
                        $$.type = BOOL;
                        if($1.type==BOOL && $3.type==BOOL)
                        {
                                $$.val.B = $1.val.B && $3.val.B;
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
                | Operand mc_or Operand 
                {
                        $$.type = BOOL;
                        if($1.type==BOOL && $3.type==BOOL)
                        {
                                $$.val.B = $1.val.B || $3.val.B;
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
                | mc_not Operand
                {
                        $$.type = BOOL;
                        if($2.type==BOOL)
                        {
                                $$.val.B = !$2.val.B;
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
;

comparisonExpression    : Operand equal Operand 
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I == $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I == $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F == $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F == $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand notEqual Operand
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I != $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I != $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F != $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F != $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand lessOrEqual Operand
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I <= $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I <= $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F <= $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F <= $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand greatOrEqual Operand
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I >= $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I >= $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F >= $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F >= $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand less Operand
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I < $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I < $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F < $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F < $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand great Operand
                        {
                                $$.type = BOOL;

                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.I > $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.I > $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.val.B = $1.val.F > $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.val.B = $1.val.F > $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
;

arithmeticExpression    : Operand mul Operand
                        {
                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.type = INT;
                                                $$.val.I = $1.val.I * $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.I * $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F * $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F * $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand divs Operand
                        {
                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                if($3.val.I == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        $$.type = FLOAT;
                                                        $$.val.F = $1.val.I / $3.val.I;
                                                        break;
                                                }
                                        case FLOAT:
                                                if($3.val.F == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        $$.type = FLOAT;
                                                        $$.val.F = $1.val.I / $3.val.F;
                                                        break;
                                                }
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                if($3.val.I == 0){
                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        $$.type = FLOAT;
                                                        $$.val.F = $1.val.F / $3.val.I;                                
                                                        break;
                                                }
                                        case FLOAT:
                                                if($3.val.F == 0){

                                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d division par 0.", nb_ligne, nb_colone);
                                                        YYABORT;
                                                        break;
                                                }else{
                                                        $$.type = FLOAT;
                                                        $$.val.F = $1.val.F / $3.val.F;
                                                        break;
                                                }
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand pls Operand
                        {
                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.type = INT;
                                                $$.val.I = $1.val.I + $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.I + $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F + $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F + $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
                        | Operand min Operand
                        {
                                switch($1.type){
                                case INT :
                                        switch($3.type){
                                        case INT :
                                                $$.type = INT;
                                                $$.val.I = $1.val.I - $3.val.I;
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.I - $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                case FLOAT:
                                        switch($3.type){
                                        case INT :
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F - $3.val.I;                                
                                                break;
                                        case FLOAT:
                                                $$.type = FLOAT;
                                                $$.val.F = $1.val.F - $3.val.F;
                                                break;
                                        default:
                                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                                break;
                                        }
                                        break;

                                default:
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d invalid type.\n", nb_ligne, nb_colone);YYABORT;
                                        break;
                                }
                        }
;

Operand : idf 
        {
                symrec *elem = get_sym($1);
                $$.type = elem->type;
                switch (elem->type)
                {
                case INT :
                $$.val.I = elem->value.I;
                break;
                case FLOAT :
                $$.val.F = elem->value.F;
                break;
                case CHAR :
                $$.val.C = elem->value.C;
                break;
                case BOOL :
                $$.val.B = elem->value.B;
                break;
                
                default:
                printf("ERROR: UNKNOWN TYPE");
                break;
                }
        }
        | integer 
        {
                $$ = $1;
        }
        | real
        {
                $$ = $1;
        }
        | booleen
        {
                $$ = $1;
        }
        | arithmeticExpression 
        {
                $$ = $1;
        }
        | comparisonExpression
        {
                $$ = $1;
        }
        | logicExpression
        {
                $$ = $1;
        }
        | openParenthesis Operand closeParenthesis
        {
                $$ = $2;
        }
;

%%

main()
{
        //Init_TS();
        yyparse();
        //Print_TS();
        print_table();
        if(num_errors==0){
                printf("Le programme est correcte syntaxiquement\n");
        }
}
yywrap()
{

}
yyerror ()
{ 
        num_errors++;
        printf ("ERREUR SYNTAXIQUE: ligne %d, colonne %d \n",nb_ligne,nb_colone); 
        return 1; 
}
