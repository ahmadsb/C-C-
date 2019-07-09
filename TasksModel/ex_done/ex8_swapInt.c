#include<stdio.h>

void swap(int* a , int* b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}
int main(){
    int a = 5, b = 3;
    printf("Before:\n a = %d, b=%d\n",a,b);
    swap(&a, &b);
    printf("After:\n a = %d, b=%d\n",a,b);


    return 0;
}