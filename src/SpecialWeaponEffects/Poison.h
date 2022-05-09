//
// Created by Alex Seres on 04/05/2022.
//

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
    }
};


#endif //THEGLADIATORPROJECT_POISON_H
