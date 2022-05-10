//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_BLEED_H
#define THEGLADIATORPROJECT_BLEED_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"

class Bleed : public SpecialWeaponEffect{

public:
    Bleed(){
        turnCounter = INTMAX_MAX;
        decreaser = 2;
        chanceToOccur = 5;
    }
};


#endif //THEGLADIATORPROJECT_BLEED_H