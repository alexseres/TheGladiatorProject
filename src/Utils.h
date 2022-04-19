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
    int getRandomNumber(int max);
    int getRandomNumber(int min, int max);
    string getLineByRandomNumber(int randNum, string fileName);
};


#endif //THEGLADIATORPROJECT_UTILS_H
