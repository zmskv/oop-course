add_executable(main_lab4 main.cpp)

add_executable(tests_lab4 tests/test_figure.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab4 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab4)
