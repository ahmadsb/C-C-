#include<stdio.h>
#include"vectorGeneric.h"

int main(){
    int status;
    Vector* v = vectorGenerate(4, &status);
    if(status)
        printf("create vector\n");
    
    if(vectorPush(v, 10))
        printf("yes push\n");
    if(vectorDestroy(&v))
        printf("done\n");
    return 0;
}