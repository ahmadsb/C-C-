
#include"Lion.h"
#include<iostream>
Lion::Lion(){ std::cout<<"Ctor Lion"<<std::endl;}
Lion::~Lion(){std::cout<<"Dtor Lion"<<std::endl;}
std::string Lion::print_details(){
    string str= getName() +getTypeOfFood();
    return str;
    }

std::string getName() {
return "Lion";
}
std::string getSpecies() {
return "species "
}
int getLifeExpectancy() {
return 15;
}
std::string getTypeOfFood() ={
return "apple";
}
double getSpeed() {
return 100;
}
int getDurationPregnancy(){
return 20;
}
int getYoungBorn(){
    return 20;
}