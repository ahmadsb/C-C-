#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* my_strcpy(char dest[], const char src[]  )
{  
    char* temp = dest;
    size_t i =0 ;
    for(; i< strlen(src); i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';


    return temp;
}

int main(){

    printf("ex3 -model \n");
    char  str[]= "Ahmad";
    char  str2[] = "ASSSd";
    printf("the first string befor strcpy %s \n",str );
    char* str3 = my_strcpy(str, str2);
    printf("the first string after strcpy %s \n",str3 );


    return 0;
}