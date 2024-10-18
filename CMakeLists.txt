cmake_minimum_required(VERSION 3.10)
project(oop_course)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)

set(GTEST_DIR external/googletest)


enable_testing()
