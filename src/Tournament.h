//
// Created by Alex Seres on 21/04/2022.
//

#ifndef THEGLADIATORPROJECT_TOURNAMENT_H
#define THEGLADIATORPROJECT_TOURNAMENT_H
#include <iostream>
#include <vector>
#include "Utils.h"
#include "GladiatorFactory.h"
#include "Gladiators/BaseGladiator.h"
#include "Gladiators/Archer.h"
#include "Gladiators/Assassin.h"
#include "Gladiators/Swordsman.h"
#include "Gladiators/Brutal.h"

using namespace std;




class Tournament {
private:
    GladiatorFactory gladiatorFactory;
    vector<BaseGladiator> Gladiators;

public:
    void fillGladiatorsVector();
    void simulateTournament();
    vector<BaseGladiator> getGladiators(){return Gladiators;}

};


#endif //THEGLADIATORPROJECT_TOURNAMENT_H
