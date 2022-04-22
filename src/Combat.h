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
    BaseGladiator gladiator1;
    BaseGladiator gladiator2;
    Utils util;

public:
    Combat(BaseGladiator g1, BaseGladiator g2): gladiator1(g1), gladiator2(g2){}
    void simulateCombat();
    void turn(BaseGladiator &attacker, BaseGladiator &defender);

};


#endif //THEGLADIATORPROJECT_COMBAT_H
