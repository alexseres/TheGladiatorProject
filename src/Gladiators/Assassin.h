//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_ASSASSIN_H
#define THEGLADIATORPROJECT_ASSASSIN_H

#include "BaseGladiator.h"

class Assassin : public BaseGladiator {
public:
    Assassin(GladiatorType type, string name, double hp, double sp, double dex, int level): BaseGladiator(type, name, hp, sp, dex, level){
        Type = type;
        hp_multiplier = Low;
        sp_multiplier = High;
        dex_multiplier = High;
    }
};


#endif //THEGLADIATORPROJECT_ASSASSIN_H
