%{
    int nb_ligne = 1;
    int nb_colone = 1;
    int qc = 0;
    char tmp[20];
    int yyerror();

    int sauv_debut_while = 0;
    int sauv_debut_if = 0;
    int sauv_fin_if = 0;
    int sauve_debut_for = 0;
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
%token  mc_if mc_else mc_for mc_while mc_in mc_range mc_and mc_or mc_not newLine ident
%token  <type>  mc_int mc_float mc_char mc_bool 
%token  colon comma assign openParenthesis closeParenthesis openBracket closeBracket
%token  <str>   idf
%token  lessOrEqual greatOrEqual less great equal notEqual
%token  pls min divs mul
%token  <valtype>   integer real character booleen

%type   <valtype>       Val logicExpression Operand arithmeticExpression comparisonExpression
%type   <type>          type
%type   <str>           intOridf

%right  assign
%right  mc_not
%left   mc_and mc_or
%left   lessOrEqual greatOrEqual less great equal notEqual
%left   pls min
%left   mul divs

%%
Prog    : newLines prog_Instructions {printf("End Prog\n");}
        | prog_Instructions {printf("End Prog\n");}
;

newLines : newLine newLines
        | newLine
;

prog_Instructions       : Instruction prog_Instructions 
                        | Instruction
;
Instruction     : Declaration newLines
                | Assignment newLines
                | WHILE
                | IF
                | FOR 
;
Declaration     : type ListDeclaration
                {       
                        int i;
                        for(i=return_top(); i>=0; i--)
                        {
                                char * tempstr = (char *)pop();
                                
                                if(get_sym(tempstr)->type == NOTYPE){
                                        install_type(tempstr, $1);
                                }
                                if(get_sym(tempstr)->type != $1){
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d, declaration type dont match constant type.\n", nb_ligne, nb_colone);YYABORT;
                                }

                        }
                }
                | type idf
                {
                        if(get_sym($2)==NULL)
                        {
                                put_sym($2);
                                install_type($2, $1);
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        } 
                }tab{
                        
                        quadr("ADEC", $2, "vide", "vide");
                }
                
;
ListDeclaration : idf comma 
                {
                        if(get_sym($1)==NULL)
                        {
                                put_sym($1);
                                push($1);
                                quadr("=","temp", "vide", $1 );
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                } ListDeclaration
                | idf assign Val comma
                {
                        if(get_sym($1)==NULL)
                        {
                                put_sym($1);
                                install_type($1, $3.type);
                                install_value($1, $3);
                                printf("val=%d, type = %c\n", $3.val.I, $3.type);
                                push($1);
                                quadr("=","temp", "vide", $1 );

                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                } ListDeclaration
                | idf
                {
                        if(get_sym($1)==NULL)
                        {
                                put_sym($1);
                                push($1);
                                quadr("=","temp", "vide", $1 );
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
                | idf assign Val 
                {
                        if(get_sym($1)==NULL)
                        {
                                put_sym($1);
                                install_type($1, $3.type);
                                install_value($1, $3);
                                push($1);
                                quadr("=","temp", "vide", $1 );

                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
;
Assignment      : idf assign Val
                {
                        if(get_sym($1)==NULL)
                        {
                                put_sym($1);
                                install_type($1, $3.type);
                                install_value($1, $3);

                                quadr("=","temp", "vide", $1 );
                        }else{
                                if(get_sym($1)->type==$3.type)
                                {
                                        install_value($1, $3);

                                        quadr("=","temp", "vide", $1 );
                                }else{
                                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d type incompatibe\n", nb_ligne, nb_colone);YYABORT;
                                }
                        }
                }
                | idf openBracket intOridf closeBracket assign Val {
                        if(get_sym($1)==NULL)
                        {
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, variable already declared.\n", nb_ligne, nb_colone);YYABORT;
                        }

                        if(get_sym($1)->type==$6.type)
                        {
                                sprintf(tmp, "%s[%s]", $1, $3);
                                quadr("=","temp", "vide", tmp);
                        }else{
                                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, type incompatibe.\n", nb_ligne, nb_colone);YYABORT;
                        }
                }
;
Val     : Operand 
        {
                $$=$1;
        }
        | character {$$=$1;}
;

intOridf        : integer
                {
                        sprintf(tmp, "%d", $1.val.I);
                        $$ = strdup(tmp);
                }
                | idf 
                {
                        $$ = strdup($1);
                }
;
type    : mc_int {$$ = $1;}
        | mc_float {$$ = $1;}
        | mc_char {$$ = $1;}
        | mc_bool {$$ = $1;}
;
tab     : openBracket integer closeBracket
        {
                int max = $2.val.I;
                int i;
                
                for(i = 0; i<max; i++)
                {
                        sprintf(tmp, "%d", i);
                        quadr("BOUNDS", tmp, "vide", "vide");
                }
                        
        }
;

IF      : IF_STAT ELSE {
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_fin_if, 1, tmp);
        }
        | IF_STAT {
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_fin_if, 1, tmp);
        }
;
IF_STAT : IF_COND block_Instructions 
        {
                sauv_fin_if = qc;
                quadr("BR", "fin", "vide", "vide");

                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_debut_if, 1, tmp);
        }
;
IF_COND : mc_if openParenthesis Operand closeParenthesis colon newLine
        {
                sauv_debut_if = qc;
                quadr("BZ", "fin", "condition.temp", "vide");

                if($3.type != BOOL)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d type incompatibe\n", nb_ligne, nb_colone);YYABORT;
                }
        }
;
ELSE    : mc_else colon newLine block_Instructions
;

WHILE   : WC block_Instructions
        {
                sprintf(tmp, "%d", sauv_debut_while);
                quadr("BR", tmp, "vide", "vide");
                sprintf(tmp, "%d", qc);
                ajour_quad(sauv_debut_while, 1, tmp);
        }
;
WC      : mc_while openParenthesis Operand closeParenthesis colon newLine
        {
                sauv_debut_while = qc; 
                quadr("BZ", "fin", "condition.temp", "vide");
        }
;


FOR     : forType colon newLine block_Instructions{
        sprintf(tmp, "%d", sauve_debut_for);
        quadr("BR", tmp, "vide", "vide");
        sprintf(tmp, "%d", qc);
        ajour_quad(sauve_debut_for, 1, tmp);
}
;
forType : for_idf range
        | for_idf idf 
        {
                if(get_sym($2)==NULL)
                {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, identificateur non declarer.\n", nb_ligne, nb_colone);YYABORT; 
                }
        }
;
range   : mc_range openParenthesis integer comma integer closeParenthesis {
        if($3.type != INT || $5.type != INT)
        {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, range must be of type int.\n", nb_ligne, nb_colone);YYABORT;
        }
        if($3.val.I > $5.val.I)
        {
                printf("ERROR SEMENTIQUE: ligne %d, colonne %d, negative range not allowed.\n", nb_ligne, nb_colone);YYABORT;
        }

        quadr("=", "rangeMin" ,"vide", "idf");
        sauve_debut_for = qc;
        quadr("BG" ,"fin", "idf", "rangeMax");
}
;
for_idf : mc_for idf mc_in {
        if(get_sym($2)==NULL)
        {
               printf("ERROR SEMENTIQUE: ligne %d, colonne %d, identificateur non declarer.\n", nb_ligne, nb_colone);YYABORT; 
        }else{
                if(get_sym($2)->type != INT)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d, invalid type in for loop.\n", nb_ligne, nb_colone);YYABORT; 
                }
        }
}
;

block_Instructions      : ident Declaration newLines block_Instructions
                        | ident Declaration newLines 
                        | ident Assignment newLines block_Instructions
                        | ident Assignment newLines 
;

logicExpression : Operand mc_and Operand
                {
                        $$.type = BOOL;
                        if($1.type==BOOL && $3.type==BOOL)
                        {
                                $$.val.B = $1.val.B && $3.val.B;

                                int sauv_bz1 = qc;
                                quadr("BZ", "vide", "opd1", "vide"); 

                                int sauv_bz2 = qc;
                                quadr("BZ", "vide", "opd2", "vide"); 

                                quadr("=", "1", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz1, 1, tmp);
                                ajour_quad(sauv_bz2, 1, tmp);
                                quadr("=", "0", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
                                
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

                                int sauv_bnz1 = qc;
                                quadr("BNZ", "vide", "opd1", "vide"); 

                                int sauv_bnz2 = qc;
                                quadr("BNZ", "vide", "opd2", "vide"); 

                                quadr("=", "0", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bnz1, 1, tmp);
                                ajour_quad(sauv_bnz2, 1, tmp);
                                quadr("=", "1", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                int sauv_bz = qc;
                                quadr("BZ", "vide", "opd", "vide"); 

                                quadr("=", "0", "vide", "temp");

                                int sauv_br = qc;
                                quadr("BR", "vide", "vide", "vide"); 
                                
                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=", "1", "vide", "temp");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);

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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BZ", "faux", "T0", "vide");

                                quadr("=", "1", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","0","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BMZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BPZ", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BM", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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

                                quadr("-","opd1","opd2","T0");

                                int sauv_bz = qc;
                                quadr("BP", "vrai", "T0", "vide");

                                quadr("=", "0", "vide", "T1");

                                int sauv_br = qc;
                                quadr("BR","fin","vide","vide");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_bz, 1, tmp);
                                quadr("=","1","vide","T1");

                                sprintf(tmp, "%d", qc);
                                ajour_quad(sauv_br, 1, tmp);
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
                                
                                quadr("*","opd1","opd2","temp");
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
                                quadr("/","opd1","opd2","temp");
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

                                quadr("+","opd1","opd2","temp");
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

                                quadr("-","opd1","opd2","temp");
                        }
;

Operand : idf 
        {
                symrec *elem = get_sym($1);
                if(elem == NULL)
                {
                        printf("ERROR SEMENTIQUE: ligne %d, colonne %d variable (%s) not declared.\n", nb_ligne, nb_colone, $1);YYABORT;
                }else{
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
                        printf("ERROR: UNKNOWN TYPE\n");
                        break;
                        }
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
        Init_TS();
        yyparse();
        print_table();
        Print_TS();
        afficher_qdr();
}
yywrap()
{

}
int yyerror (char *msg)
{
        printf ("ERREUR SYNTAXIQUE: ligne %d, colonne %d \n",nb_ligne,nb_colone); 
        exit(0);
}
