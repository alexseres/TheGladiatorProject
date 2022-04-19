//
// Created by Alex Seres on 12/04/2022.
//

#include "gtest/gtest.h"
#include "../src/Gladiators/Archer.h"


TEST(BaseGladiatorTests, check_IncreaseAbilities_Method){
    double hp = 27;
    double sp = 65;
    double dex = 32;
    int level = 4;
    GladiatorType gladiatorType = Archer;
    class Archer archer(gladiatorType,"Bela", hp, sp, dex, level);
    archer.increaseAbilities();
    EXPECT_TRUE(hp < archer.getHP());
    EXPECT_TRUE(sp < archer.getSP());
    EXPECT_TRUE(dex < archer.getDEX());

}