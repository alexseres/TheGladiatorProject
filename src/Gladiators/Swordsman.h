//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_SWORDSMAN_H
#define THEGLADIATORPROJECT_SWORDSMAN_H


#include "BaseGladiator.h"

class Swordsman : public BaseGladiator{
    Swordsman(string name): BaseGladiator(name){
        Type = "Swordsman";
        FullName = Type + " " + Name;
        hp_multiplier = High;
        sp_multiplier = Medium;
        dex_multiplier = Low;
    }
};



#endif //THEGLADIATORPROJECT_SWORDSMAN_H
