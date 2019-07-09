#include"shelf.h"
#include<stdlib.h>
#include<string.h>
#include<stdio.h>


void init_shelf(shelf*const s){
    for (int i = 0 ; i<NUM_BOXES ; i++){
        init_box_one_pram(&(s->boxes[i]) , 1);
    }
    strcpy(message ,DEF_MSG);
}
   
   

void setBox(shelf*const s, int index, Box*const b){
    Box bBox =s->boxes[index];
    copy_ctor(&bBox , b);
}
// double  getVolumeOfShelf(shelf*const  s){
//     double temp = 0,res = 0;
    
//     for (int i = 0; i < NUM_BOXES; i++){
//         temp = (s->boxes[i].height * s->boxes[i].length *s->boxes[i].width);
//         printf("hereeeeeee %f\n",temp);
//         res+=temp;
//     }
//     return res;
// }

// Box* getBox(shelf*const s, int index)
// {
// return s->boxes[index];
// }

void const print_shelf(shelf*const s){
    double res =0;
    for (int i = 0; i < NUM_BOXES; i++){
        res+=(s->boxes[i].height * s->boxes[i].length *s->boxes[i].width);
    }
    printf("%s %f\n", message, res);
}

