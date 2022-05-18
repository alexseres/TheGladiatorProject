#include "gtest/gtest.h"
#include "../src/Gladiators/BaseGladiator.h"
#include "../src/GladiatorFactory.h"
#include "../src/Tournament.h"


int expectedGladiatorSize = 64;
int expectedFights = 63;
int expectedMinimumLevel = 5;

TEST(TournamentTest, fillGladiatorTest){
    Tournament tournament;
    tournament.fillGladiatorsVectorAndAddWeapon();
    EXPECT_EQ(tournament.getGladiators().size() , expectedGladiatorSize);
}

TEST(TournamentTest, simulateTest){
    Tournament tournament;
    tournament.fillGladiatorsVectorAndAddWeapon();
    tournament.simulateTournament();
    EXPECT_EQ(expectedFights, tournament.getFightCounter());
}

TEST(TournamentTest, knockOutTest){
    Combat combat;
    Tournament tournament;
    tournament.fillGladiatorsVectorAndAddWeapon();
    BaseGladiator champion = tournament.knockOut(tournament.getGladiators(), combat);
    EXPECT_TRUE(expectedMinimumLevel< champion.getGladiatorLevel());
    EXPECT_TRUE(!champion.isDead);
}

TEST(TournamentTest, sliceVectorTest){
    Tournament tournament;
    tournament.fillGladiatorsVectorAndAddWeapon();
    int expectedResult = tournament.getGladiators().size() / 2;
    vector<BaseGladiator> result = tournament.sliceVector(tournament.getGladiators(), 0, tournament.getGladiators().size() / 2);
    EXPECT_EQ(result.size(), expectedResult);
}