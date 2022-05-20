# CMake generated Testfile for 
# Source directory: /Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test
# Build directory: /Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/cmake-build-debug/test
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test([=[BaseGladiatorTest]=] "test1")
set_tests_properties([=[BaseGladiatorTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;29;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
add_test([=[util_t]=] "randomNumberTest")
set_tests_properties([=[util_t]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;30;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
add_test([=[GladiatorFactoryTest]=] "generateGladiatorTest" "generateGladiatorsTest")
set_tests_properties([=[GladiatorFactoryTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;31;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
add_test([=[TournamentTest]=] "fillGladiatorsTest" "simulateTest" "sliceVectorTest" "knockOutTes")
set_tests_properties([=[TournamentTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;32;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
add_test([=[CombatTest]=] "simulateCombatTest" "turnTest" "announceWinnerTest" "checkIfIsWeaponizedTest" "checkIfIsParalyzedTest" "isUsingWeaponTest")
set_tests_properties([=[CombatTest]=] PROPERTIES  _BACKTRACE_TRIPLES "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;33;add_test;/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/test/CMakeLists.txt;0;")
subdirs("../_deps/googletest-build")
