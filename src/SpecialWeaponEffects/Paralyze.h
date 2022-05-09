//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_PARALYZE_H
#define THEGLADIATORPROJECT_PARALYZE_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"

class Paralyze : public SpecialWeaponEffect {
public:
    Paralyze(){
        turnCounter = 3;
        chanceToOccur = 10;
    }
    int makeDamage(int sp, bool &isWeaponized) override;
};


#endif //THEGLADIATORPROJECT_PARALYZE_H
