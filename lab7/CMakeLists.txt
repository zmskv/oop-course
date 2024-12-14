add_executable(tests_lab7 game/tests/tests_game.cpp)

include_directories(${CMAKE_SOURCE_DIR}/external/googletest/googletest/include)
target_link_libraries(tests_lab7 gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests_lab7)
