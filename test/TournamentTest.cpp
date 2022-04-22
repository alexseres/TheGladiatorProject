#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/GladiatorFactory.h"
#include "../src/Tournament.h"

TEST(TournamentTest, fillGladiatorTests){
    Tournament tournament;
    tournament.fillGladiatorsVector();
    int expectedGladiatorSize = 64;
    EXPECT_EQ(tournament.getGladiators().size() , expectedGladiatorSize);

}