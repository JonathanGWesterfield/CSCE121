cmake_minimum_required(VERSION 3.0.0)
project(FLTK_Practice)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
set(FLTK_DIR /usr/local/Cellar/fltk/build)

find_package(FLTK REQUIRED NO_MODULE)

INCLUDE_DIRECTORIES(${FLTK_INCLUDE_DIRS})
LINK_DIRECTORIES(/usr/local/lib)

add_executable(FLTK_Practice main.cpp)
# target_include_directories(FLTK_Practice PUBLIC ${FLTK_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(FLTK_Practice fltk)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")



