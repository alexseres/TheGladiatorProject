#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/GladiatorFactory.h"
#include "../src/Combat.h"




TEST(CombatTest, simulateCombatTest){
    Combat combat;
    Utils util;
    int gladiatorsLevel = 4;
    bool chanceForWeaponEffect1 = util.getRandomNumber(0,100) < 11 ? true : false;
    bool chanceForWeaponEffect2 = util.getRandomNumber(0,100) < 11 ? true : false;
    Paralyze para(4, true);
    Bleed bleed(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", 65, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", 35, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &para;
    gladiator2.weapon = &bleed;

    BaseGladiator winner = combat.simulateCombat(gladiator1, gladiator2);

    EXPECT_TRUE(!winner.isDead);
    EXPECT_TRUE(gladiatorsLevel < winner.getGladiatorLevel());
}

TEST(CombatTest, announceWinnerTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int gladiatorsHp = 34;
    string message;
    Paralyze para(4, true);
    Bleed bleed(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", 65, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", 35, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &para;
    gladiator2.weapon = &bleed;
    combat.announceWinner(gladiator1, gladiator2);

    EXPECT_TRUE(gladiator1.getGladiatorLevel() > gladiatorsLevel);
    EXPECT_TRUE(gladiator1.getMatchWon() == 1);

}

TEST(CombatTest, turnTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int gladiatorsHp = 34;
    string gladiator1Name = "Archer Maximus";
    string expectedMessage = "Archer Maximus turns.";
    string message;
    Paralyze para(4, true);
    Bleed bleed(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", 65, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", 35, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &para;
    gladiator2.weapon = &bleed;

    EXPECT_NO_THROW(combat.turn(gladiator1, gladiator2));
}

TEST(CombatTest, checkIfIsWeaponizedTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int hp = 37;
    Paralyze para(4, true);
    Bleed bleed(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", hp, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", hp, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &bleed;
    gladiator2.weapon = &para;
    gladiator2.isWeaponized = true;
    combat.checkIfIsWeaponized(gladiator2, gladiator1);
    EXPECT_FALSE(hp == gladiator2.getHP());
}

TEST(CombatTest, checkIfIsParalyzedTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int hp = 37;
    Paralyze para(4, true);
    Bleed bleed(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", hp, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", hp, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &bleed;
    gladiator2.weapon = &para;
    gladiator1.isWeaponized = true;
    bool paralyzed = combat.checkIfIsParalyzed(gladiator2, gladiator1);
    EXPECT_TRUE(paralyzed);
    EXPECT_FALSE(hp == gladiator1.getHP());
}

TEST(CombatTest, isUsingWeaponTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int hp = 37;
    Paralyze para(4, true);
    Bleed poison(102,true);
    BaseGladiator gladiator1(Archer, "Archer Maximuss", hp, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutuss", hp, 54, 86, gladiatorsLevel);
    gladiator1.weapon =  &poison;
    gladiator2.weapon = &para;
    bool UsedWeapon = combat.isUsingWeapon(gladiator1, gladiator2);
    EXPECT_FALSE(UsedWeapon);
}