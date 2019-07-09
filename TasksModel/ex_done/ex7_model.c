#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* my_strcat(char* dest, const char* src )
{  
    char* temp = dest;
    dest = dest + strlen(dest);
    while(*dest++ = *src++);
    return temp;
}

int main(){
    char str[] = "ahmad" ;
    char str2[] = "sabbah" ;
    strcat(str,str2);
    printf("the first string after strcat %s \n",str);


    return 0;
}