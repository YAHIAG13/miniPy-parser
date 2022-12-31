#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

#define INT 'I'
#define FLOAT 'F'
#define CHAR 'C'
#define BOOL 'B'
#define NOTYPE 'N'

//table symbole dynamique
typedef struct symrec
{
    char *name; 
    char type; 
    union
    {
        int I;  
        float F;    
        bool B;
        char C;
    } value;
    struct symrec *next; 
}symrec;
symrec *sym_table;

//valtype struct
typedef struct vt
{
    char type;
    union{
        int I;  
        float F;    
        bool B;
        char C;
    }val;
}vt;

//functions
symrec * put_sym (char const *name);

symrec * get_sym (char const *name);

void install_value (const char * name, vt valtype);

void install_type(char const *name, char type);

void print_table();
