#ifndef THEGLADIATORPROJECT_ARCHER_H
#define THEGLADIATORPROJECT_ARCHER_H


#include "BaseGladiator.h"


class Archer : public BaseGladiator{
private:
public:
    Archer(GladiatorType type, string name, double hp, double sp, double dex, int level):
    BaseGladiator(type, name, hp, sp, dex, level){
        Type = type;
        hp_multiplier = Medium;
        sp_multiplier = Medium;
        dex_multiplier = High;
    }
};


#endif //THEGLADIATORPROJECT_ARCHER_H
