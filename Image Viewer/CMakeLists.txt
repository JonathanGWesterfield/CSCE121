cmake_minimum_required(VERSION 3.0.0)
project(Image_Viewer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(FLTK_DIR /usr/local/Cellar/fltk/build)
find_package(FLTK REQUIRED NO_MODULE)

INCLUDE_DIRECTORIES(${FLTK_INCLUDE_DIRS})
LINK_DIRECTORIES(/usr/local/lib)

set(SOURCE_FILES main.cpp NavButton.cpp NavButton.h Viewer.cpp Viewer.h)
add_executable(Image_Viewer ${SOURCE_FILES})

TARGET_LINK_LIBRARIES(Image_Viewer fltk)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")