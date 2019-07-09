#include"Fish.h"
#include"Animal.h"
Fish::Fish  (   std::string name, 
                std::string species,
                int life_expectancy,
                std::vector<std::string> places,
                std::string food_type,
                double speed,
                int lowest_depth
            )
            :Animal(name, species, life_expectancy, places, food_type, speed),
             m_lowest_depth(lowest_depth)
{}
Fish::~Fish(){
    std::cout<<"Dtor Fish"<<std::endl;
}
