cmake_minimum_required(VERSION 3.21)
project(TheGladiatorProject)
include_directories(test)
include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)

FetchContent_MakeAvailable(googletest)

# the above configuration declares a dependency on GoogleTest which is downloaded from GitHub
# 609281088cfefc76f9d0ce82e1ff6c30cc3591e5 is a git commit of the googletest version to use

enable_testing()

add_executable(
    BaseGladiatorTest
    BaseGladiatorTest.cpp

)

target_link_libraries(
    BaseGladiatorTest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(BaseGladiatorTest)

# the above config enables testing in CMake, declares the c++ test binary you want to build (BaseGladiator/test)
# and links it to GoogleTest (gtest_main). The last two lines enable Cmake's test runner to discover the tests
# included in the binary, using the GoogleTest CMake module


