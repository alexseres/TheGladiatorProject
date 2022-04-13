//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_ARCHER_H
#define THEGLADIATORPROJECT_ARCHER_H


#include "BaseGladiator.h"
#include "StatisticMultiplier.cpp"

class Archer : public BaseGladiator{
private:
public:
    Archer(string name): BaseGladiator(name){
        Type = "Archer";
        FullName = Type + " " + Name;
        hp_multiplier = Medium;
        sp_multiplier = Medium;
        dex_multiplier = High;
    }
};


#endif //THEGLADIATORPROJECT_ARCHER_H
