#include <iostream>
#include "Tournament.h"
#include "Utils.h"

using namespace std;



int main() {
    Tournament tournament;
    tournament.fillGladiatorsVectorAndAddWeapon();
    tournament.simulateTournament();

}
