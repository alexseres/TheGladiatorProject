//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_BASEGLADIATOR_H
#define THEGLADIATORPROJECT_BASEGLADIATOR_H
#include <iostream>
#include "StatisticMultiplier.cpp"
#include "GladiatorType.cpp"

using namespace std;

class BaseGladiator {
protected:
    string Name;
    GladiatorType Type;
    int Level;
    double HP;
    double SP;
    double DEX;
    StaticticMultiplier hp_multiplier;
    StaticticMultiplier sp_multiplier;
    StaticticMultiplier dex_multiplier;
    double StarterHealth;
public:
  BaseGladiator(GladiatorType type, string name, double hp, double sp, double dex, int level){
        this-> Type = type;
        this-> Name = name;
        this-> HP = hp;
        this-> SP = sp;
        this-> DEX = dex;
        this-> Level = level;
        StarterHealth = HP;
    };

    string getGladiatorName() {return Name;}
    GladiatorType getGladiatorType(){return Type;}
    int getGladiatorLevel(){return Level;}
    double getHP()  {return HP;}
    double getSP()  {return SP;}
    double getDEX() {return DEX;}
    StaticticMultiplier getHpMultiplier() {return hp_multiplier;}
    StaticticMultiplier getSpMultiplier() {return sp_multiplier;}
    StaticticMultiplier getDexMultiplier()  {return dex_multiplier;}
    int getStarterHealth()  {return StarterHealth;}
    void increaseAbilities();
    void decreaseHpBy(int decreaser);
    void healUp();
    bool isDead = false;

};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
