//
// Created by Alex Seres on 21/04/2022.
//

#include "Tournament.h"


void Tournament::fillGladiatorsVector() {
    gladiatorFactory.generateGladiators();
    for(BaseGladiator *baseGladiator : gladiatorFactory.GladiatorArr){
        BaseGladiator gladiator = *baseGladiator;
        Gladiators.push_back(gladiator);
        delete baseGladiator;
    }
}

void Tournament::simulateTournament() {

//    BaseGladiator gladiator1 = Gladiators[0];
//    BaseGladiator gladiator2 = Gladiators[1];
    int le = Gladiators.size()/2;
    int ri = Gladiators.size();

    Tree *root = tree.newTree(Combat(Gladiators[le], Gladiators[ri]));
    assigning(root, le, ri, Gladiators);
}

Tree *Tournament::assigning(Tree *root, int leftValue, int rightValue, vector<BaseGladiator> gladiators) {
    //Tree *root = tree.newTree(Combat(Gladiators[le], Gladiators[ri]));

    leftValue--;
    rightValue--;
    Tree *newTree = root->newTree(Combat(gladiators[leftValue], gladiators[rightValue ]));
    //root = tree.newTree(Combat(Gladiators[le], Gladiators[ri]));
    root ->root = nullptr;
    root -> leftBranch = assigning(root, leftValue, rightValue,  gladiators);
    root -> rightBranch = assigning(newTree, leftValue, rightValue, gladiators)



}