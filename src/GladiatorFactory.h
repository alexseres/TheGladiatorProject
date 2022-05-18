#ifndef THEGLADIATORPROJECT_GLADIATORFACTORY_H
#define THEGLADIATORPROJECT_GLADIATORFACTORY_H
#include <iostream>
#include <vector>
#include "Utils.h"
#include "Gladiators/BaseGladiator.h"
#include "Gladiators/Archer.h"
#include "Gladiators/Assassin.h"
#include "Gladiators/Swordsman.h"
#include "Gladiators/Brutal.h"
#include "SpecialWeaponEffects/SpecialWeaponEffect.h"
#include "SpecialWeaponEffects/Poison.h"
#include "SpecialWeaponEffects/Paralyze.h"
#include "SpecialWeaponEffects/Bleed.h"



using namespace std;

class GladiatorFactory {
private:
    GladiatorType GladiatorPossibilities[5] = {Archer, Assassin, Swordsman, Swordsman, Brutal};

public:
    static const int GladiatorVectorSize = 64;
    BaseGladiator *GladiatorArr[GladiatorVectorSize];
    int GladiatorPossibilitiesSize = 5;
    int GladiatorNameListSize = 45;
    string GladiatorFileName = "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/src/GladiatorPossibleNames.txt";
    Utils OwnUtils;
    void generateGladiators();
    BaseGladiator *generateGladiator();
    void generateWeaponEffect(BaseGladiator &gladiator);
};


#endif //THEGLADIATORPROJECT_GLADIATORFACTORY_H
