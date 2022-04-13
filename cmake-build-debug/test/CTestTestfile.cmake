# CMake generated Testfile for 
# Source directory: /Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test
# Build directory: /Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/cmake-build-debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[BaseGladiatorTest]=] "test1")
set_tests_properties([=[BaseGladiatorTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;23;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
add_test([=[util_t]=] "randomNumberTest")
set_tests_properties([=[util_t]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;24;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
