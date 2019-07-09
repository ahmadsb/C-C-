#ifndef FISH_H
#define FISH_H

#include"Animal.h"
class Fish: public Animal{
    private:
        int  m_lowest_depth;
    public:
        Fish(   std::string name, 
                std::string species,
                int life_expectancy,
                std::vector<std::string> places,
                std::string food_type,
                double speed,
                int lowest_depth
            );
        ~Fish();
        virtual void print_details() const = 0;
};
#endif