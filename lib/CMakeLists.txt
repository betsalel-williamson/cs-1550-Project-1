cmake_minimum_required(VERSION 2.8)

# Define helper functions and macros used by Google Test.
include(../test/lib/googletest/cmake/internal_utils.cmake)

project(lib CXX C)

config_compiler_and_linker()  # Defined in internal_utils.cmake.

# Where Project_1's .h files can be found.
include_directories(
        ${lib_SOURCE_DIR}/include
        ${lib_SOURCE_DIR})

# Where Project_1's libraries can be found.
link_directories(${lib_BINARY_DIR}/src)

########################################################################
#
# Defines the lib libraries.  User tests should link
# with one of them.

# Project_1 libraries.  We build them using more strict warnings than what
# are used for other targets, to ensure that gtest can be compiled by a user
# aggressive about warnings.
cxx_library(Project_1_lib "${cxx_strict}" src/syscalls.c)
target_link_libraries(Project_1_lib)