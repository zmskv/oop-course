cmake_minimum_required(VERSION 3.10)
project(oop_lab3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(main_lab3 main.cpp)

enable_testing()

add_executable(tests_lab3 tests/test_figure.cpp)

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG release-1.11.0
)
FetchContent_MakeAvailable(googletest)

target_link_libraries(tests_lab3 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab3)