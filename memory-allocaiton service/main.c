#include <stdio.h>
#include"MemoryAllocator.h"
int main(){
    char arr[4096];// divided into Allignment
    MemoryAllocator* ma = MemoryAllocator_init(&arr,4096 );
    char* p =MemoryAllocator_allocate(ma,8);
    printf("%p",p);
    MemoryAllocator_free(ma,&arr);
    return 0;
}