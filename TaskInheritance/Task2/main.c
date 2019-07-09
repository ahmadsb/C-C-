#include<stdio.h>
#include"box.h"
#include"shelf.h"

void thisFunc();
void thatFunc();
void doBoxes();
void doShelves();

int main(){

   
    
    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();
        
    printf("\n--- End main() ---\n\n");

    return 1;
}
// static variable object box*
void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n"); 
    Box box99;
    init_box(&box99, 99, 99, 99); // ?? static ctor in cpp how convert to c
 

    mult_box(&box99, 10);
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n"); 
    Box box88;
    init_box(&box88, 88, 88, 88); // ?? static ctor
    mult_box(&box88, 10);
}

void doBoxes()
{
    printf("\n--- Start doBoxes() ---\n\n");

    Box  b1;
    init_box_one_pram(&b1,3);//&b
    Box b2;
    init_box(&b2, 4, 5, 6);
    /*here we used b1->.. .. not fun. getVoulme becuase --> inline(cpp) here c*/
    printf("b1 volume: %f\n", b1.length * b1.length *b1.width );
    printf("b2 volume: %f\n", b2.length*  b2.height *b2.width );

    mult_box(&b1, 1.5);
    mult_box(&b2, 0.5);

    printf("b1 volume: %f\n",  b1.length * b1.length *b1.width);
    printf("b2 volume: %f\n", b2.length*  b2.height *b2.width );

    Box b3;
    // defualt ctor --> gets 1 in language c there isn't defualt variable pram.
    init_box_one_pram(&b3,1);
    copy_ctor(&b3, &b2);
    // mult_box(&b2, 3);
    Box b4;
    init_box_one_pram(&b4, 1);
    copy_ctor(&b4, &b2);

    printf("b3 %s b4\n", if_equal_boxes(&b3, &b4) == True ? "equals" : "does not equal");
    mult_box(&b3, 1.5);
    mult_box(&b4, 0.5);

    printf("Now, b3 %s b4\n", if_equal_boxes(&b3, &b4) == True ?"equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    delete_box(&b4);
    delete_box(&b3);
    delete_box(&b2);
    delete_box(&b1);

}

void doShelves()
{
    printf("\n--- start doShelves() ---\n\n");

    Box aBox;
    init_box_one_pram(&aBox, 5);
    shelf aShelf ;
    init_shelf(&aShelf);
    print_shelf(&aShelf);
  
    // setBox(aShelf, 1, largeBox);
    setBox(&aShelf, 0, &aBox);

    print_shelf(&aShelf);
    setMessage( "This is the total volume on the shelf:");
    print_shelf(&aShelf);
    setMessage( "Shelf's volume:");
    print_shelf(&aShelf);
    Box bBox ;
    
    init_box(&bBox, 2, 4, 6);
    setBox(&aShelf, 1, &bBox);
    Box cBox;
    init_box_one_pram(&cBox, 2);
    setBox(&aShelf, 2, &cBox);
    print_shelf(&aShelf);

    printf("\n--- end doShelves() ---\n\n");
}


