cmake_minimum_required(VERSION 3.10)
project(oop-course)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)


add_subdirectory(lab1)