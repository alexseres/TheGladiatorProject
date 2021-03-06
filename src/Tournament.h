//
// Created by Alex Seres on 21/04/2022.
//

#ifndef THEGLADIATORPROJECT_TOURNAMENT_H
#define THEGLADIATORPROJECT_TOURNAMENT_H
#include <iostream>
#include <utility>
#include <vector>
#include "Utils.h"
#include "GladiatorFactory.h"
#include "Gladiators/BaseGladiator.h"
#include "Gladiators/Archer.h"
#include "Gladiators/Assassin.h"
#include "Gladiators/Swordsman.h"
#include "Gladiators/Brutal.h"
#include "Combat.h"

using namespace std;

class Tournament {
private:
    GladiatorFactory gladiatorFactory;
    vector<BaseGladiator> Gladiators;
    BaseGladiator *Champion;
    int fightCounter = 0;


public:
    void fillGladiatorsVectorAndAddWeapon();
    void simulateTournament();
    BaseGladiator knockOut(vector<BaseGladiator> gladiators, Combat combat);
    vector<BaseGladiator> sliceVector(vector<BaseGladiator> const &v, int m, int n);
    vector<BaseGladiator> getGladiators(){return Gladiators;}
    int getFightCounter(){return fightCounter;}


};


#endif //THEGLADIATORPROJECT_TOURNAMENT_H
