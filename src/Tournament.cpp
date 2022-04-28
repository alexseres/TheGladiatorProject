#include "Tournament.h"


void Tournament::fillGladiatorsVector() {
    gladiatorFactory.generateGladiators();
    int counter = 1;
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

    Tree *championTree = tree.constructTree(Gladiators);


}


//Tree* Tournament::buildTree(Tree *root,vector<BaseGladiator> gladiators) {
//    if(gladiators.size() == 2){
//
//    }
//    else{
//        vector<BaseGladiator> leftSubVector = {gladiators.begin() +0, gladiators.end() + gladiators.size()/2};
//        root->rightBranch = buildTree(leftSubVector);
//    }
//}

//vector<BaseGladiator> Tournament::getSubVector(int start, int end) {
//    vector<BaseGladiator> subGladiators;
//    for(int i = start;i <= end; i++){
//        subGladiators.push_back(Gladiators[i]);
//    }
//    return subGladiators;
//}


//Tree* Tournament::buildTree(int start, int end) {
//    if(start > end) return nullptr;
//    Combat *combat;
//    Tree *root = tree.newTree(combat);
//
//    //if the only node is left, then return node
//    if(start == end) return root;
//
//    int leftStart = start + 1;
//    int rightStart = leftStart + (end - leftStart + 1) / 2;
//    int leftEnd = rightStart - 1;
//    int rightEnd = end;
//
//    root -> leftBranch = buildTree(leftStart, leftEnd);
//    root -> rightBranch = buildTree(rightStart, rightEnd);
//    return root;
//}

//Tree* Tournament::buildTree(Tree* root, int start, int end) {
//    if(start == end) return nullptr;
//    int mid = (start + end)/2;
////    Combat combat;
//    Tree *node = tree.newTree();
//    root->leftBranch = assigning(node, start, mid - 1);
//    root->rightBranch = assigning(node, mid + 1, end);
//    return node;
//}

//Tree* Tournament::assigning(Tree* root,int start, int end) {
//    if(start >= end) return NULL;
//    //int mid = (start + end)/2;
//    int mid =(end - start)/ 2;
//    root->leftBranch = assigning(root, start, mid - 1);
//    root->rightBranch = assigning(root, mid + 1, end);
//
//    Combat combat(Gladiators[mid], Gladiators[end]);
//    Tree* node = root->newTree(combat);
//    return node;
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



