//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_BURN_H
#define THEGLADIATORPROJECT_BURN_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"
#include "../Utils.h"

class Burn : public SpecialWeaponEffect{
private:
    Utils util;
public:
    Burn(){
        turnCounter = util.getRandomNumber(1,5);
        decreaser = 5;
        chanceToOccur = 15;
    }
};


#endif //THEGLADIATORPROJECT_BURN_H
