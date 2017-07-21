cmake_minimum_required(VERSION 3.6)
project(ClassPractice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Date.h Date.cpp)
add_executable(ClassPractice ${SOURCE_FILES})