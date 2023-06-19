cmake_minimum_required(VERSION 3.22)

add_library(enigma enigmaI.cpp)

target_link_libraries(enigma common plugboard entrywheel rotor reflector)

target_include_directories(enigma PUBLIC ./)