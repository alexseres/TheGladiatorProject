//
// Created by Alex Seres on 11/04/2022.
//

#ifndef THEGLADIATORPROJECT_UTILS_H
#define THEGLADIATORPROJECT_UTILS_H
#include <iostream>
using namespace std;

class Utils {
private:
    string FileName;
    int GladiatorNamesSize;

public:
    string getFileName(){return FileName;}
    void setFileName(string fileName){FileName = fileName; }
    int getGladiatorNamesSize(){return GladiatorNamesSize;}
    void setGladiatorNamesSize(int size){GladiatorNamesSize = size;}
    int const getRandomNumber(int max);
    int const getRandomNumber(int min, int max);
    double const getRandomDouble();
    string getLineByRandomNumber(int randNum, string fileName);
    const int getClampValue(int number);
};


#endif //THEGLADIATORPROJECT_UTILS_H
