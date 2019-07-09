#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void my_swap(void* a,void* b, size_t n)  
{ 
    void* temp = malloc(n); //  malloc returns void* 
    memcpy(temp,    b,      n); 
    memcpy(b,      a,       n); 
    memcpy(a,      temp,    n); 
    free(temp);
} 
int main(){
    int a = 5, b = 3;
    printf("Before:\n a = %d, b=%d\n",a,b);
    my_swap(&a, &b , sizeof(a));
    printf("After:\n a = %d, b=%d\n",a,b);


    return 0;
}