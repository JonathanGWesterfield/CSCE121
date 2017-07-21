cmake_minimum_required(VERSION 3.6)
project(NewPalindromes)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp functions.cpp functions.h)
add_executable(NewPalindromes ${SOURCE_FILES})