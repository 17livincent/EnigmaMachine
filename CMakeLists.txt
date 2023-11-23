cmake_minimum_required(VERSION 3.22)

project(EnigmaMachine VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-Wall -Werror -g)

add_subdirectory(common)
add_subdirectory(entrywheel)
add_subdirectory(plugboard)
add_subdirectory(reflector)
add_subdirectory(rotor)
add_subdirectory(enigma)
add_subdirectory(test)

enable_testing()
add_test(NAME test_entrywheel COMMAND test_entrywheel)
add_test(NAME test_plugboard COMMAND test_plugboard)
add_test(NAME test_reflector COMMAND test_reflector)
add_test(NAME test_rotor COMMAND test_rotor)
add_test(NAME test_enigmaI COMMAND test_enigmaI)