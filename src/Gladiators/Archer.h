#ifndef THEGLADIATORPROJECT_ARCHER_H
#define THEGLADIATORPROJECT_ARCHER_H


#include "BaseGladiator.h"


class Archer : public BaseGladiator{
private:
public:
    Archer(GladiatorType type, string name, int hp, int sp, int dex, int level, SpecialWeaponEffect weaponEffect):
    BaseGladiator(type, name, hp, sp, dex, level, weaponEffect){
        hp_multiplier = Medium;
        sp_multiplier = Medium;
        dex_multiplier = High;
    }
};


#endif //THEGLADIATORPROJECT_ARCHER_H
