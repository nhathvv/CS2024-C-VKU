#ifndef _PETMANAGE_CAT_H
#define _PETMANAGE_CAT_H
#include "Pet.h"

class Cat : public Pet
{
public:
    Cat(std::string _name, float _weight, std::string _color, int _age) : Pet(_name, _weight, _color, _age)
    {
    }
    void makeSound()
    {
        std::cout << "Meo meo!\n";
    }

    bool eat(std::string food)
    {
        if (food == ("ca"))
        {
            this->setWeight(0.3);
            return true;
        }
        return false;
    }
};
#endif // !_PETMANAGE_CAT_H
