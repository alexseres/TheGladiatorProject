//
// Created by Alex Seres on 05/05/2022.
//

#include "SpecialWeaponEffect.h"

int SpecialWeaponEffect::makeDamage(int hp, bool &isWeaponized) {
    if(turnCounter > 0){
        --turnCounter;
        return (int)hp * (decreaser * 0.01);
    }
    else{
        isWeaponized = false;
        return 0;
    }
}

