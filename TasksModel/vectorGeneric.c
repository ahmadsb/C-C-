#include<stdio.h>
#include<stdlib.h>
#include"vectorGeneric.h"

typedef struct vector{
    size_t m_size;
    size_t m_capacity;
    void** m_values;
}Vector;

static int isPowerOfTwo(int n);
static unsigned int smallPowerOf2(unsigned int n); 
// static int vector_empty(Vector* vec, int* status);

Vector* vectorGenerate(size_t capacity , int* status){
    if(capacity == 0)
    {
        printf("Sorry, You can not enter a zero value");
        return NULL;
    }
    if( !isPowerOfTwo(capacity))
        capacity = smallPowerOf2(capacity);

    Vector* temp = (Vector*)malloc(sizeof(Vector));
    if(!temp){
        *status = FAILED;
        return NULL;
    }
    temp->m_values = malloc(sizeof(temp->m_values) * capacity);
    temp->m_capacity = capacity;
    temp->m_size = 0;
    *status = SUCCESS;
    return temp;
}

Err_t vectorDestroy(Vector** ptr_vec){
    if(!(*ptr_vec))
        return FAILED;
    free((*ptr_vec)->m_values);
    free((*ptr_vec));
    *ptr_vec = 0;
    return SUCCESS;
}
// type int*, double* , double
Err_t vectorPush(Vector* vec, void** value){
    if(vec->m_size >= vec->m_capacity){
        vec->m_values =  realloc(vec->m_values,sizeof(*value) * (vec->m_capacity *= 2));
        if(!vec->m_values)
            return FAILED;   
    }
    // vec->m_values[vec->m_size] = value;
    vec->m_values[vec->m_size++] = value;
    return SUCCESS;
}


// Err_t vectorInsert(Vector* vec, int value, int index){
//     int i = 0;
//     if(vec->m_size >= vec->m_capacity){
//         vec->m_values =  (int*) realloc( vec->m_values,sizeof(int) *( vec->m_capacity *= 2));
//         if(!vec->m_values)
//             return FAILED;
//     }
//     ++vec->m_size;
//     for(i = vec->m_size - 1 ; i > index ; --i)
//         vec->m_values[i] = vec->m_values[i-1];
//     if( i == index)
//         vec->m_values[i] = value;
//     return SUCCESS;
    
// }


// Err_t vectorPop(Vector* vec){
//     if(vec->m_size > 0){
//         vec->m_values[vec->m_size--] = 0;//?
//         return SUCCESS;
//     }
//     return FAILED;
// }

// Err_t vectorRemove(Vector* vec, int index){
//     int temp = 0;
//     int i = 0;
//     if( 0 <= index < vec->m_size){
//     for( i = index; i < vec->m_size-1 ; ++i)
//         vec->m_values[i] = vec->m_values[i+1];
//     vec->m_size--;
//         return SUCCESS;
//     }
//     return FAILED;
    
// }
// int vectorGetElement(Vector* vec, int index, int* status){
//     if( 0 <= index < vec->m_size){
//         *status = SUCCESS;
//          return vec->m_values[index];
//     }
//     *status = FAILED;
    
// }
// Err_t vectorSetElement(Vector* vec, int value , int index){
//     if( 0 <= index < vec->m_size){
//         vec->m_values[index] = value;
//         return SUCCESS;
//     }
//     return FAILED;
    
// }
// size_t vectorGetSize(Vector* vec, int* status){
//     if(!vector_empty(vec,status))
//         return 0;
//     return vec->m_size;
// }
// size_t vectorGetCapacity(Vector* vec, int* status){
//     if(!vector_empty(vec,status))
//         return 0;
//     return vec->m_capacity;
//     }
// Err_t printVector(Vector* vec){
//     size_t i ;
//     if(!vec)
//         return FAILED;
//     for(i = 0; i < vec->m_size - 1 ; ++i)
//         printf("%d->", vec->m_values[i]);
//     if( i == vec->m_size - 1)
//         printf("%d\n", vec->m_values[i]);
//     return SUCCESS;
// }










int isPowerOfTwo(int n) { 
  if (n == 0) 
    return 0; 
  while (n != 1) 
  { 
      if (n%2 != 0) 
         return 0; 
      n = n/2; 
  } 
  return 1; 
} 
unsigned int smallPowerOf2(unsigned int n) { 
    unsigned int p = 1; 
    if (n && !(n & (n - 1))) 
        return n; 
  
    while (p < n)  
        p <<= 1; 
      
    return p/2; 
} 
int vector_empty(Vector* vec, int* status){
    if(!vec){
        *status = FAILED;
        return 0;
    }
    *status = SUCCESS;
    return 1;
}