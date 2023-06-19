cmake_minimum_required(VERSION 3.22)

add_library(rotor rotor.cpp)

target_link_libraries(rotor common)

target_include_directories(rotor PUBLIC ./)