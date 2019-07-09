#include "MemoryAllocator.h"
#include<stdlib.h>
#include<string.h>
#include<assert.h>
// to calculate the allignment 
struct{
    char c;
    union{
        long l;
        size_t s;
        double d;
        long long lL;
        long double ld;
    }u;
}s;
//

struct MemoryAllocator{
    void* m_ptr;
    size_t m_size;
};

MemoryAllocator* MemoryAllocator_init(void* memoryPool, size_t size){
     if (size < 0)
    {
        printf("the size shuold be  greater than 0 ");
        return NULL;
    }

    MemoryAllocator* ma = (MemoryAllocator*)malloc(sizeof(MemoryAllocator));

    if(ma){
            ma->m_ptr = memoryPool;
            ma->m_size = size;
    }
    
    (*(char *)(ma->m_ptr)) =  ma->m_size - ALLIGNMENT;
    return ma;
}
void* MemoryAllocator_release(MemoryAllocator* allocator){
    return allocator->m_ptr;
}

void* MemoryAllocator_allocate(MemoryAllocator* allocator, size_t size)
{
    if(size < 0)
    {
        printf("the size shuold be  greater than 0 ");
        return NULL;
    }
   (*(char *)(allocator->m_ptr)) =  allocator->m_size - size - ALLIGNMENT;

   return allocator->m_ptr;
    
}

void MemoryAllocator_free(MemoryAllocator* allocator, void* ptr){
   
}
size_t MemoryAllocator_optimize(MemoryAllocator* allocator){
   
}
