#include<stdio.h>
#include<string.h>
#include<stdlib.h>
// void* dest, int*psize,
void my_forEach( void* dest2, int size, void (*functionPtr)(void*))
{  
    int* dest= (int*) dest2;
    for(size_t i =0;  i< size ; i++){
        functionPtr(&dest[i]);
    }

}
void FOO(void* e){
    int* temp = (int*) e;
    *temp= (*temp) * (*temp);
}
void BAR(void* e){
    int* temp = (int*) e;
    *temp = (*temp) * (*temp);

}

int main(){
    // char* p ="helo";
    // p[2] = '2'; not work..> bug
    // printf("start %p\n",(int)(*(char*)FOO));// &FOO === FOO
    // bar = foo , (*bar)(3,7)
    int size = 4;
    int dest[] = {1,2,3,4};

    // my_forEach(dest, size ,FOO);
    // for(int j =0; j< size ; j++){
    //     printf("here : %d\n",dest[j] );
    // }
    // printf("==========\n");
    // my_forEach(dest, size , BAR);

    // for(int j =0; j< size ; j++){
    //     printf("here : %d\n",dest[j] );
    // }



    return 0;
}