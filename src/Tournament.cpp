#include "Tournament.h"


void Tournament::fillGladiatorsVector() {
    // if dereference pointers and assign it to an object, should the object be deleted explicitly?
    gladiatorFactory.generateGladiators();
    for(BaseGladiator *baseGladiator : gladiatorFactory.GladiatorArr){
        BaseGladiator gladiator = *baseGladiator;
        Gladiators.push_back(gladiator);
        delete baseGladiator;
    }
}

void Tournament::simulateTournament() {

    Tree t(Gladiators[0]);
    //Tree* newt = t.constructTree(Gladiators);
    Tree *championTree = t.constructTree(Gladiators);
    cout << "Champion is " + championTree->gladiator->getGladiatorName() + ".";

}


