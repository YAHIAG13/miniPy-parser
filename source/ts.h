#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<assert.h>

#define EV 0
#define ES 1
#define EM 2


//ts pour variables
typedef struct
{
    int state;
    char name[20];
    char code[20];
    char type[20];
    float val;
} elmv;
//ts pour separateurs et mc 
typedef struct
{ 
   int state; 
   char name[20];
   char type[20];
} elmsm;

//declaration des tables
elmv tabv[1000]; //variables
elmsm tabs[40]; //separateurs
elmsm tabm[40]; //mot cle
int cptv, cpts, cptm; //compteurs

//initialistation
void Init_TS(){
    cptv = 0;
    cpts = 0;
    cptm = 0;
    int i;

    for(i=0; i<1000; i++){
        tabv[i].state = 0;
    }

    for(i=0; i<40; i++){
        tabs[i].state = 0;
        tabm[i].state = 0;
    }
}

void Add_TS(char name[], char code[], char type[], float val, int i,const int typeE){
    switch(typeE){
        case EV:
            tabv[i].state = 1;
            strcpy(tabv[i].name,name);
            strcpy(tabv[i].code,code);
            strcpy(tabv[i].type,type);
            tabv[i].val = val;
            cptv++;
            break;
        case ES:
            tabs[i].state = 1;
            strcpy(tabs[i].name,name);
            strcpy(tabs[i].type,type);
            cpts++;
            break;
        case EM:
            tabm[i].state = 1;
            strcpy(tabm[i].name,name);
            strcpy(tabm[i].type,type);
            cptm++;
            break;
    }
}

void Find_TS(char name[], char code[], char type[], float val, const int typeE){
    int i;
    switch(typeE){
        case EV:
            if(cptv==0){
                Add_TS(name, code, type, val, 0, EV);
            }else{
                for (i=0; ((i<1000)&&(tabv[i].state==1))&&(strcmp(name,tabv[i].name)!=0); i++);
				if(i<1000)
				{
				    Add_TS(name,code,type,val,i,EV);     
				}
				else printf("Entite %s existe deja\n",name);
            }
            break;
        case ES:
            if(cpts==0){
                Add_TS(name, code, type, val, 0, ES);
            }else{
                for (i=0; ((i<40)&&(tabs[i].state==1))&&(strcmp(name,tabs[i].name)!=0); i++);
				if(i<40)
				{
				    Add_TS(name,code,type,val,i,ES);     
				}
				else printf("Entite %s existe deja\n",name);
            }
            break;
        case EM:
            if(cptm==0){
                Add_TS(name, code, type, val, 0, EM);
            }else{
                for (i=0; ((i<40)&&(tabm[i].state==1))&&(strcmp(name,tabm[i].name)!=0); i++);
				if(i<40)
				{
				    Add_TS(name,code,type,val,i,EM);     
				}
				else printf("Entite %s existe deja\n",name);
            }
            break;
    }
}
void Print_TS(){
    int i;
    printf("\n");
    printf("    ||*************** Table des symboles IDF **************||\n");
    printf("    _________________________________________________________\n");
    printf("    | Nom_Entite |  Code_Entite |  Type_Entite | Val_Entite |\n");
    printf("    _________________________________________________________\n");
    for(i=0;i<cptv;i++)
    {	
        if(tabv[i].state==1)
        { 
    printf("    |%11s |%13s |%13s |%11f |\n", tabv[i].name, tabv[i].code, tabv[i].type, tabv[i].val);
        }
    }
    printf("\n");
    printf("    ||************ Table des symboles mots cles ***********||\n");
    printf("    _________________________________________________________\n");
    printf("    | NomEntite                 | CodeEntite                |\n");
    printf("    _________________________________________________________\n");
  
    for(i=0;i<cptm;i++) {
        if(tabm[i].state==1)
        { 
            printf("    |%26s |%26s | \n", tabm[i].name, tabm[i].type);     
        }
    }

    printf("\n");
    printf("    ||*********** Table des symboles separateurs **********||\n");
    printf("    _________________________________________________________\n");
    printf("    | NomEntite                 | CodeEntite                |\n");
    printf("    _________________________________________________________\n");
  
    for(i=0;i<cpts;i++){

        if(tabs[i].state==1)
        { 
            printf("    |%26s |%26s | \n", tabs[i].name, tabs[i].type);
        }
    }
}
