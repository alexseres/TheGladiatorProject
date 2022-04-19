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
    const string Name;
    string FullName;
    GladiatorType Type;
    int Level;
    double HP;
    double SP;
    double DEX;
    StaticticMultiplier hp_multiplier;
    StaticticMultiplier sp_multiplier;
    StaticticMultiplier dex_multiplier;
    int StarterHealth;
    int CurrentHealth;
public:
    BaseGladiator(GladiatorType type, string name, double hp, double sp, double dex, int level):Type(type),Name(name), HP(hp), SP(sp), DEX(dex), Level(level){};
    double getHP() const {return HP;}
    double getSP() const {return SP;}
    double getDEX() const {return DEX;}
    void increaseAbilities();
};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
