#ifndef THEGLADIATORPROJECT_BASEGLADIATOR_H
#define THEGLADIATORPROJECT_BASEGLADIATOR_H
#include <iostream>
#include "StatisticMultiplier.cpp"
#include "GladiatorType.cpp"
#include "SpecialWeaponEffects/SpecialWeaponEffect.cpp"
#include "SpecialWeaponEffects/Paralyze.h"


using namespace std;

class BaseGladiator {
protected:
    string Name;
    GladiatorType Type;
    int Level = 0;
    int HP = 0;
    int SP = 0;
    int DEX = 0;
    StaticticMultiplier hp_multiplier;
    StaticticMultiplier sp_multiplier;
    StaticticMultiplier dex_multiplier;
    int StarterHealth = 0;

public:

    BaseGladiator(GladiatorType type,
                  string name,
                  int hp,
                  int sp,
                  int dex,
                  int level){
        this-> Type = type;
        this-> Name = name;
        this-> HP = hp;
        this-> SP = sp;
        this-> DEX = dex;
        this-> Level = level;
        StarterHealth = HP;
    };
    SpecialWeaponEffect *weapon;

    string getGladiatorName() {return Name;}
    GladiatorType getGladiatorType(){return Type;}
    int getGladiatorLevel(){return Level;}
    int getHP() {return HP;}
    int getSP()  {return SP;}
    int getDEX() {return DEX;}
    StaticticMultiplier getHpMultiplier() {return hp_multiplier;}
    StaticticMultiplier getSpMultiplier() {return sp_multiplier;}
    StaticticMultiplier getDexMultiplier()  {return dex_multiplier;}
    int getStarterHealth()  {return StarterHealth;}
    void increaseAbilities();
    void decreaseHpBy(int decreaser);
    void healUp();
    bool isDead = false;

    void weaponize(BaseGladiator &enemy);
    bool isWeaponized = false;


};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
