#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

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
