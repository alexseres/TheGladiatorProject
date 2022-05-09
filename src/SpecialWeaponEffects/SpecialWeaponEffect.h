#ifndef THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
#define THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H

#include <iostream>
#include "../Utils.h"
using namespace std;


class SpecialWeaponEffect {

protected:
    Utils util;
    int turnCounter;
    int decreaser;
    int chanceToOccur;
public:
    virtual int makeDamage(int hp, bool &isWeaponized);
    int getChanceToOccur(){return chanceToOccur;};
};


#endif //THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
