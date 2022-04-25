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
//    int le = Gladiators.size()/2;
//    int ri = Gladiators.size();


    assigning(Gladiators, 0, Gladiators.size());

}

Tree* Tournament::assigning(vector<BaseGladiator> gladiators, int start, int end) {
    if(start > end) return nullptr;
    int mid = (start + end)/2;
    Combat combat(gladiators[mid], gladiators[end]);
    Tree *root = tree.newTree(combat);
    root->leftBranch = assigning(gladiators, start, mid - 1);
    root->rightBranch = assigning(gladiators, mid + 1, end);
    return root;
}



//Tree* Tournament::assigning(vector<BaseGladiator> gladiators, int start, int end) {
//    if(start > end) return nullptr;
//    int mid = (start + end)/2;
//    Combat combat(gladiators[mid], gladiators[end]);
//    Tree *root = tree.newTree(combat);
//    root->leftBranch = assigning(gladiators, start, mid - 1);
//    root->rightBranch = assigning(gladiators, mid + 1, end);
//    return root;
//}


//void Tournament::assigning(Tree *root, int leftValue, int rightValue, vector<BaseGladiator> gladiators) {
//    //Tree *root = tree.newTree(Combat(Gladiators[le], Gladiators[ri]));
//    leftValue--;
//    rightValue--;
//    if(leftValue < 0){
//
//        return;
//    }
//    Tree *newTree = root->newTree(Combat(gladiators[leftValue], gladiators[rightValue]));
//    root ->root = nullptr;
//    assigning(root->leftBranch = newTree, leftValue, rightValue,  gladiators);
//    //root = tree.newTree(Combat(Gladiators[le], Gladiators[ri]));
//    assigning( root-> rightBranch = root,leftValue, rightValue, gladiators);
////    root->GladiatorCombat.simulateCombat();
////    root -> leftBranch = assigning(root, leftValue, rightValue,  gladiators);
////    root -> rightBranch = assigning(newTree, leftValue, rightValue, gladiators);
//}



