#ifndef _PETMANAGE_FARMFUNCTION_H
#define _PETMANAGE_FARMFUNCTION_H
#include "Pet.h"
#include <vector>
class FarmFunctions{
public:
    std::vector<Pet*> createPets();
    void deFoodForPets(std::vector<Pet*>, std::vector<std::string>);
    void makeSoundForPets(std::vector<Pet*>);
};
#endif // !_PETMANAGE_FARMFUNCTION_H
