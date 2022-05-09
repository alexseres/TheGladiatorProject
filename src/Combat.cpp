
#include "Combat.h"

BaseGladiator Combat::simulateCombat(BaseGladiator gladiator1, BaseGladiator gladiator2) {
    string introduction ="Duel " +  gladiator1.getGladiatorName() +": (" +"HP: " + to_string(gladiator1.getHP()) + ", SP: " +  to_string(gladiator1.getSP()) + ", DEX: " + to_string(gladiator1.getDEX()) + ", Level: "  + to_string(gladiator1.getGladiatorLevel()) + ") versus " +
                         gladiator2.getGladiatorName() +": (" +"HP: " + to_string(gladiator2.getHP()) + ", SP: " +  to_string(gladiator2.getSP()) + ", DEX: " + to_string(gladiator2.getDEX()) + ", Level: "  + to_string(gladiator2.getGladiatorLevel()) + ")";
    cout << introduction << endl;
    CombatLogs.push_back(introduction);

    string message;
    bool firstStarts = true;

    //sometimes the duel goes infinity, and we need to make sure it does not cause stack overflow
    //so it is rescrited to 100 turn each
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

void Combat::checkIfIsWeaponized(BaseGladiator &gladiator) {
    string message;
    if(gladiator.isWeaponized){
        if(!(typeid(gladiator.weapon).name() == "Paralyze")){
            int damage = gladiator.weapon.makeDamage(gladiator.getHP(), gladiator.isWeaponized);
            gladiator.decreaseHpBy(damage);
            message = gladiator.getGladiatorName() + " is damaged by " + to_string(damage) +  ", because of effect";
            CombatLogs.push_back(message);
            cout << message << endl;
        }
    }
}

bool Combat::checkIfIsParalyzed(BaseGladiator &attacker, BaseGladiator &defender) {
    string message;
    if(attacker.isWeaponized){
        if(typeid(attacker.weapon).name() == "Paralyze"){
            message = attacker.getGladiatorName() + " misses this turn, because he is paralyzed";
            CombatLogs.push_back(message);
            cout << message << endl;
            return true;
        }
    }
    if(defender.isWeaponized){
        if(typeid(defender.weapon).name() == "Paralyze"){
            int damage = attacker.weapon.makeDamage(attacker.getSP(), defender.isWeaponized);
            defender.decreaseHpBy(damage);
            message = defender.getGladiatorName() + " is damaged by " + to_string(damage) +  ", because of effect";
            CombatLogs.push_back(message);
            cout << message << endl;
            return true;
        }
    }
    return false;
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    checkIfIsWeaponized(attacker);
    checkIfIsWeaponized(defender);
    bool skipRest = checkIfIsParalyzed(attacker, defender);
    if(attacker.isDead || defender.isDead) return;
    if(skipRest) return;

    string message;
    message = attacker.getGladiatorName() + " turns.";
    CombatLogs.push_back(message);
    cout << message << endl;

    int difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    if(chance > percentage){
        //hit been successful
        int decreaser = (int)attacker.getSP() * util.getRandomDouble();
        defender.decreaseHpBy(decreaser);
        message =  attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + " with " + to_string(decreaser) + " damage.";

        //if(attacker.hasWeaponEffect) attacker.weapon.weaponize(defender);
        if(attacker.hasWeaponEffect) {
            int chanceToWeaponize = util.getRandomNumber(100);
            if (chanceToWeaponize <= attacker.weapon.getChanceToOccur()) {
                defender.isWeaponized = true;
            }
        }
    }
    else{
        //missed
        message = attacker.getGladiatorName() + " Misses.";
    }
    CombatLogs.push_back(message);
    cout << message << endl;
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
