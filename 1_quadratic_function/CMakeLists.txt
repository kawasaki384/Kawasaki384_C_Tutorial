#set CMake Version
cmake_minimum_required(VERSION 3.13)

project(quadratic_function C)

add_executable(quadratic_function quadratic_function.c)

target_link_libraries(quadratic_function PUBLIC m)