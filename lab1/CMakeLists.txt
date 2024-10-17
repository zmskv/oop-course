add_executable(main_lab1 main.cpp)

add_executable(tests_lab1 tests/test_clean_number.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab1 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab1)
