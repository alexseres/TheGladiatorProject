//
// Created by Alex Seres on 22/04/2022.
//

#include "Tree.h"


//Tree *Tree::newTree(BaseGladiator gla) {
//    Tree *tree = new Tree();
//    gladiator = gla;
//    tree -> rightBranch = NULL;
//    tree -> leftBranch = NULL;
//    return tree;
//}

Tree* Tree::newTree(BaseGladiator *gla) {
    Tree *tree = new Tree();
    tree -> gladiator = gla;
    tree -> rightBranch = NULL;
    tree -> leftBranch = NULL;
    tree -> sign = 6;
    return tree;
}

Tree::Tree() {
    this -> gladiator = NULL;
    this->leftBranch = NULL;
    this->rightBranch = NULL;
}


Tree* Tree::constructTree(vector<BaseGladiator> gladiators) {
    if(gladiators.size() == 2){
//        this->leftBranch = newTree(gladiators[0]);
//        this->rightBranch = newTree(gladiators[1]);
        Combat combat;
        BaseGladiator *winner = combat.draft(&gladiators[0],& gladiators[1]);
        Tree *winnerTree = newTree(winner);
        return winnerTree;
    }
    else{
//        vector<BaseGladiator> rightSubVector = {gladiators.begin() +gladiators.size()/2, gladiators.end() + gladiators.size()};
//        vector<BaseGladiator> leftSubVector = {gladiators.begin() +0, gladiators.end() + gladiators.size()/2};
        vector<BaseGladiator> rightSubVector = slice(gladiators, gladiators.size()/2, gladiators.size());
        vector<BaseGladiator> leftSubVector = slice(gladiators, 0, gladiators.size()/2);
        this -> rightBranch = constructTree(rightSubVector);
        this -> leftBranch = constructTree(leftSubVector);
        BaseGladiator* gladiator1 = this -> rightBranch->gladiator;
        BaseGladiator* gladiator2 = this -> leftBranch->gladiator;
        Combat combat;
        BaseGladiator *winner = combat.draft(gladiator1, gladiator2);
        return newTree(winner);
    }
}

vector<BaseGladiator> Tree::slice(vector<BaseGladiator> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    std::vector<BaseGladiator> vec(first, last);
    return vec;
}

