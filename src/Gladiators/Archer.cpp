//
// Created by Alex Seres on 08/04/2022.
//

#include "Archer.h"

string BaseGladiator::getName() {
    return (string)typeid(Archer).name() + " " + Name;
}