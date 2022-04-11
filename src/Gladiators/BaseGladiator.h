//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_BASEGLADIATOR_H
#define THEGLADIATORPROJECT_BASEGLADIATOR_H
#include <iostream>
using namespace std;


class BaseGladiator {
protected:
    const string Name;
    string FullName;
    string Type;
public:

    BaseGladiator(string name): Name(name){}



};


#endif //THEGLADIATORPROJECT_BASEGLADIATOR_H
