#ifndef BOX_H
#define BOX_H
#define True 1
#define False 0




typedef struct{
    double width;
    double height;
    double length;
    
}Box;
/*init ctor don't need to use in mempry heap 'malloc' */
void init_box(Box*const b,double width, double height, double length);
void init_box_one_pram(Box*const b,double dim);

void delete_box(Box*const b);
// pram: const box* const b
// getVolume --> fun. inline in cpp ,so don't need to use it
// double  getVolume  (box * b ) ;

void mult_box(Box* const b, double mult);

void const print_box(Box*const b);


// Box operator*( Box* const box, double mult);
// Box operator*(double mult, const Box& box);

int if_equal_boxes(Box* const  b1, Box* const b2);
int if_not_equal_boxes(Box* const b1, Box* const b2);

void copy_ctor(Box*const b1 , Box*const b2);


#endif