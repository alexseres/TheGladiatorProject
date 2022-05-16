#include "GladiatorFactory.h"
#include "Utils.h"



void GladiatorFactory::generateGladiators() {
    srand(time(NULL));
    for(int i = 0;i < GladiatorVectorSize;i++){
        BaseGladiator *gladiator = generateGladiator();
        GladiatorArr[i] = gladiator;
    }
}


SpecialWeaponEffect GladiatorFactory::generateWeaponEffect() {
    bool chanceForWeaponEffect = OwnUtils.getRandomNumber(0,100) < 11 ? true : false;
    int randomNum = OwnUtils.getRandomNumber(0,100);
    int turnCounter;
    if(randomNum <= 33){
        turnCounter = 101;
        return Bleed(turnCounter, chanceForWeaponEffect);
    }
    else if(randomNum >=67){
        turnCounter = 4;
        return Paralyze(turnCounter, chanceForWeaponEffect);
    }
    else{
        turnCounter = 3;
        return Poison(turnCounter, chanceForWeaponEffect);
    }

}

BaseGladiator *GladiatorFactory::generateGladiator() {
    int randomGladiatorTypeIndex = rand() % GladiatorPossibilitiesSize;
    int randomGladiatorNum = OwnUtils.getRandomNumber(GladiatorNameListSize);
    int randomGladiatorLevel = OwnUtils.getRandomNumber(1, 5);
    int randomHP = OwnUtils.getRandomNumber(25,100);
    int randomSP = OwnUtils.getRandomNumber(25, 100);
    int randomDEX = OwnUtils.getRandomNumber(25,100);
    SpecialWeaponEffect effect = generateWeaponEffect();
    string randomGladiatorName = OwnUtils.getLineByRandomNumber(randomGladiatorNum, GladiatorFileName);
    switch (GladiatorPossibilities[randomGladiatorTypeIndex]) {
        case Archer: {
            string fullName = "Archer " + randomGladiatorName;
            class Archer *archer = new class Archer(Archer, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel, effect);
            return archer;
        }
        case Assassin: {
            string fullName = "Assassin " + randomGladiatorName;
            class Assassin *assassin = new class Assassin(Assassin, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel, effect);
            return assassin;
        }
        case Brutal: {
            string fullName = "Brutal " + randomGladiatorName;
            class Brutal *brutal = new class Brutal(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel, effect);
            return brutal;
        }
        case Swordsman: {
            string fullName = "Swordsman " + randomGladiatorName;
            class Swordsman *swordsman = new class Swordsman(Brutal, fullName, randomHP, randomSP, randomDEX, randomGladiatorLevel, effect);
            return swordsman;
        }
    }
}
