cmake_minimum_required(VERSION 3.22)

add_library(plugboard plugboard.cpp)

target_link_libraries(plugboard common)

target_include_directories(plugboard PUBLIC ./)