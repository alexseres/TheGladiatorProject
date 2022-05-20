#ifndef THEGLADIATORPROJECT_COMBAT_H
#define THEGLADIATORPROJECT_COMBAT_H


#include "Gladiators/BaseGladiator.h"
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"
#include "SpecialWeaponEffects/Poison.h"
#include "SpecialWeaponEffects/Paralyze.h"
#include "Utils.h"
#include <iostream>
#include <vector>
using namespace std;


class Combat {
private:
    Utils util;
    //with these we can do runtime type comparison
//    const type_info &typePoison = typeid(Poison);
//    const type_info &typeParalyze = typeid(Paralyze);
    const string typeParalyze = typeid(Paralyze).name();
    const string typePoison = typeid(Poison).name();

public:
    void announceWinner(BaseGladiator &winner,BaseGladiator &looser);
    BaseGladiator simulateCombat(BaseGladiator gladiator1, BaseGladiator gladiator2);
    void turn(BaseGladiator &attacker, BaseGladiator &defender);
    void checkIfIsWeaponized(BaseGladiator &defender, BaseGladiator &attacker);
    bool checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender);
    void isAttacking(BaseGladiator &attacker, BaseGladiator &defender);
    bool isUsingWeapon(BaseGladiator &attacker, BaseGladiator &defender);

};


#endif //THEGLADIATORPROJECT_COMBAT_H
