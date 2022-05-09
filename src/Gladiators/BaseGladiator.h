#ifndef THEGLADIATORPROJECT_BASEGLADIATOR_H
#define THEGLADIATORPROJECT_BASEGLADIATOR_H
#include <iostream>
#include "StatisticMultiplier.cpp"
#include "GladiatorType.cpp"
#include "SpecialWeaponEffects/SpecialWeaponEffect.cpp"


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
    const bool hasWeaponEffect;

public:
    SpecialWeaponEffect weapon;
    BaseGladiator(GladiatorType type, string name, int hp, int sp, int dex, int level, bool weaponEffect): hasWeaponEffect(weaponEffect){
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
//    void setHP(int val){HP = val;}
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
    bool isBleeding = false;
    bool isPoisoned = false;
    bool isParalyzed = false;
    bool isBurning = false;


};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
