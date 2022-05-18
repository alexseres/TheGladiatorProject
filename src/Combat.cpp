
#include "Combat.h"

BaseGladiator Combat::simulateCombat(BaseGladiator gladiator1, BaseGladiator gladiator2) {
    string introduction ="Duel " +  gladiator1.getGladiatorName() +": (" +"HP: " + to_string(gladiator1.getHP()) + ", SP: " +  to_string(gladiator1.getSP()) + ", DEX: " + to_string(gladiator1.getDEX()) + ", Level: "  + to_string(gladiator1.getGladiatorLevel()) + ") versus " +
                         gladiator2.getGladiatorName() +": (" +"HP: " + to_string(gladiator2.getHP()) + ", SP: " +  to_string(gladiator2.getSP()) + ", DEX: " + to_string(gladiator2.getDEX()) + ", Level: "  + to_string(gladiator2.getGladiatorLevel()) + ")";
    cout << introduction << endl;
    CombatLogs.push_back(introduction);

    string message;
    bool firstStarts = true;

    //sometimes the duel goes infinity, and we need to make sure it does not cause stack overflow
    //so it is restricted to 100 turn each
    int turnCounter = 0;

    while(gladiator1.getHP() > 0 && gladiator2.getHP() > 0 && turnCounter < 101){
        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
        if(firstStarts) firstStarts = false;
        else firstStarts = true;
        ++turnCounter;
    }

    if(turnCounter > 100){
        int percentage = util.getRandomNumber(100);
        if(percentage > 50){
            gladiator1.isDead = true;
        }
        else{
            gladiator2.isDead = true;
        }
    }

    if(gladiator2.isDead){
        announceWinner(gladiator1, gladiator2, message);
        return gladiator1;
    }
    else{
        announceWinner(gladiator2, gladiator1, message);
        return gladiator2;
    }
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    checkIfIsWeaponized(defender, attacker);
    checkIfIsWeaponized(attacker, defender);
    bool skipRest = checkIfIsParalyzed(attacker, defender);
    if(attacker.isDead || defender.isDead) return;
    if(skipRest) return;

    string message;
    message = attacker.getGladiatorName() + " turns.";
    CombatLogs.push_back(message);
    cout << message << endl;

    isAttacking(attacker, defender, message);

    CombatLogs.push_back(message);
    cout << message << endl;
}

void Combat::checkIfIsWeaponized(BaseGladiator &defender, BaseGladiator &attacker) {
    if(defender.isWeaponized){
        const type_info &typeActualAttackerWeapon = typeid(*attacker.weapon);
        if(typeParalyze == typeActualAttackerWeapon){
            return;
        }
        else{
            string message;
            int damage = 0;
            if(typePoison == typeActualAttackerWeapon){
                damage = attacker.weapon->makeDamage(defender.getHP(), defender.isWeaponized);
                if(damage == -1){
                    //-1 only returns in Poison class and happens when 2 times poisoned
                    message = defender.getGladiatorName() + " is poisoned for the second time, he is gonna die";
                    CombatLogs.push_back(message);
                    cout << message << endl;
                    defender.isDead = true;
                    return;
                }
                else{
                    damage = attacker.weapon->makeDamage(defender.getHP(), defender.isWeaponized);
                    message = defender.getGladiatorName() + " is poisoned for " + to_string(attacker.weapon->getTurnCounter()) + " turn, and he is damaged by " +
                            to_string(damage);
                }
            }
            else{
                damage = attacker.weapon->makeDamage(defender.getHP(), defender.isWeaponized);
                message = defender.getGladiatorName() + " is bleeding for the rest of the combat"  + " turn, and he is damaged by " +
                          to_string(damage);
            }
            defender.decreaseHpBy(damage);
            CombatLogs.push_back(message);
            cout << message << endl;
        }
    }
}

bool Combat::checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender) {
    // cant be 2 gladiator paralyzed at the same time

    string message;

    if(attacker.isWeaponized){
        const type_info &typeActualDefenderWeapon = typeid(*defender.weapon);
        if(typeParalyze == typeActualDefenderWeapon){
            defender.weapon->turnCounterReducer();
            message = attacker.getGladiatorName() + " misses this turn, because he is paralyzed";
            CombatLogs.push_back(message);
            cout << message << endl;
            return true;
        }
    }

    if(defender.isWeaponized){
        const type_info &typeActualAttackerWeapon = typeid(*attacker.weapon);
        if(typeParalyze == typeActualAttackerWeapon){
            int damage = attacker.weapon->makeDamage(attacker.getSP(), defender.isWeaponized);
            if(damage > 0){
                defender.decreaseHpBy(damage);
                message = defender.getGladiatorName() + " is damaged by " + to_string(damage) +  ", because of being pralyzed";
                attacker.weapon->turnCounterReducer();
                CombatLogs.push_back(message);
                cout << message << endl;
            }
            return true;
        }
    }
    return false;
}


void Combat::isUsingWeapon(BaseGladiator &attacker, BaseGladiator &defender) {
    if(attacker.weapon->canBeUsed){
        int chanceToWeaponize = util.getRandomNumber(100);
        if (chanceToWeaponize <= attacker.weapon->getChanceToOccur()) {
            defender.isWeaponized = true;
            const type_info &typeActualAttackerWeapon = typeid(*attacker.weapon);
            if(typePoison == typeActualAttackerWeapon){
                attacker.weapon->reduceLifeCounter();
            }
        }
    }
}

void Combat::isAttacking(BaseGladiator &attacker, BaseGladiator &defender, string &message) {
    int difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    if(chance > percentage){
        //hit been successful
        int decreaser = (int)attacker.getSP() * util.getRandomDouble();
        defender.decreaseHpBy(decreaser);
        message = attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + " with " + to_string(decreaser) + " damage.";
        isUsingWeapon(attacker, defender);
    }
    else{
        //missed
        message = attacker.getGladiatorName() + " Misses.";
    }
}


void Combat::announceWinner(BaseGladiator &winner, BaseGladiator &looser, string &message) {
    winner.increaseAbilities();
    winner.healUp();
    message = winner.getGladiatorName() + " has won. " + looser.getGladiatorName() + " is dead.";
    CombatLogs.push_back(message);
    cout << message << endl;
    message ="Winner " +  winner.getGladiatorName() +" increased to:  (" +"HP: " + to_string(winner.getHP()) + ", SP: " +  to_string(winner.getSP()) + ", DEX: " + to_string(winner.getDEX()) + ", Level: "  + to_string(winner.getGladiatorLevel()) + ")";
    CombatLogs.push_back(message);
    cout << message << endl;
}
