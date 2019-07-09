#ifndef MEMORY_ALLOCATOR_H
#define MEMORY_ALLOCATOR_H
#include <stdio.h>
typedef struct MemoryAllocator MemoryAllocator;
#define ALLIGNMENT ((char*) (&s.u.l) - (& s.c) ) // windows. 64
// #define _get_pool_addr(p) ((p) - sizeof(MemoryAllocator))


/* memoryPool is a ptr to an already-existing large memoryblock */
MemoryAllocator* MemoryAllocator_init(void* memoryPool, size_t size);

/* Returns a ptr to the memoryPool */
void* MemoryAllocator_release(MemoryAllocator* allocator);

void* MemoryAllocator_allocate(MemoryAllocator* allocator, size_t size);

void MemoryAllocator_free(MemoryAllocator* allocator, void* ptr);

/* Merges all adjacent free blocks, and returns the size of largest free block */
size_t MemoryAllocator_optimize(MemoryAllocator* allocator);

#endif