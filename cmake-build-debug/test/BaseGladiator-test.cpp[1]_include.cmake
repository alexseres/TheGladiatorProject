if(EXISTS "/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/cmake-build-debug/test/BaseGladiator-test.cpp[1]_tests.cmake")
  include("/Users/alexseres/OwnCplusPlusProjects/TheGladiatorProject/cmake-build-debug/test/BaseGladiator-test.cpp[1]_tests.cmake")
else()
  add_test(BaseGladiator-test.cpp_NOT_BUILT BaseGladiator-test.cpp_NOT_BUILT)
endif()
