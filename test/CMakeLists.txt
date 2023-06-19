cmake_minimum_required(VERSION 3.22)

add_executable(test_entrywheel test_entrywheel.cpp)
target_link_libraries(test_entrywheel entrywheel)

add_executable(test_plugboard test_plugboard.cpp)
target_link_libraries(test_plugboard plugboard)

add_executable(test_reflector test_reflector.cpp)
target_link_libraries(test_reflector reflector)

add_executable(test_rotor test_rotor.cpp)
target_link_libraries(test_rotor rotor)

add_executable(test_enigmaI test_enigmaI.cpp)
target_link_libraries(test_enigmaI enigma)

add_executable(run_enigmaI run_enigmaI.cpp)
target_link_libraries(run_enigmaI enigma)
