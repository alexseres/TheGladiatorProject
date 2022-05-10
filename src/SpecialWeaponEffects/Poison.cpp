#include "Poison.h"

int Poison::makeDamage(int hp, bool &isWeaponized) {
    if(lifeCounter > 0){
        if(turnCounter > 0){
            --turnCounter;
            return (int)hp * (decreaser * 0.01);
        }
        else{
            isWeaponized = false;
            return 0;
        }
    }
    else{
        return -1;
    }
}