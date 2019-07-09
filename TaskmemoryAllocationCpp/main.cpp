
#include <iostream>
#include "Allocator.h"
#include "person.h"
int main() {
    char buffer[32] = "ahmad";
    Person p (buffer,1,2);
    Allocator<Person,4> *p4 = new Allocator<Person,4>(p);

   // to provide : param:Person("abcd",1,2) 
   //shuold be to use  in solve (1) or sovle(2) in Allocator.h
   Allocator<Person,4> *p7 = new Allocator<Person,4>(Person("abcd",1,2));
   Allocator<Person,4> *p6 = new Allocator<Person,4>(Person("abcd",1,2));
   Allocator<Person,4> *p8 = new Allocator<Person,4>(Person("abcd",1,2));


    return 0;
}