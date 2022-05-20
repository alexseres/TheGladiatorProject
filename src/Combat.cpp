
#include "Combat.h"

BaseGladiator Combat::simulateCombat(BaseGladiator gladiator1, BaseGladiator gladiator2) {
    cout << "Duel " +  gladiator1.getGladiatorName() +": (" +"HP: " + to_string(gladiator1.getHP()) + ", SP: " +  to_string(gladiator1.getSP()) + ", DEX: " + to_string(gladiator1.getDEX()) + ", Level: "  + to_string(gladiator1.getGladiatorLevel()) + ") versus " +
                         gladiator2.getGladiatorName() +": (" +"HP: " + to_string(gladiator2.getHP()) + ", SP: " +  to_string(gladiator2.getSP()) + ", DEX: " + to_string(gladiator2.getDEX()) + ", Level: "  + to_string(gladiator2.getGladiatorLevel()) + ")" << endl;

    bool firstStarts = true;

    // sometimes the duel goes infinity, and we need to make sure it does not cause stack overflow
    // so it is restricted to 100 turn each
    int turnCounter = 0;
    while(!(gladiator1.isDead) &&!(gladiator2.isDead) && turnCounter < 101){
        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
        if(firstStarts) firstStarts = false;
        else firstStarts = true;
        ++turnCounter;
    }

    if(turnCounter > 100){
        cout << "No decision could be made, because it passed more than 100 round, so we throw a dime to decide who wins" << endl;
        int percentage = util.getRandomNumber(100);
        percentage > 50 ? gladiator1.isDead = true : gladiator2.isDead = true;
    }

    if(gladiator2.isDead){
        announceWinner(gladiator1, gladiator2);
        gladiator1.setMatchWon();
        if(gladiator1.weapon->canBeUsed)gladiator1.weapon->resetFields();
        return gladiator1;
    }
    else{
        announceWinner(gladiator2, gladiator1);
        gladiator2.setMatchWon();
        if(gladiator2.weapon->canBeUsed)gladiator2.weapon->resetFields();
        return gladiator2;
    }
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    cout << attacker.getGladiatorName() + " turns." << endl;
    checkIfIsWeaponized(defender, attacker);
    if(defender.isDead) return;

    checkIfIsWeaponized(attacker, defender);
    if(attacker.isDead) return;

    bool skipRest = checkIfIsParalyzed(attacker, defender);
    if(attacker.isDead || defender.isDead) return;
    if(skipRest) return;

    isAttacking(attacker, defender);
}

void Combat::checkIfIsWeaponized(BaseGladiator &defender, BaseGladiator &attacker) {
    if(defender.isWeaponized){
        string typeActualAttackerWeapon = typeid(*attacker.weapon).name();
        if(typeParalyze == typeActualAttackerWeapon){
            return;
        }
        else{
            int damage = 0;
            damage = attacker.weapon->makeDamage(defender.getHP(), defender.isWeaponized);
            if(typePoison == typeActualAttackerWeapon){
                cout << defender.getGladiatorName() + " is poisoned for " + to_string(attacker.weapon->getTurnCounter()) + " turn, and he is damaged by " + to_string(damage) << endl;
            }
            else{
                cout << defender.getGladiatorName() + " is bleeding for the rest of the combat"  + " turn, and he is damaged by " +to_string(damage) << endl;
            }

            defender.decreaseHpBy(damage);
            cout << "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, " + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP." << endl;
        }
    }
}

bool Combat::checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender) {
    // cant be 2 gladiator paralyzed at the same time
    if(attacker.isWeaponized){
        string typeActualDefenderWeapon = typeid(*defender.weapon).name();
        if(typeParalyze == typeActualDefenderWeapon){
            defender.weapon->turnCounterReducer();
            cout << attacker.getGladiatorName() + " misses this turn, because he is paralyzed" << endl;
            return true;
        }
    }

    if(defender.isWeaponized){
        string typeActualAttackerWeapon = typeid(*attacker.weapon).name();
        if(typeParalyze == typeActualAttackerWeapon){
            int damage = attacker.weapon->makeDamage(attacker.getSP(), defender.isWeaponized);
            if(damage > 0){
                defender.decreaseHpBy(damage);
                cout << defender.getGladiatorName() + " is damaged by " + to_string(damage) +  ", because of being paralyzed" << endl;
                attacker.weapon->turnCounterReducer();
                cout <<  "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, " + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP." << endl;
            }
            return true;
        }
    }
    return false;
}

bool Combat::isUsingWeapon(BaseGladiator &attacker, BaseGladiator &defender) {
    //check if the gladiator can use its weapon
    if(attacker.weapon->canBeUsed){
        int chanceToWeaponize = util.getRandomNumber(100);
        // check if he got luck to use weapon
        if(chanceToWeaponize <= attacker.weapon->getChanceToOccur()) {
            defender.isWeaponized = true;
            cout << defender.getGladiatorName() + " has been effected " << endl;
            string typeActualAttackerWeapon = typeid(*attacker.weapon).name();

            //basically checks if the defender poisoned for the second time, if he is, he is gonna die
            if (typePoison == typeActualAttackerWeapon) {
                attacker.weapon->reduceLifeCounter();
                if (attacker.weapon->getLifeCounter() == 0) {
                    cout << defender.getGladiatorName() + " is poisoned for the second time, he is gonna die" << endl;
                    defender.isDead = true;
                }
            }
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

void Combat::isAttacking(BaseGladiator &attacker, BaseGladiator &defender) {
    int difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    if(chance > percentage){
        //hit been successful
        int decreaser = (int)attacker.getSP() * util.getRandomDouble();
        defender.decreaseHpBy(decreaser);
        cout << attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + " with " + to_string(decreaser) + " damage." << endl;
        cout << "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, " + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP." << endl;
        if(defender.isDead) return;
        if(!(defender.isWeaponized))isUsingWeapon(attacker, defender);
    }
    else{
        //missed
        cout << attacker.getGladiatorName() + " Misses." << endl;
    }
}

void Combat::announceWinner(BaseGladiator &winner, BaseGladiator &looser) {
    winner.increaseAbilities();
    winner.healUp();
    cout << winner.getGladiatorName() + " has won. " + looser.getGladiatorName() + " is dead." << endl;
    cout << "Winner " +  winner.getGladiatorName() +" increased to:  (" +"HP: " + to_string(winner.getHP()) + ", SP: " +  to_string(winner.getSP()) + ", DEX: " + to_string(winner.getDEX()) + ", Level: "  + to_string(winner.getGladiatorLevel()) + ")" << endl;
}
