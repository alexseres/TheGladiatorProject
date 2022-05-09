//
// Created by Alex Seres on 04/05/2022.
//

#include "Paralyze.h"

int Paralyze::makeDamage(int sp, bool &isWeaponized) {
    if(turnCounter > 0) {
        return (int) sp * util.getRandomDouble();
    }
    else{
        isWeaponized = false;
        return 0;
    }
}