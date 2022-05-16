#ifndef THEGLADIATORPROJECT_BRUTAL_H
#define THEGLADIATORPROJECT_BRUTAL_H


#include "BaseGladiator.h"

class Brutal : public BaseGladiator{
public:
    Brutal(GladiatorType type, string name, int hp, int sp, int dex, int level, SpecialWeaponEffect weaponEffect): BaseGladiator(type, name, hp, sp, dex, level, weaponEffect){
        Type = type;
        hp_multiplier = High;
        sp_multiplier = High;
        dex_multiplier = Low;
    }
};


#endif //THEGLADIATORPROJECT_BRUTAL_H
