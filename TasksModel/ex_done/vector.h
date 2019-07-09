#ifndef VECTOR_H
#define VECTOR_H

typedef struct vector Vector;
typedef enum{FAILED = 0,SUCCESS }Err_t;
Vector* vectorGenerate(size_t capacity, int* status);
Err_t vectorDestroy(Vector** vec);
Err_t vectorPush(Vector* vec, int value); 
Err_t vectorInsert(Vector* vec, int value, int index);
Err_t vectorPop(Vector* vec);
Err_t vectorRemove(Vector* vec, int index);
Err_t vectorSetElement(Vector* vec, int value , int index);
Err_t vectorGetElement(Vector* vec, int index, int* value);
Err_t vectorGetSize(Vector* vec, int* value);
Err_t vectorGetCapacity(Vector* vec,  int* value);
Err_t printVector(Vector* vec);

#endif