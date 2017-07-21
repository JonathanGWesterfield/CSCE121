cmake_minimum_required(VERSION 3.0.0)
project(Lab_52)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FLTK_DIR /usr/local/Cellar/fltk/build)

find_package(FLTK REQUIRED NO_MODULE)

INCLUDE_DIRECTORIES(${FLTK_INCLUDE_DIRS})
LINK_DIRECTORIES(/usr/local/lib)

set(SOURCE_FILES main.cpp cloudy.gif fog.gif lightning.gif partsunny.gif rain.gif sunny.gif)
add_executable(Lab_52 ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(Lab_52 fltk)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")