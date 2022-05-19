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
//    Combat combat;
//    int gladiatorsLevel = 4;
//    int gladiatorsHp = 34;
//    string message;
////    Bleed bleed(101, chanceForWeaponEffect1);
////    Poison poison(4, chanceForWeaponEffect2);
//    Paralyze para(4, true);
//    BaseGladiator gladiator1(Archer, "Archer Maximus", 65, 34, 64, gladiatorsLevel, para);
//    BaseGladiator gladiator2(Swordsman, "Swordsman Brutus", 35, 54, 86, gladiatorsLevel,para);
//
//    combat.announceWinner(gladiator1, gladiator2, message);
//
//    EXPECT_TRUE(gladiator1.getGladiatorLevel() > gladiatorsLevel);
//    EXPECT_TRUE(message.find("Winner") !=  std::string::npos);

}

TEST(CombatTest, turnTest){
//    Combat combat;
//    int gladiatorsLevel = 4;
//    int gladiatorsHp = 34;
//    string gladiator1Name = "Archer Maximus";
//    string expectedMessage = "Archer Maximus turns.";
//    string message;
////    Bleed bleed(101, chanceForWeaponEffect1);
////    Poison poison(4, chanceForWeaponEffect2);
//    Paralyze para(4, true);
//    BaseGladiator gladiator1(Archer, "Archer Maximus", 65, 34, 64, gladiatorsLevel, para);
//    BaseGladiator gladiator2(Swordsman, "Swordsman Brutus", 35, 54, 86, gladiatorsLevel,para);
//
//    combat.turn(gladiator1,gladiator2);
//
//    EXPECT_EQ(expectedMessage, combat.getCombatLogs()[0]);

}