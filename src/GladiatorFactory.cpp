#include "GladiatorFactory.h"
#include "Utils.h"


void GladiatorFactory::generateGladiators() {
    srand(time(NULL));
    for(int i = 0;i < GladiatorVectorSize;i++){
        BaseGladiator *gladiator = generateGladiator();
        GladiatorArr[i] = gladiator;
    }
}

BaseGladiator *GladiatorFactory::generateGladiator() {
    int randomGladiatorTypeIndex = rand() % GladiatorPossibilitiesSize;
    int randomGladiatorNum = OwnUtils.getRandomNumber(GladiatorNameListSize);
    int randomGladiatorLevel = OwnUtils.getRandomNumber(1, 5);
    int randomHP = OwnUtils.getRandomNumber(25,100);
    int randomSP = OwnUtils.getRandomNumber(25, 100);
    int randomDEX = OwnUtils.getRandomNumber(25,100);
    string randomGladiatorName = OwnUtils.getLineByRandomNumber(randomGladiatorNum, GladiatorFileName);
    switch (GladiatorPossibilities[randomGladiatorTypeIndex]) {
        case Archer: {
            string fullName = "Archer " + randomGladiatorName;
            class Archer *archer = new class Archer(Archer, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return archer;
        }
        case Assassin: {
            string fullName = "Assassin " + randomGladiatorName;
            class Assassin *assassin = new class Assassin(Assassin, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return assassin;
        }
        case Brutal: {
            string fullName = "Brutal " + randomGladiatorName;
            class Brutal *brutal = new class Brutal(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return brutal;
        }
        case Swordsman: {
            string fullName = "Swordsman " + randomGladiatorName;
            class Swordsman *swordsman = new class Swordsman(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel);
            return swordsman;
        }
    }
}
