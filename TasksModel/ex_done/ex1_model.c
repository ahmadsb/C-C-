#include<stdio.h>
size_t my_strlen(const char str[])
{   
    size_t len = 0 ;
     for ( ;str[len] ; len++ ){
         len++;
     }
     return len;
}

int main(){

    printf("ex1 -model \n");
    char str[12]= "Ahmad Sabbah";
    size_t temp = my_strlen(str);
    printf("the size of %s is : %ld \n",str , temp);


    return 0;
}