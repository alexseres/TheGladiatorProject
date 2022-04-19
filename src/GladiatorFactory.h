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
    int GladiatorsSize = 64;
    string GladiatorFileName = "/GladiatorPossibleNames";
    Utils OwnUtils;
    void generateGladiators();
    BaseGladiator generateGladiator();

};


#endif //THEGLADIATORPROJECT_GLADIATORFACTORY_H
