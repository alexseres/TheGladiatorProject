#ifndef THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
#define THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H

#include <iostream>
#include "../Utils.h"
using namespace std;


class SpecialWeaponEffect {

protected:
    int lifeCounter;
    Utils util;
    int turnCounter;
    int decreaser;
    int chanceToOccur;
public:
    virtual int makeDamage(int hp, bool &isWeaponized);
    int getChanceToOccur(){return chanceToOccur;};

    int getTurnCounter() {return turnCounter;}
    int getLifeCounter(){return lifeCounter;}
    void reduceLifeCounter(){--lifeCounter;}
    void turnCounterReducer(){if(turnCounter > 0)--turnCounter;}
};


#endif //THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H