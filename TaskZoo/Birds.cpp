#include"Birds.h"
#include"Animal.h"
#include<iostream>

Birds::Birds(   std::string name, 
                std::string species,
                int life_expectancy,
                std::vector<std::string> places,
                std::string food_type,
                double speed,
                double typical_height,
                double wing_span
            )
            :Animal(name, species, life_expectancy, places, food_type, speed),
            m_typical_height(typical_height),
            m_wing_span(wing_span)
{}
Birds::~Birds(){
    std::cout<<"Dtor Birds"<<std::endl;
}
