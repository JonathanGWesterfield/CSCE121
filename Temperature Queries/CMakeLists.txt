cmake_minimum_required(VERSION 3.6)
project(Temperature_Queries)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp linkedlist.cpp linkedlist.h node.h temperaturedb.cpp temperaturedb.h s050_TX-70s.dat
        s050_TX-2000-2015.dat temps-3lines.dat temps-7lines.dat queries.dat queries-70s.dat queries-2000s.dat
        results-3lines.dat results-7lines.dat results-70s.dat results-2000s.dat)
add_executable(Temperature_Queries ${SOURCE_FILES})