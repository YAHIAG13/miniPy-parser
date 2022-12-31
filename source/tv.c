#include"tv.h"

void install_value (const char * name, vt valtype){

    symrec *elem = get_sym(name);
    switch (elem->type)
        {
        case INT :
            elem->value.I = valtype.val.I;
            break;
        case FLOAT :
            elem->value.F = valtype.val.F;
            break;
        case CHAR :
            elem->value.C = valtype.val.C;
            break;
        case BOOL :
            elem->value.B = valtype.val.B;
            break;
        
        default:
            printf("ERROR: UNKNOWN TYPE\n");
            break;
        }
}

symrec * put_sym (char const *name)
{
    symrec *elem = (symrec *)malloc(sizeof(symrec));
    elem->name = strdup(name);
    elem->type = NOTYPE;

    elem->next = sym_table;
    sym_table = elem;
    return sym_table;
}


symrec * get_sym (char const *name)
{
    symrec *elem ;
    for ( elem = sym_table; elem; elem = elem->next)
    {
        if (strcmp (elem->name, name) == 0)
            return elem;
    }

    return NULL;
}


void print_table()
{   
    
    symrec *elem ;
    printf("\nVariables Table :\n");
    for (elem = sym_table; elem!=NULL; elem = elem->next)
    {
        printf("|%15s | %15c |", elem->name, elem->type);
        switch (elem->type)
        {
        case INT :
            printf(" %15d |\n", elem->value.I);
            break;
        case FLOAT :
            printf(" %15f |\n", elem->value.F);
            break;
        case CHAR :
            printf(" %15c |\n", elem->value.C);
            break;
        case BOOL :
            printf(" %15s |\n", elem->value.B ? "true" : "false");
            break;
        
        default:
            printf("ERROR: UNKNOWN TYPE\n");
            break;
        }
    }
    printf("\n");
}

void install_type(char const *name, char type)
{
    symrec *elem = get_sym(name);
    elem->type = type;
    switch (elem->type)
    {
    case INT :
        elem->value.I = 0;
        break;
    case FLOAT :
        elem->value.F = 0;
        break;
    case CHAR :
        elem->value.C = '0';
        break;
    case BOOL :
        elem->value.B = false;
        break;

    default:
        printf("ERROR: UNKNOWN TYPE\n");
        break;
    }
}
