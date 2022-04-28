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
#include "Tree.h"
#include "Combat.h"

using namespace std;




class Tournament {
private:
    //Combat combat;
    Tree tree;
    GladiatorFactory gladiatorFactory;
    vector<BaseGladiator> Gladiators;
    int le = Gladiators.size()/2;
    int ri = Gladiators.size();

public:
    void fillGladiatorsVector();
    void simulateTournament();
    vector<BaseGladiator> getGladiators(){return Gladiators;}
    Tree* assigning(Tree* node,int start, int end);
    Tree* buildTree(Tree* root,vector<BaseGladiator> gladiators, int start, int end);
    vector<BaseGladiator> getSubVector(int start, int end);
    explicit Tournament(Tree tree): tree(std::move(tree)){};
};


#endif //THEGLADIATORPROJECT_TOURNAMENT_H
