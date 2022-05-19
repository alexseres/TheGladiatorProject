
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

//    while(gladiator1.getHP() > 0 && gladiator2.getHP() > 0 && turnCounter < 101){
//        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
//        if(firstStarts) firstStarts = false;
//        else firstStarts = true;
//        ++turnCounter;
//    }

    while(!(gladiator1.isDead) &&!(gladiator2.isDead) && turnCounter < 101){
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
        if(gladiator1.weapon->canBeUsed)gladiator1.weapon->resetFields();
        return gladiator1;
    }
    else{
        announceWinner(gladiator2, gladiator1, message);
        if(gladiator2.weapon->canBeUsed)gladiator2.weapon->resetFields();
        return gladiator2;
    }
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    string message;
    message = attacker.getGladiatorName() + " turns.";
    CombatLogs.push_back(message);
    cout << message << endl;

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
//        const type_info &typeActualAttackerWeapon = typeid(*attacker.weapon);
        string typeActualAttackerWeapon = typeid(*attacker.weapon).name();
        if(typeParalyze == typeActualAttackerWeapon){
            return;
        }
        else{
            string message;
            int damage = 0;
            damage = attacker.weapon->makeDamage(defender.getHP(), defender.isWeaponized);
            if(typePoison == typeActualAttackerWeapon){
                message = defender.getGladiatorName() + " is poisoned for " + to_string(attacker.weapon->getTurnCounter()) + " turn, and he is damaged by " +
                            to_string(damage);
            }
            else{
                message = defender.getGladiatorName() + " is bleeding for the rest of the combat"  + " turn, and he is damaged by " +
                          to_string(damage);
            }

            if(damage <= 0) return;

            defender.decreaseHpBy(damage);
            CombatLogs.push_back(message);
            cout << message << endl;

            message = "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, "
                      + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP.";
            cout << message << endl;
            CombatLogs.push_back(message);
        }
    }
}

bool Combat::checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender) {
    // cant be 2 gladiator paralyzed at the same time
    string message;
    if(attacker.isWeaponized){
        string typeActualDefenderWeapon = typeid(*defender.weapon).name();
        if(typeParalyze == typeActualDefenderWeapon){
            defender.weapon->turnCounterReducer();
            message = attacker.getGladiatorName() + " misses this turn, because he is paralyzed";
            CombatLogs.push_back(message);
            cout << message << endl;
            return true;
        }
    }

    if(defender.isWeaponized){
        string typeActualAttackerWeapon = typeid(*attacker.weapon).name();
        if(typeParalyze == typeActualAttackerWeapon){
            int damage = attacker.weapon->makeDamage(attacker.getSP(), defender.isWeaponized);
            if(damage > 0){
                defender.decreaseHpBy(damage);
                message = defender.getGladiatorName() + " is damaged by " + to_string(damage) +  ", because of being pralyzed";
                attacker.weapon->turnCounterReducer();
                CombatLogs.push_back(message);
                cout << message << endl;
                message = "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, "
                          + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP.";
                cout << message << endl;
                CombatLogs.push_back(message);
            }
            return true;
        }
    }
    return false;
}

void Combat::isUsingWeapon(BaseGladiator &attacker, BaseGladiator &defender) {
    //check if the gladiator can use its weapon
    if(attacker.weapon->canBeUsed){
        int chanceToWeaponize = util.getRandomNumber(100);
        // check if he got luck to use weapon
        if(chanceToWeaponize <= attacker.weapon->getChanceToOccur()) {
            defender.isWeaponized = true;
            string message = defender.getGladiatorName() + " has been effected ";
            cout << message << endl;
            CombatLogs.push_back(message);

            string typeActualAttackerWeapon = typeid(*attacker.weapon).name();

            //basically checks if the defender poisoned for the second time, it is, he is gonna die
            if(typePoison == typeActualAttackerWeapon){
                attacker.weapon->reduceLifeCounter();
                if(attacker.weapon->getLifeCounter() == 0){
                    message = defender.getGladiatorName() + " is poisoned for the second time, he is gonna die";
                    CombatLogs.push_back(message);
                    cout << message << endl;
                    defender.isDead = true;
                    return;
                }
            }
        }
    }
}

void Combat::isAttacking(BaseGladiator &attacker, BaseGladiator &defender) {
    int difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    string message= "";
    if(chance > percentage){
        //hit been successful
        int decreaser = (int)attacker.getSP() * util.getRandomDouble();
        defender.decreaseHpBy(decreaser);
        message = attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + " with " + to_string(decreaser) + " damage.";
        cout << message << endl;
        CombatLogs.push_back(message);

        message = "Actual HP statistics: " + attacker.getGladiatorName() + " =" + to_string(attacker.getHP()) + " HP, "
                + defender.getGladiatorName() + " =" + to_string(defender.getHP()) + " HP.";
        cout << message << endl;
        CombatLogs.push_back(message);

        if(defender.isDead) return;
        if(!(defender.isWeaponized))isUsingWeapon(attacker, defender);
    }
    else{
        //missed
        message = attacker.getGladiatorName() + " Misses.";
        cout << message << endl;
        CombatLogs.push_back(message);
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
