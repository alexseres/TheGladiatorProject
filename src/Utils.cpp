//
// Created by Alex Seres on 11/04/2022.
//

#include "Utils.h"
#include "iostream"
#include <fstream>

using namespace std;

const int Utils::getRandomNumber(int max) {
    return rand() % max;
}
const int Utils::getRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}
const int Utils::getClampValue(int number) {
    int lower = 10;
    int upper = 100;
    return max(lower, min(number, upper));
}

const double Utils::getRandomDouble() {
    double min = 0.1;
    double max = 0.5;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

string Utils::getLineByRandomNumber(int randNum, string fileName) {
    string neededLine;
    ifstream file;
    file.open(fileName, ios::out);
    if(file.is_open()){
        int counter = 0;
        for(string line; (getline(file, line));){
            if(counter == randNum){
                neededLine = line;
                break;
            }
            counter++;
        }
        file.close();
    }
    else{
        cout << "Unable to open file" << endl;
    }
    return neededLine;
}

