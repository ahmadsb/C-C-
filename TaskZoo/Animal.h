#ifndef ANIMALS_H
#define ANIMALS_H
#include<iostream>
#include <vector>
class Animal{
    public:
        Animal();
        virtual ~Animal();

        virtual std::string print_details();
        
        virtual std::string getName() = 0;
        virtual std::string getSpecies() = 0;
        virtual int getLifeExpectancy() = 0;
        virtual std::string getTypeOfFood() = 0;
        virtual double getSpeed() = 0;

       

        };

#endif
