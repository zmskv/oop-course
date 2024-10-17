add_executable(main_lab2 main.cpp)

add_executable(tests_lab2 tests/test_binary.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab2 gtest gtest_main)


include(GoogleTest)
gtest_discover_tests(tests_lab2)
