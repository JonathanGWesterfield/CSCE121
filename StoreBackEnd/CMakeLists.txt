cmake_minimum_required(VERSION 3.6)
project(StoreBackEnd)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Store.cpp Store.h Customer.cpp Customer.h Product.cpp Product.h)
add_executable(StoreBackEnd ${SOURCE_FILES})