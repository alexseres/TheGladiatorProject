#include "BaseGladiator.h"


void BaseGladiator::increaseAbilities() {
    SP = (int)(SP * (sp_multiplier * 0.01) * Level);
    DEX = (int)(DEX * (dex_multiplier * 0.01) * Level);
    ++Level;
}

void BaseGladiator::healUp() {
    HP = StarterHealth;
    HP = (int)(HP * (hp_multiplier * 0.01) * Level);
    StarterHealth = HP;
}

void BaseGladiator::decreaseHpBy(int decreaser){
    HP = HP - decreaser;
    if(HP <= 0){
        isDead = true;
    }
}



