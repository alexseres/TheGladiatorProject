#ifndef THEGLADIATORPROJECT_POISON_H
#define THEGLADIATORPROJECT_POISON_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"


class Poison : public SpecialWeaponEffect {

public:
    Poison(){
        turnCounter = 3;
        decreaser = 5;
        chanceToOccur = 20;
        lifeCounter = 2;
    }
    int makeDamage(int hp, bool &isWeaponized) override;
    int getLifeCounter(){return lifeCounter;}
};


#endif //THEGLADIATORPROJECT_POISON_H