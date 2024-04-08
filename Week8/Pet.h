#ifndef _PETMANAGE_h
#define _PETMANAGE_h
#include <string>
#include <iostream>
class Pet
{
private:
    int id;
    std::string name;
    float weight;
    std::string color;
    int age;

public:
    Pet() {}
    Pet(std::string _name, float _weight, std::string _color, int _age)
    {
        this->name = _name;
        this->weight = _weight;
        this->color = _color;
        this->age = _age;
    }
    virtual void makeSound() = 0;
    virtual bool eat(std::string) = 0;
    void showMe()
    {
        std::cout << "Pet name: " << name
                  << ", weight: " << weight
                  << ", color: " << color
                  << ", age: " << age << std::endl;
    }
    float getWeight()
    {
        return weight;
    }
    void setWeight(float w)
    {
        weight += w;
    }
};

#endif 