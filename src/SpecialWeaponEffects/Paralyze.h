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

    //if I define this virtual function in cpp I get an error, dont know why
    int makeDamage(int sp, bool &isWeaponized) override{
        if(turnCounter > 0) {
            return (int) sp * util.getRandomDouble();
        }
        else{
            isWeaponized = false;
            turnCounter = turnCounterStarter;
            return 0;
        }
    };
    void resetFields() override{
        turnCounter = turnCounterStarter;
    }
};


#endif //THEGLADIATORPROJECT_PARALYZE_H
