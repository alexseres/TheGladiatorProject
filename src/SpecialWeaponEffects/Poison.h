#ifndef THEGLADIATORPROJECT_POISON_H
#define THEGLADIATORPROJECT_POISON_H

#include <iostream>
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"


class Poison : public SpecialWeaponEffect {

public:
    int lifeCounterStarter = 0;
    int getLifeCounter(){return lifeCounter;}
    Poison(int turnCounter, bool chanceToUse) : SpecialWeaponEffect(turnCounter, chanceToUse) {
        decreaser = 5;
        chanceToOccur = 20;
        lifeCounter = 2;
        lifeCounterStarter = lifeCounter;
    }
    int makeDamage(int hp, bool &isWeaponized) override{
        if(lifeCounter > 0){
            --turnCounter;
            if(turnCounter > 0){
                int damage = (int)hp * (decreaser * 0.1);
                if(damage != 0){
                    return damage;
                }
                else{
                    return 1;
                }
            }
            else{
                turnCounter = turnCounterStarter;
                isWeaponized = false;
                return 0;
            }
        }
    }

    void resetFields() override {
        turnCounter = turnCounterStarter;
        lifeCounter = lifeCounterStarter;
    }
};


#endif //THEGLADIATORPROJECT_POISON_H
