//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_PARALYZE_H
#define THEGLADIATORPROJECT_PARALYZE_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"

class Paralyze : public SpecialWeaponEffect {
public:
    Paralyze(int turnCounter, bool chanceToUse) : SpecialWeaponEffect(turnCounter, chanceToUse) {
        chanceToOccur = 10;
    }

    int makeDamage(int hp, bool &isWeaponized);
};


#endif //THEGLADIATORPROJECT_PARALYZE_H
