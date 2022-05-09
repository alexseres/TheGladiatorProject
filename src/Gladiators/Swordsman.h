//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_SWORDSMAN_H
#define THEGLADIATORPROJECT_SWORDSMAN_H


#include "BaseGladiator.h"

class Swordsman : public BaseGladiator{
public:
    Swordsman(GladiatorType type, string name, double hp, double sp, double dex, int level, bool weaponEffect): BaseGladiator(type, name, hp, sp, dex, level, weaponEffect){
        Type = type;
        hp_multiplier = High;
        sp_multiplier = Medium;
        dex_multiplier = Low;
    }
};



#endif //THEGLADIATORPROJECT_SWORDSMAN_H
