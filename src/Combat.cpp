
#include "Combat.h"

void Combat::simulateCombat() {
    string message;
    bool firstStarts = true;
    while(gladiator1.getHP() > 0 || gladiator2.getHP() > 0){
        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
        !firstStarts || (firstStarts = false);  //check if firstStarts was true then it will be false and vice versa
    }
    if(gladiator2.isDead){
        message = gladiator1.getGladiatorName() + " has won. " + gladiator2.getGladiatorName() + " is dead.";
    }
    else{
        message = gladiator2.getGladiatorName() + " has won. " + gladiator1.getGladiatorName() + " is dead.";
    }
    CombatLogs.push_back(message);
    cout << message << endl;
}

void Combat::turn(BaseGladiator &attacker, BaseGladiator &defender) {
    string message;
    message = attacker.getGladiatorName() + " turns.";
    CombatLogs.push_back(message);

    bool difference = attacker.getDEX() - defender.getDEX();
    int chance = util.getClampValue(difference);
    int percentage = util.getRandomNumber(100);
    if(chance > percentage){
        //hit been successful
        defender.decreaseHpBy(attacker.getSP() * util.getRandomDouble());
        message =  attacker.getGladiatorName() + " Hits " + defender.getGladiatorName() + ".";

    }
    else{
        //missed
        message = attacker.getGladiatorName() + " Misses.";
    }
    CombatLogs.push_back(message);
    cout << message << endl;
}

BaseGladiator Combat::draft(BaseGladiator gl1, BaseGladiator gl2) {
    return gl2;
}