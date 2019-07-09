#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* my_strncpy(char* dest, const char* src, int len )
{  
    char* temp = dest;
    while(*dest++ = *src++);

    return temp;
}

int main(){

    printf("ex3 -model \n");
    char  str[]= "Ahmad";
    char  str2[] = "ASSSd";
    printf("the first string befor strcpy %s \n",str );
    char* str3 = my_strncpy(str, str2, 5);
    printf("the first string after strcpy %s \n",str3 );


    return 0;
}