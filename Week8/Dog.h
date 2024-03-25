#ifndef _PETMANAGE_DOG_H
#define _PETMANAGE_DOG_H
#include "Pet.h"

class Dog : public Pet
{
public:
    Dog(std::string _name, float _weight, std::string _color, int _age) : Pet(_name, _weight, _color, _age)
    {
    }
    void makeSound()
    {
        std::cout << "Gau Gau!\n";
    }

    bool eat(std::string food)
    {
        if (food == ("xuong"))
        {
            this->setWeight(0.8);
            return true;
        }
        return false;
    }
};
#endif // !_PETMANAGE_DOG_H
