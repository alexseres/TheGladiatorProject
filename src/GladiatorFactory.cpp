//
// Created by Alex Seres on 11/04/2022.
//

#include "GladiatorFactory.h"
#include "Utils.h"


void GladiatorFactory::generateGladiators() {
    BaseGladiator *gladiatorArr[GladiatorsSize];

    for(int i = 0;i < GladiatorsSize;i++){

    }

}

BaseGladiator GladiatorFactory::generateGladiator() {
    int randomGladiatorTypeIndex = rand() % sizeof(GladiatorPossibilities)/sizeof(GladiatorPossibilities[0]);
    int randomGladiatorNum = OwnUtils.getRandomNumber(GladiatorsSize);
    int randomGladiatorLevel = OwnUtils.getRandomNumber(1, 5);
    int randomHP = OwnUtils.getRandomNumber(25,100);
    int randomSP = OwnUtils.getRandomNumber(25, 100);
    int randomDEX = OwnUtils.getRandomNumber(25,100);
    string randomGladiatorName = OwnUtils.getLineByRandomNumber(randomGladiatorNum, GladiatorFileName);
    switch (GladiatorPossibilities[randomGladiatorTypeIndex]) {
        case Archer: {
            string fullName = "Archer " + randomGladiatorName;
            class Archer archer(Archer, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return archer;
        }
        case Assassin: {
            string fullName = "Assassin" + randomGladiatorName;
            class Assassin assassin(Assassin, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return assassin;
        }
        case Brutal: {
            string fullName = "Brutal" + randomGladiatorName;
            class Brutal brutal(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return brutal;
        }
        case Swordsman: {
            string fullName = "Swordsman" + randomGladiatorName;
            class Swordsman swordsman(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return swordsman;
        }
    }
}
