#include"box.h"
#include<stdlib.h>
#include<stdio.h>




void init_box(Box*const b,double width, double height, double length){
    b->height = height;
    b->length = length;
    b->width =  width;
    print_box(b);
}
void init_box_one_pram(Box*const b,double dim){
    b->height = dim;
    b->length = dim;
    b->width  = dim;
    print_box(b);
}
// box* create1_box(double width, double height, double length){
//     box* b=(box*)malloc(sizeof(box));
//     b->height = height;
//     b->width = width;
//     b->length = length;
//     print(b);
//     return b;
// }
// box* create2_box(double dim ){
//     box* b =(box*)malloc(sizeof(box));
//     b->height = dim;
//     b->length =dim;
//     b->width =dim;
//     print(b);
//     return b;
// }
// box* create_defualt_box( ){
//     box* b =(box*)malloc(sizeof(box));
//     b->height = 1;
//     b->length =1;
//     b->width =1;
//     print(b);
//     return b;
// }
void delete_box(Box* const b){
   printf("Box destructor, %f x %f x %f\n", b->height, b->length, b->width);
}

/*don't need getVolume --> fun. inline*/
// double const getVolume(box* b) {
//     return b->width * b->length * b->height;
// }
//pointer const
void mult_box(Box* const b,double mult){
    b->width *= mult;
    b->height *= mult;
    b->length *= mult;
}

void const print_box(Box*const b){
    printf("Box: %f x %f x %f\n",b->width,b->height, b->length); 
}

int if_equal_boxes(Box*const b1, Box*const b2){
    if(b1->height == b2->height &&
                 b1->length == b2->length &&
                         b1->width == b2->width)
                         return True;
    return False;
}
int if_not_equal_boxes(Box*const b1, Box*const b2){
    if (if_equal_boxes(b1,b2) == True)
        return False;
    return True;
}
void copy_ctor(Box*const b1 , Box*const b2){
    b1->height = b2->height;
    b1->width = b2->width;
    b1->length = b2->length;
    print_box(b1);
    print_box(b2);
}