//
// Created by Alex Seres on 11/04/2022.
//

#include "Utils.h"
#include "iostream"
using namespace std;

int Utils::getRandomNumber(int min, int max) {
    return rand() % max + 1;
}