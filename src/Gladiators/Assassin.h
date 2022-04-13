//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_ASSASSIN_H
#define THEGLADIATORPROJECT_ASSASSIN_H


#include "BaseGladiator.h"

class Assassin : public BaseGladiator {
public:
    Assassin(string name): BaseGladiator(name){
        Type = "Assassin";
        FullName = Type + " " + Name;
        hp_multiplier = Low;
        sp_multiplier = High;
        dex_multiplier = High;
    }
};


#endif //THEGLADIATORPROJECT_ASSASSIN_H
