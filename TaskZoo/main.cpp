#include<iostream>
#include <vector>
#include"Animal.h"
#include"Mammals.h"
#include"Lion.h"




int main(){
    std::cout<<"Hello World!!"<<std::endl;
    Animal *l = new Lion();
    l->print_details();
    return 0;
}