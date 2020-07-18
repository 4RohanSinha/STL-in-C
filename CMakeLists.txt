#compiles the test file along with the libraries
#in the future, only have it compile the library
#use add_library
cmake_minimum_required(VERSION 3.7)

project(TestSTL)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

file(GLOB SOURCES "src/*.c")

add_executable(TestSTL ${SOURCES})
