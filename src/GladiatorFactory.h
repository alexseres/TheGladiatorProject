//
// Created by Alex Seres on 11/04/2022.
//

#ifndef THEGLADIATORPROJECT_GLADIATORFACTORY_H
#define THEGLADIATORPROJECT_GLADIATORFACTORY_H
#include <iostream>
#include "Utils.h"
#include "Gladiators/BaseGladiator.h"
#include "Gladiators/Archer.h"
#include "Gladiators/Assassin.h"
#include "Gladiators/Swordsman.h"
#include "Gladiators/Brutal.h"

using namespace std;


class GladiatorFactory {
private:
    GladiatorType GladiatorPossibilities[5] = {Archer, Assassin, Swordsman, Swordsman, Brutal};

public:
    int GladiatorPossibilitiesSize = 5;
    static const int GladiatorArraySize = 64;
    BaseGladiator *Gladiators[GladiatorArraySize];
    int GladiatorNameListSize = 46;
    string GladiatorFileName = "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/src/GladiatorPossibleNames.txt";
    Utils OwnUtils;
    void generateGladiators();
    BaseGladiator *generateGladiator();
};


#endif //THEGLADIATORPROJECT_GLADIATORFACTORY_H
