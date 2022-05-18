#ifndef THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
#define THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H

#include <iostream>
#include "../Utils.h"
using namespace std;


class SpecialWeaponEffect {

protected:
    int lifeCounter = 0;
    Utils util;
    int turnCounter = 0;
    int turnCounterStarter = 0;
    int decreaser = 0;
    int chanceToOccur = 0;

public:
    bool canBeUsed = false;
    SpecialWeaponEffect(int turnCounterIni, int chanceToUse){
        turnCounter = turnCounterIni;
        turnCounterStarter = turnCounterIni;
        canBeUsed = chanceToUse;
    }
    virtual int makeDamage(int hp, bool &isWeaponized) = 0;
    int getChanceToOccur(){return chanceToOccur;};

    int getTurnCounter() {return turnCounter;}
    int getLifeCounter(){return lifeCounter;}
    void reduceLifeCounter(){--lifeCounter;}
    void turnCounterReducer(){if(turnCounter > 0)--turnCounter;}

};


#endif //THEGLADIATORPROJECT_SPECIALWEAPONEFFECT_H
