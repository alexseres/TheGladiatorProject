#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/GladiatorFactory.h"
#include "../src/Tournament.h"

TEST(TournamentTest, fillGladiatorTest){
//    Tournament tournament;
//    tournament.fillGladiatorsVector();
//    int expectedGladiatorSize = 64;
//    EXPECT_EQ(tournament.getGladiators().size() , expectedGladiatorSize);
}

TEST(TournamentTest, simulateTest){
    Tournament tournament;
    tournament.fillGladiatorsVector();
    tournament.simulateTournament();


}