#include<stdio.h>
#define SIZEOF_V(var) ((char*)(&var + 1) -  (char*)(&var))
int main(){

    int a = 5;
    // SIZEOF_V(++a) works in cpp but doesn't work in c
    // SIZEOF_V(a++)  doesn't work in c and cpp
    printf("sizeof of variable is : %ld\n",   SIZEOF_V(a));
    printf("sizeof of variable is : %ld\n",   SIZEOF_V(a)*10);


    return 0;
}