#include "BaseGladiator.h"


void BaseGladiator::increaseAbilities() {
    SP = SP * (sp_multiplier * 0.01) * Level;
    HP = HP * (hp_multiplier * 0.01) * Level;
    DEX = DEX * (dex_multiplier * 0.01) * Level;
}

void BaseGladiator::decreaseHpBy(int decreaser) {
    HP = HP - decreaser;
    if(HP >= 0){
        isDead = true;
    }
}

void BaseGladiator::healUp(int increaser) {

}
