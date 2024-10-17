add_executable(main_lab3 main.cpp)

add_executable(tests_lab3 tests/test_figure.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab3 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab3)
