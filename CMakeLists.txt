cmake_minimum_required(VERSION 2.8)
project(Project1)
enable_testing()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

set(SOURCE_FILES main.c sysCall/src/syscalls.c sysCall/include/syscalls.h)

add_executable(Project1 ${SOURCE_FILES})

add_subdirectory(sysCall)
add_subdirectory(sysCall_tests)