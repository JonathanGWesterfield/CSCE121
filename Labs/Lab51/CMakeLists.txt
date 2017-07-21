cmake_minimum_required(VERSION 3.0.0)
project(Lab_51_FLTK)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FLTK_DIR /usr/local/Cellar/fltk/build)

find_package(FLTK REQUIRED NO_MODULE)

INCLUDE_DIRECTORIES(${FLTK_INCLUDE_DIRS})
LINK_DIRECTORIES(/usr/local/lib)

set(SOURCE_FILES main.cpp Circle.cpp Circle.h Rectangle.cpp Rectangle.h Shape.cpp Shape.h Triangle.cpp Triangle.h)
add_executable(Lab_51_FLTK ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(Lab_51_FLTK fltk)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")