#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

#define SIZE 100


char * stack[SIZE];
int top = -1;

void push(char * string){
   if(top == SIZE-1)
      printf("\nStack is Full!!! Insertion is not possible!!!");
   else{
      top++;
      stack[top] = strdup(string);
   }
}
char * pop(){
   if(top == -1)
      printf("\nStack is Empty!!! Deletion is not possible!!!");
   else{
      top--;
      return stack[top+1];
   }
}

int return_top(){
    return top;
}

float re_atof(char *str, int strln)
{
    char *buffer;
    buffer = (char*) malloc((strln-3)*sizeof(char));
    if(str[0]=='(')
    {
        memcpy(buffer, &str[2], strln-3);
        return atof(buffer)*(-1);
    }else{
        return atof(str);
    }
    free(buffer);
}
