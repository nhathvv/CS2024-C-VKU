#include <iostream>
#include <string>
#include <vector>
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Chicken.h"
#include "Pig.h"
#include "FarmFunctions.h"
int main(){
    FarmFunctions farm;
    std::vector<Pet*> pets = farm.createPets();
    for(auto var : pets)
    {
        var->showMe();
    }
    std::vector<std::string> foods = {"ca", "xuong", "ca"};
    farm.deFoodForPets(pets, foods);
    std::cout << "After eats" << std::endl;
    for(auto var : pets)
    {
        var->showMe();
    }
    farm.makeSoundForPets(pets);
}