#ifndef THEGLADIATORPROJECT_POISON_H
#define THEGLADIATORPROJECT_POISON_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"


class Poison : public SpecialWeaponEffect {

public:
    Poison(int turnCounter, bool chanceToUse) : SpecialWeaponEffect(turnCounter, chanceToUse) {
        decreaser = 5;
        chanceToOccur = 20;
        lifeCounter = 2;
    }
    int getLifeCounter(){return lifeCounter;}
    int makeDamage(int hp, bool &isWeaponized) override{
        if(lifeCounter > 0){
            if(turnCounter > 0){
                --turnCounter;
                return (int)hp * (decreaser * 0.01);
            }
            else{
                turnCounter = turnCounterStarter;
                isWeaponized = false;
                return 0;
            }
        }
        else{
            turnCounter = turnCounterStarter;
            isWeaponized = false;
            return -1;
        }
    };
};


#endif //THEGLADIATORPROJECT_POISON_H
