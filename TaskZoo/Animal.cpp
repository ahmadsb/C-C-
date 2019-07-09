#include"Animal.h"

Animal::Animal(){} 

Animal::~Animal(){
    std::cout<<"Dtor. Animal"<<std::endl;
}
std::string Animal::print_details(){
    string str= getName()+getSpecies()+getTypeOfFood();
}


