//
// Created by Alex Seres on 12/04/2022.
//
#include "gtest/gtest.h"
#include "../src/Utils.h"

// check if the range does not overpass the limit
TEST(util_t, randomNumberTest){
    Utils utils;
    int res = utils.getRandomNumber(15);
    EXPECT_TRUE(res < 16);
}