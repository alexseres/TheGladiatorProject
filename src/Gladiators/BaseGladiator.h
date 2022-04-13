//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_BASEGLADIATOR_H
#define THEGLADIATORPROJECT_BASEGLADIATOR_H
#include <iostream>
#include "StatisticMultiplier.cpp"

using namespace std;

class BaseGladiator {
protected:
    const string Name;
    string FullName;
    string Type;
    int Level;
    int HP;
    int SP;
    int DEX;
    StaticticMultiplier hp_multiplier;
    StaticticMultiplier sp_multiplier;
    StaticticMultiplier dex_multiplier;
    int StarterHealth;
    int CurrentHealth;
public:
    BaseGladiator(string name): Name(name){};
    virtual void overrideMultipliers();
};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
