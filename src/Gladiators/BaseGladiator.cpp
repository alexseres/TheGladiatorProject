#include "BaseGladiator.h"


void BaseGladiator::increaseAbilities() {
    SP = SP * (sp_multiplier * 0.01) * Level;
    HP = HP * (hp_multiplier * 0.01) * Level;
    DEX = DEX * (dex_multiplier * 0.01) * Level;
}