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
    Tree *championTree = tree.constructTree(Gladiators);


}


