//
// Created by Alex Seres on 22/04/2022.
//

#ifndef THEGLADIATORPROJECT_TREE_H
#define THEGLADIATORPROJECT_TREE_H
#include "Gladiators/BaseGladiator.h"
#include "Combat.h"


class Tree {
private:
public:
    Combat *GladiatorCombat;
    Tree *root;
    Tree *leftBranch;
    Tree *rightBranch;

    Tree *newTree(Combat combat);
//    Combat process(Tree *root, int val, vector<BaseGladiator> gladiators);
};


#endif //THEGLADIATORPROJECT_TREE_H
