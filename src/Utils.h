//
// Created by Alex Seres on 11/04/2022.
//

#ifndef THEGLADIATORPROJECT_UTILS_H
#define THEGLADIATORPROJECT_UTILS_H
#include <iostream>
using namespace std;

class Utils {
private:
    const string fileName = "/GladiatorPossibleNames";
public:
    string getFileName(){return fileName;}
    int getRandomNumber(int max);
    string getLineByRandomNumber(int randNum);
};


#endif //THEGLADIATORPROJECT_UTILS_H
