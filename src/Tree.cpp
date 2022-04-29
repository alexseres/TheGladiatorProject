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

Tree* Tree::newTree(BaseGladiator gla) {
    Tree *tree = new Tree(gla);
//    tree -> gladiator = gla;
    tree -> rightBranch = NULL;
    tree -> leftBranch = NULL;
    return tree;
}

//Tree::Tree(BaseGladiator gl): Gladiator(gl){
//
//    this->leftBranch = NULL;
//    this->rightBranch = NULL;
//}

Tree* Tree::constructTree(vector<BaseGladiator> gladiators) {
    if(gladiators.size() == 2){
        Combat combat;
        BaseGladiator winner = combat.simulateCombat(gladiators[0], gladiators[1]);
        return newTree(winner);
    }
    else{
        vector<BaseGladiator> rightSubVector = slice(gladiators, gladiators.size()/2, gladiators.size());
        vector<BaseGladiator> leftSubVector = slice(gladiators, 0, gladiators.size()/2);
        this -> rightBranch = constructTree(rightSubVector);
        this -> leftBranch = constructTree(leftSubVector);
        Combat combat;
        BaseGladiator winner = combat.simulateCombat(this->rightBranch->Gladiator,
                                                      this->leftBranch->Gladiator);
//        this -> rightBranch = NULL;
//        this -> leftBranch = NULL;
        return newTree(winner);
    }
}

//Tree* Tree::constructTree(vector<BaseGladiator> gladiators) {
//    if(gladiators.size() == 2){
//        Combat combat;
//        BaseGladiator *winner = combat.simulateCombat(&gladiators[0], &gladiators[1]);
//        return newTree(winner);
//    }
//    else{
//        vector<BaseGladiator> rightSubVector = slice(gladiators, gladiators.size()/2, gladiators.size());
//        vector<BaseGladiator> leftSubVector = slice(gladiators, 0, gladiators.size()/2);
//        this -> rightBranch = constructTree(rightSubVector);
//        this -> leftBranch = constructTree(leftSubVector);
//        Combat combat;
//        BaseGladiator *winner = combat.simulateCombat(this->rightBranch->gladiator,
//                                                      this->leftBranch->gladiator);
////        this -> rightBranch = NULL;
////        this -> leftBranch = NULL;
//        return newTree(winner);
//    }
//}



vector<BaseGladiator> Tree::slice(vector<BaseGladiator> const &v, int m, int n)
{
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<BaseGladiator> vec(first, last);
    return vec;
}

