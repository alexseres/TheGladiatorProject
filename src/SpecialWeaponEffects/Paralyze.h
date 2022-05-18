//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_PARALYZE_H
#define THEGLADIATORPROJECT_PARALYZE_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"

class Paralyze : public SpecialWeaponEffect {
public:
    int makeDamage(int hp, bool &isWeaponized) override {
        if(turnCounter > 0) {
            return (int) hp * util.getRandomDouble();
        }
        else{
            isWeaponized = false;
            return 0;
        }
    }
    Paralyze(int turnCounter, bool chanceToUse) : SpecialWeaponEffect(turnCounter, chanceToUse) {
        chanceToOccur = 10;
    }
};


#endif //THEGLADIATORPROJECT_PARALYZE_H
