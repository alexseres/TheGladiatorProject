
#include "Combat.h"
BaseGladiator* Combat::simulateCombat(BaseGladiator &gladiator1, BaseGladiator &gladiator2) {
    string introduction ="Duel " +  gladiator1.getGladiatorName() +": (" +"HP: " + to_string(gladiator1.getHP()) + ", SP: " +  to_string(gladiator1.getSP()) + ", DEX: " + to_string(gladiator1.getDEX()) + ", Level: "  + to_string(gladiator1.getGladiatorLevel()) + ") versus " +
    gladiator2.getGladiatorName() +": (" +"HP: " + to_string(gladiator2.getHP()) + ", SP: " +  to_string(gladiator2.getSP()) + ", DEX: " + to_string(gladiator2.getDEX()) + ", Level: "  + to_string(gladiator2.getGladiatorLevel()) + ")";
    cout << introduction << endl;
    CombatLogs.push_back(introduction);

    string message;
    bool firstStarts = true;

    while(gladiator1.getHP() > 0 && gladiator2.getHP() > 0){
        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
        //!firstStarts || (firstStarts = false);  //check if firstStarts was true then it will be false and vice versa
        if(firstStarts) firstStarts = false; else firstStarts = true;

    }

    BaseGladiator *winner;
    BaseGladiator *notWinner;

    if(gladiator2.isDead){
        winner = &gladiator1;
        notWinner = &gladiator2;
    }
    else{
        winner = &gladiator2;
        notWinner = &gladiator1;
    }

    winner->increaseAbilities();
    winner->healUp();
    message = winner->getGladiatorName() + " has won. " + notWinner->getGladiatorName() + " is dead.";
    CombatLogs.push_back(message);
    cout << message << endl;
    return winner;
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    string message;
    message = attacker.getGladiatorName() + " turns.";
    CombatLogs.push_back(message);
    cout << message << endl;

    int difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    if(chance > percentage){
        //hit been successful
        int decreaser = attacker.getSP() * util.getRandomDouble();
        defender.decreaseHpBy(decreaser);
        message =  attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + " with " + to_string(decreaser) + " damage.";

    }
    else{
        //missed
        message = attacker.getGladiatorName() + " Misses.";
    }
    CombatLogs.push_back(message);
    cout << message << endl;
}

BaseGladiator* Combat::draft(BaseGladiator *gl1, BaseGladiator *gl2) {
    return gl2;
}

Combat::Combat() {
//why need this, without this, it throws an error
}
