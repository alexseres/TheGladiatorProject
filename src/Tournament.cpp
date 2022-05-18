#include "Tournament.h"


void Tournament::fillGladiatorsVectorAndAddWeapon() {
    gladiatorFactory.generateGladiators();
    for(BaseGladiator *baseGladiator : gladiatorFactory.GladiatorArr){
        BaseGladiator gladiator = *baseGladiator;
        Gladiators.push_back(gladiator);
        delete baseGladiator;
    }
}

BaseGladiator Tournament::knockOut(vector<BaseGladiator> gladiators, Combat combat){
    if(gladiators.size() == 2){
        BaseGladiator winner = combat.simulateCombat(gladiators[0], gladiators[1]); ++fightCounter;
        return winner;
    }
    else{
        vector<BaseGladiator> rightSubVector = sliceVector(gladiators, gladiators.size()/2, gladiators.size());
        vector<BaseGladiator> leftSubVector = sliceVector(gladiators, 0, gladiators.size()/2);
        BaseGladiator rightChampion = knockOut(rightSubVector, combat);
        BaseGladiator leftChampion = knockOut(leftSubVector, combat);
        BaseGladiator winner = combat.simulateCombat(rightChampion,leftChampion); ++fightCounter;
        return winner;
    }
}

vector<BaseGladiator> Tournament::sliceVector(vector<BaseGladiator> const &v, int m, int n){
    auto first = v.cbegin() + m;
    auto last = v.cbegin() + n;

    vector<BaseGladiator> vec(first, last);
    return vec;
}

void Tournament::simulateTournament() {
    Combat combat;
    BaseGladiator champion = knockOut(Gladiators, combat);
    Champion = &champion;

    cout << "Champion is " + Champion->getGladiatorName() + ".";
}


