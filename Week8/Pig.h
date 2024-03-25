#ifndef _PETMANAGE_PIG_H
#define _PETMANAGE_PIG_H
#include "Pet.h"

class Pig : public Pet
{
public:
    Pig(std::string _name, float _weight, std::string _color, int _age) : Pet(_name, _weight, _color, _age)
    {
    }
    void makeSound()
    {
        std::cout << "ec ec ec!\n";
    }

    bool eat(std::string food)
    {
        if (food == ("rau"))
        {
            this->setWeight(1.0);
            return true;
        }
        return false;
    }
};
#endif // !_PETMANAGE_PIG_H
