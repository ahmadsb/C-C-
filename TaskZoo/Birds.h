#ifndef BIRDS_H
#define BIRDS_H
#include "Animal.h"
class Birds : public Animal
{
private:
  double m_typical_height;
  double m_wing_span;

public:
  Birds(std::string name,
        std::string species,
        int life_expectancy,
        std::vector<std::string> places,
        std::string food_type,
        double speed,
        double typical_height,
        double wing_span);
  ~Birds();
  virtual void print_details() const = 0;
};
#endif