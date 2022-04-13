//
// Created by Alex Seres on 11/04/2022.
//

#include "Utils.h"
#include "iostream"
#include <fstream>
using namespace std;

int Utils::getRandomNumber(int max) {
    return rand() % max + 1;
}

string Utils::getLineByRandomNumber(int randNum) {
    string neededLine;
    ifstream file;
    file.open(getFileName(), ios::out);
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