
cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(foward_test)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
find_package(FFmpeg)
if (FFmpeg_FOUND) 
    message(STATUS ">>> FFmpeg get!!!")
endif()

add_subdirectory(examples/test00_forward)
add_subdirectory(examples/test01_file_move)

