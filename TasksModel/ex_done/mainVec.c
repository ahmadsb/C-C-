#include<stdio.h>
#include"vector.h"
int main(){
    int status , value,value1,value2;
    Vector* v = vectorGenerate(2, &status);
    printf("stauts of vectorGenerate is : %d\n", status);
    
    if(vectorPush(v, 1) && vectorPush(v, 2) && vectorPush(v, 3) && vectorPush(v, 4))
        printVector(v);
   
    if(vectorGetSize(v,&value1) && vectorGetCapacity(v, &value2))
        printf("the size is %d\nthe capacity is %d\n", value1 ,value2);
    
    if(vectorRemove(v, 1) && vectorRemove(v, 3))
        printVector(v);
      
    if(vectorInsert(v, 10, 0) && vectorInsert(v, 11, 1) && vectorInsert(v, 12, 2))
        printVector(v);

    if(vectorPop(v) && vectorPop(v))
        printVector(v);

    if(vectorSetElement(v, 5, 0))
        printVector(v);

    if(vectorGetElement(v, 2, &value))
        printf("the value is %d\n", value);

    if(vectorDestroy(&v))
        printf("done!!\n");
    return 0;
}