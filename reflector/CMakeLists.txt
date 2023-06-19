cmake_minimum_required(VERSION 3.22)

add_library(reflector reflector.cpp)

target_link_libraries(reflector common)

target_include_directories(reflector PUBLIC ./)