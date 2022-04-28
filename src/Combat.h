//
// Created by Alex Seres on 21/04/2022.
//

#ifndef THEGLADIATORPROJECT_COMBAT_H
#define THEGLADIATORPROJECT_COMBAT_H


#include "Gladiators/BaseGladiator.h"
#include "Utils.h"
#include <iostream>
#include <vector>

class Combat {
private:
    vector<string> CombatLogs;
    Utils util;

public:
    Combat();
    BaseGladiator* simulateCombat(BaseGladiator &gladiator1, BaseGladiator &gladiator2);
    void turn(BaseGladiator &attacker, BaseGladiator &defender);
    BaseGladiator* draft(BaseGladiator *gl1, BaseGladiator *gl2);

};


#endif //THEGLADIATORPROJECT_COMBAT_H
