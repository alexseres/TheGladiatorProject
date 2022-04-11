//
// Created by Alex Seres on 08/04/2022.
//

#ifndef THEGLADIATORPROJECT_ARCHER_H
#define THEGLADIATORPROJECT_ARCHER_H


#include "BaseGladiator.h"

class Archer : public BaseGladiator{
////    //constructor inheritance, bloody amazing
//    using BaseGladiator::BaseGladiator;
private:

public:
    Archer(string name): BaseGladiator(name){ Type = "Archer"; FullName = Type + " " + Name; }
};


#endif //THEGLADIATORPROJECT_ARCHER_H
