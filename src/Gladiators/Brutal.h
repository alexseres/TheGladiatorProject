//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_BRUTAL_H
#define THEGLADIATORPROJECT_BRUTAL_H


#include "BaseGladiator.h"

class Brutal : public BaseGladiator{
public:
    Brutal(string name): BaseGladiator(name){
        Type = "Brutal";
        FullName = Type + " " + Name;
        hp_multiplier = High;
        sp_multiplier = High;
        dex_multiplier = Low;
    }
};


#endif //THEGLADIATORPROJECT_BRUTAL_H
