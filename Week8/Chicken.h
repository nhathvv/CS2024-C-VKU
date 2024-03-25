#ifndef _PETMANAGE_CHICKEN_H
#define _PETMANAGE_CHICKEN_H
#include "Pet.h"

class Chicken : public Pet
{
public:
    Chicken(std::string _name, float _weight, std::string _color, int _age) : Pet(_name, _weight, _color, _age)
    {
    }
    void makeSound()
    {
        std::cout << "o o o!\n";
    }

    bool eat(std::string food)
    {
        if (food == ("thoc"))
        {
            this->setWeight(0.8);
            return true;
        }
        return false;
    }
};
#endif // !_PETMANAGE_CHICKEN_H
