
#include "Combat.h"


//BaseGladiator* Combat::simulateCombat(BaseGladiator *gladiator1, BaseGladiator *gladiator2) {
//    return gladiator2;
//        string introduction ="Duel " +  gladiator1->getGladiatorName() +": (" +"HP: " + to_string(gladiator1->getHP()) + ", SP: " +  to_string(gladiator1->getSP()) + ", DEX: " + to_string(gladiator1->getDEX()) + ", Level: "  + to_string(gladiator1->getGladiatorLevel()) + ") versus " +
//    gladiator2->getGladiatorName() +": (" +"HP: " + to_string(gladiator2->getHP()) + ", SP: " +  to_string(gladiator2->getSP()) + ", DEX: " + to_string(gladiator2->getDEX()) + ", Level: "  + to_string(gladiator2->getGladiatorLevel()) + ")";
//    cout << introduction << endl;
//    CombatLogs.push_back(introduction);
//
//    string message;
//    bool firstStarts = true;
//
//    //sometimes the duel goes infinity, and we need to make sure it does not cause stack overflow
//    //so it is rescrited to 100 turn each
//    int turnCounter = 0;
//
//    while(gladiator1->getHP() > 0 && gladiator2->getHP() > 0 && turnCounter < 101){
//        firstStarts ? turn(gladiator1, gladiator2) : turn(gladiator2, gladiator1);
//        //!firstStarts || (firstStarts = false);  //check if firstStarts was true then it will be false and vice versa
//        if(firstStarts) firstStarts = false; else firstStarts = true;
//        ++turnCounter;
//    }
//    return gladiator1;
//    BaseGladiator *winner;
//    BaseGladiator *notWinner;
//
//    if(turnCounter > 100){
//        int percentage = util.getRandomNumber(100);
//        if(percentage > 50){
//            winner = gladiator1;
//            notWinner = gladiator2;
//        }
//        else{
//            winner = gladiator2;
//            notWinner = gladiator1;
//        }
//    }
//    else if(gladiator2->isDead){
//        winner = gladiator1;
//        notWinner = gladiator2;
//    }
//    else{
//        winner = gladiator2;
//        notWinner = gladiator1;
//    }
//
//    winner->increaseAbilities();
//    winner->healUp();
//    message = winner->getGladiatorName() + " has won. " + notWinner->getGladiatorName() + " is dead.";
//
//    CombatLogs.push_back(message);
//    cout << message << endl;
////    notWinner == gladiator1 ? delete gladiator1 : delete gladiator2;
//    return winner;
//}

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
        //!firstStarts || (firstStarts = false);  //check if firstStarts was true then it will be false and vice versa
        if(firstStarts) firstStarts = false; else firstStarts = true;
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

void Combat::announceWinner(BaseGladiator &winner, BaseGladiator &looser, string &message) {
    winner.increaseAbilities();
    winner.healUp();
    message = winner.getGladiatorName() + " has won. " + looser.getGladiatorName() + " is dead.";
    CombatLogs.push_back(message);
    cout << message << endl;
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

//
//void Combat::turn(BaseGladiator *attacker, BaseGladiator *defender) {
//    string message;
//    message = attacker->getGladiatorName() + " turns.";
//    CombatLogs.push_back(message);
//    cout << message << endl;
//
//    int difference = attacker->getDEX() - defender->getDEX();
//    int chance = util.getClampValue(difference);
//    int percentage = util.getRandomNumber(100);
//    if(chance > percentage){
//        //hit been successful
//        int decreaser = attacker->getSP() * util.getRandomDouble();
//        defender->decreaseHpBy(decreaser);
//        message =  attacker->getGladiatorName() + " Hits " + defender->getGladiatorName() + " with " + to_string(decreaser) + " damage.";
//
//    }
//    else{
//        //missed
//        message = attacker->getGladiatorName() + " Misses.";
//    }
//    CombatLogs.push_back(message);
//    cout << message << endl;
//}

BaseGladiator* Combat::draft(BaseGladiator *gl1, BaseGladiator *gl2) {
    return gl2;
}

Combat::Combat() {
//why need this, without this, it throws an error
}
