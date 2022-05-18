#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/Gladiators/Archer.h"
#include "../src/Gladiators/Assassin.h"
#include "../src/Gladiators/Brutal.h"
#include "../src/Gladiators/Swordsman.h"
#include "../src/GladiatorFactory.h"

//Check if
TEST(GladiatorFactoryTest, generateGladiatorTest){
    //Arrange
    GladiatorFactory gf;

    //Assign
    BaseGladiator *g = gf.generateGladiator();

    //Assert
    EXPECT_TRUE(g->getGladiatorType() == Archer || g->getGladiatorType() == Assassin || g->getGladiatorType() == Swordsman || g->getGladiatorType() == Brutal);
    EXPECT_TRUE(g->getGladiatorLevel() > 0 && g->getGladiatorLevel() < 6);
    EXPECT_TRUE(g->getDEX() > 24 && g->getDEX() < 101);
    g->increaseAbilities();

}

TEST(GladiatorFactoryTest, generateGladiatorsTest){
    //Arrange
    GladiatorFactory gf;

    //Assign
    gf.generateGladiators();

    //Assert
    EXPECT_TRUE(gf.GladiatorArr[0] != gf.GladiatorArr[1]);
    for(BaseGladiator *gladiator : gf.GladiatorArr){
        // just check if class members been initialized and increased
        EXPECT_TRUE(gladiator->getGladiatorName().size() > 0);
        EXPECT_TRUE(gladiator->getDEX() > 0 );
        EXPECT_TRUE(gladiator->getGladiatorLevel() > 0 );
    }
    cout << "passed" << endl;
}