cmake_minimum_required(VERSION 3.22)

add_library(entrywheel entrywheel.cpp)

target_link_libraries(entrywheel common)

target_include_directories(entrywheel PUBLIC ./)