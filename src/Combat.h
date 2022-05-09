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
    void announceWinner(BaseGladiator &winner,BaseGladiator &looser, string &message);
    BaseGladiator simulateCombat(BaseGladiator gladiator1, BaseGladiator gladiator2);
    void turn(BaseGladiator &attacker, BaseGladiator &defender);
    void checkIfIsWeaponized(BaseGladiator &gladiator);
    bool checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender);
    vector<string> getCombatLogs(){return CombatLogs;}
};


#endif //THEGLADIATORPROJECT_COMBAT_H
