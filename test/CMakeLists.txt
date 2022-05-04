cmake_minimum_required(VERSION 3.21)
project(TheGladiatorProject)
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

# the above configuration declares a dependency on GoogleTest which is downloaded from GitHub
# 609281088cfefc76f9d0ce82e1ff6c30cc3591e5 is a git commit of the googletest version to use

enable_testing()

add_executable(BaseGladiatorTest BaseGladiatorTest.cpp ../src/Gladiators/BaseGladiator.cpp)
add_executable(UtilsTest UtilsTest.cpp ../src/Utils.cpp)
add_executable(GladiatorFactoryTest  GladiatorFactoryTest.cpp ../src/GladiatorFactory.cpp ../src/Utils.cpp ../src/Gladiators/BaseGladiator.cpp)
add_executable(TournamentTest TournamentTest.cpp ../src/Tournament.cpp ../src/Combat.cpp ../src/GladiatorFactory.cpp ../src/Utils.cpp ../src/Gladiators/BaseGladiator.cpp)


target_link_libraries(BaseGladiatorTest gtest_main)
target_link_libraries(UtilsTest gtest_main)
target_link_libraries(GladiatorFactoryTest gtest_main)
target_link_libraries(TournamentTest gtest_main)

add_test(NAME BaseGladiatorTest COMMAND test1)
add_test(NAME util_t COMMAND randomNumberTest)
add_test(NAME GladiatorFactoryTest COMMAND generateGladiatorTest generateGladiatorsTest)
add_test(NAME TournamentTest COMMAND fillGladiatorsTest simulateTest sliceVectorTest knockOutTes)

#include(GoogleTest)
#gtest_discover_tests(
#    BaseGladiatorTest
#    UtilsTest
#)

# the above config enables testing in CMake, declares the c++ test binary you want to build (BaseGladiator/test)
# and links it to GoogleTest (gtest_main). The last two lines enable Cmake's test runner to discover the tests
# included in the binary, using the GoogleTest CMake module


