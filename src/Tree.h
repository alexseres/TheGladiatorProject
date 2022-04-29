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
    BaseGladiator *gladiator;
    BaseGladiator Gladiator;
    Tree *rightBranch;
    Tree *leftBranch;

    Tree* newTree(BaseGladiator gla);
    Tree(BaseGladiator gladiator): Gladiator(gladiator){};

//    Tree* constructTree(vector<BaseGladiator> gladiators);
    Tree* constructTree(vector<BaseGladiator> gladiators);
    vector<BaseGladiator> slice(vector<BaseGladiator> const &v, int m, int n);
    //Tree(BaseGladiator gla): gladiator(std::move(gla)){}

};


#endif //THEGLADIATORPROJECT_TREE_H
