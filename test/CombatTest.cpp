#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/GladiatorFactory.h"
#include "../src/Combat.h"




TEST(CombatTest, simulateCombatTest){
    Combat combat;
    int gladiatorsLevel = 4;
    BaseGladiator gladiator1(Archer, "Archer Maximus", 65, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutus", 35, 54, 86, gladiatorsLevel);

    BaseGladiator winner = combat.simulateCombat(gladiator1, gladiator2);

    EXPECT_TRUE(!winner.isDead);
    EXPECT_TRUE(gladiatorsLevel < winner.getGladiatorLevel());
}

TEST(CombatTest, announceWinnerTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int gladiatorsHp = 34;
    string message;
    BaseGladiator gladiator1(Archer, "Archer Maximus", gladiatorsHp, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutus", gladiatorsHp, 54, 86, gladiatorsLevel);

    combat.announceWinner(gladiator1, gladiator2, message);

    EXPECT_TRUE(gladiator1.getGladiatorLevel() > gladiatorsLevel);
    EXPECT_TRUE(message.find("Winner") !=  std::string::npos);

}

TEST(CombatTest, turnTest){
    Combat combat;
    int gladiatorsLevel = 4;
    int gladiatorsHp = 34;
    string gladiator1Name = "Archer Maximus";
    string expectedMessage = "Archer Maximus turns.";
    string message;
    BaseGladiator gladiator1(Archer, gladiator1Name, gladiatorsHp, 34, 64, gladiatorsLevel);
    BaseGladiator gladiator2(Swordsman, "Swordsman Brutus", gladiatorsHp, 54, 86, gladiatorsLevel);

    combat.turn(gladiator1,gladiator2);

    EXPECT_EQ(expectedMessage, combat.getCombatLogs()[0]);

}