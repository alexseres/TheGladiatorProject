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

}
