cmake_minimum_required(VERSION 3.21)
project(TheGladiatorProject)

set(CMAKE_CXX_STANDARD 14)

add_executable(TheGladiatorProject main.cpp Gladiators/BaseGladiator.cpp Gladiators/BaseGladiator.h Gladiators/Archer.cpp Gladiators/Archer.h Gladiators/Assassin.cpp Gladiators/Assassin.h Gladiators/Swordsman.cpp Gladiators/Swordsman.h Gladiators/Brutal.cpp Gladiators/Brutal.h)
