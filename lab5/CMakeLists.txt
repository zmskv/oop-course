add_executable(main_lab5 main.cpp)

add_executable(tests_lab5 tests/tests_list.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab5 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab5)
