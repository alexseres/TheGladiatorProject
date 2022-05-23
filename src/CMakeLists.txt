cmake_minimum_required(VERSION 3.21)
project(TheGladiatorProject)
set(CMAKE_CXX_STANDARD 14)
include_directories(Gladiators)
include_directories(SpecialWeaponEffects)

add_executable(TheGladiatorProject
        main.cpp
        Tournament.h
        Combat.h
        GladiatorFactory.h
        Gladiators/Archer.h
        Gladiators/Assassin.h
        Gladiators/BaseGladiator.h
        Gladiators/Brutal.h
        Gladiators/StatisticMultiplier.cpp
        Gladiators/Swordsman.h
        SpecialWeaponEffects/Bleed.h
        SpecialWeaponEffects/Paralyze.h
        SpecialWeaponEffects/Poison.h
        SpecialWeaponEffects/SpecialWeaponEffect.h
        Utils.h
        Combat.cpp
        GladiatorFactory.cpp
        Gladiators/Archer.cpp
        Gladiators/Assassin.cpp
        Gladiators/BaseGladiator.cpp
        Gladiators/Brutal.cpp
        Gladiators/StatisticMultiplier.cpp
        Gladiators/Swordsman.cpp
        SpecialWeaponEffects/Bleed.cpp
        SpecialWeaponEffects/Paralyze.cpp
        SpecialWeaponEffects/Poison.cpp
        SpecialWeaponEffects/SpecialWeaponEffect.cpp
        Utils.cpp
        Tournament.cpp)
