#ifndef SHELF_H
#define SHELF_H
#include"box.h"
#include<string.h>


#define NUM_BOXES 3
#define SIZE_MSG 256
#define DEF_MSG "The total volume held on the shelf is"

char message[SIZE_MSG];
static void setMessage(char* msg)
{
    strcpy(message ,msg);
}

typedef struct {
    Box boxes[NUM_BOXES];
}shelf;



void init_shelf(shelf*const s);

void setBox(shelf*const s,int index, Box*const b);
// double const getVolumeOfShelf();
// Box* getBox(shelf*const s, int index);
void const print_shelf(shelf*const s);

#endif





