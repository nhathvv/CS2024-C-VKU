
#include "FarmFunctions.h"
#include "Cat.h"
#include "Dog.h"
#include "Chicken.h"
// #include <vector>
#include <iostream>

std::vector<Pet *> FarmFunctions::createPets()
{
    Cat *cat1 = new Cat("Tom", 6.3, "black", 5);
    Dog *dog = new Dog("Bull", 10.3, "black", 2);
    Cat *cat2 = new Cat("Toc", 2.3, "gray", 5);
    std::vector<Pet *> pets;
    pets.push_back(cat1);
    pets.push_back(dog);
    pets.push_back(cat2);
    return pets;
}

void FarmFunctions::deFoodForPets(std::vector<Pet *> pets, std::vector<std::string> foods)
{
    for (auto var : pets)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            var->eat(foods[i]);
            foods[i] = "";
        }
    }
}

void FarmFunctions::makeSoundForPets(std::vector<Pet*> pets){
    for(auto var : pets)
    {
        var->makeSound();
    }
}
