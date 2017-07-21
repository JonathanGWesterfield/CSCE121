cmake_minimum_required(VERSION 3.6)
project(StoreBackEnd2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp customer.cpp customer.h product.cpp product.h store.cpp store.h)
add_executable(StoreBackEnd2 ${SOURCE_FILES})