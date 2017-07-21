cmake_minimum_required(VERSION 3.6)
project(Lab_35)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Library.cpp Library.h Book.cpp Book.h)
add_executable(Lab_35 ${SOURCE_FILES})