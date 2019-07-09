#include<stdio.h>
// ( ) of result SIZEOF_T important
#define SIZEOF_T(var_type) \
    ((char*)( (var_type*)0 + 1 ) - (char*)0  ) \
    // -(char*)0 casting from char* to ld 'size_t'

int main()
{
    int a = 5;
    printf("sizeof of variable is : %ld\n",   SIZEOF_T(double)  ) ;

    return 0;
}