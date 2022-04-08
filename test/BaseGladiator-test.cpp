#include "gtest/gtest.h"
#include "../src/Gladiators/Archer.h"


//first argument is a group name and the second you can specify the test
TEST(GladiatorTest, test1){
    Archer archer1;
    //check if its empty
    EXPECT_EQ(0, archer1.getName())
}