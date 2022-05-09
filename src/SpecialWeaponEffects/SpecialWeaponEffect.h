#ifndef THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
#define THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H

#include <iostream>
using namespace std;


class SpecialWeaponEffect {

protected:
    int turnCounter;
    int decreaser;
    int chanceToOccur;
public:
    int makeDamage(int hp, bool &isWeaponized);
    int getChanceToOccur(){return chanceToOccur;};
};


#endif //THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
