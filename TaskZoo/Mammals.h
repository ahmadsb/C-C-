#ifndef MAMMALS_H
#define MAMMALS_H
#include "Animal.h"
class Mammals : public Animal
{

  public:
    Mammals();
    ~Mammals();
    std::string print_details();
    virtual int getDurationPregnancy() = 0;
    virtual int getYoungBorn() = 0; //  pure virtual
};

#endif