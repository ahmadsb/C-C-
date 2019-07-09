#include <cstdio>
#include "cpp2c_encapsulation_defs.h"

static Box largeBox(10, 20, 30);

void thisFunc()
{
    std::printf("\n--- thisFunc() ---\n\n"); 
    static Box box99(99, 99, 99);
    box99 *= 10;
}

void thatFunc()
{
    std::printf("\n--- thatFunc() ---\n\n"); 
    static Box box88(88, 88, 88);
    box88 *= 10;
}

void doBoxes()
{
    std::printf("\n--- Start doBoxes() ---\n\n");

    Box b1(3);
    Box b2(4, 5, 6);
    
    std::printf("b1 volume: %f\n", b1.getVolume());
    std::printf("b2 volume: %f\n", b2.getVolume());

    b1 *= 1.5;
    b2 *= 0.5;

    std::printf("b1 volume: %f\n", b1.getVolume());
    std::printf("b2 volume: %f\n", b2.getVolume());

    Box b3 = b2;
    Box b4 = 3 * b2;
    std::printf("b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");

    b3 *= 1.5;
    b4 *= 0.5;
    std::printf("Now, b3 %s b4\n", b3 == b4 ? "equals" : "does not equal");

    std::printf("\n--- End doBoxes() ---\n\n");
}


void doShelves()
{
    std::printf("\n--- start doShelves() ---\n\n");

    Box aBox = 5;

    Shelf aShelf;

    aShelf.print();
    aShelf.setBox(1, largeBox);
    aShelf.setBox(0, aBox);

    aShelf.print();
    aShelf.setMessage("This is the total volume on the shelf:");
    aShelf.print();
    Shelf::setMessage("Shelf's volume:");
    aShelf.print();

    aShelf.setBox(1, Box(2, 4, 6));

    aShelf.setBox(2, 2);
    aShelf.print();

    std::printf("\n--- end doShelves() ---\n\n");
}

int main()
{
    std::printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();
        
    std::printf("\n--- End main() ---\n\n");

    return 0;
}

