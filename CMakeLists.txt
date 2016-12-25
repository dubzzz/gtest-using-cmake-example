cmake_minimum_required(VERSION 2.8.8)

project(myProject C CXX)
find_package(GTest REQUIRED)

message(STATUS "CMake version   : " ${CMAKE_SYSTEM_VERSION})
message(STATUS "Compiler        : " ${CMAKE_CXX_COMPILER})
message(STATUS "Operating System: " ${CMAKE_SYSTEM})
set(CMAKE_CXX_STANDARD 14)

enable_testing()
include_directories(SYSTEM ${GTEST_INCLUDE_DIRS})

file(GLOB SRCS *.cpp)
add_executable(mytest ${SRCS})
target_link_libraries(mytest ${GTEST_BOTH_LIBRARIES})
add_test(NAME mytest COMMAND mytest)
