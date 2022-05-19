//
// Created by Alex Seres on 04/05/2022.
//

#ifndef THEGLADIATORPROJECT_BLEED_H
#define THEGLADIATORPROJECT_BLEED_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"

class Bleed : public SpecialWeaponEffect{

public:
    Bleed(int turnCounter, bool chanceToUse) : SpecialWeaponEffect(turnCounter, chanceToUse) {
        decreaser = 2;
        chanceToOccur = 5;
    }

    int makeDamage(int hp, bool &isWeaponized) override{

        if(turnCounter > 0){
            --turnCounter;
            return (int)hp * (decreaser * 0.1);
        }
        else{
            turnCounter = turnCounterStarter;
            isWeaponized = false;
            return 0;
        }
    }

    void resetFields() override{
        turnCounter = turnCounterStarter;
    }
};


#endif //THEGLADIATORPROJECT_BLEED_H