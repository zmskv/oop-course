cmake_minimum_required(VERSION 3.10)
project(oop_lab1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(main main.cpp)

enable_testing()

add_executable(tests tests/test_clean_number.cpp)


target_link_libraries(tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)