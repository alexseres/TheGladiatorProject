//
// Created by Alex Seres on 22/04/2022.
//

#include "Tree.h"


Tree *Tree::newTree(Combat combat) {
    Tree *tree = new Tree();
    tree -> GladiatorCombat = &combat;
    tree -> leftBranch = nullptr;
    tree -> rightBranch = nullptr;
    return tree;
}








//void Tree::add() {
//
//}
//
//void Tree::leftBranch() {
//
//}
//
//void Tree::rightBranch() {
//
//}