cmake_minimum_required(VERSION 3.6)
project(Practice_Linked_List)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Node.cpp Node.h LinkedList.cpp LinkedList.h)
add_executable(Practice_Linked_List ${SOURCE_FILES})