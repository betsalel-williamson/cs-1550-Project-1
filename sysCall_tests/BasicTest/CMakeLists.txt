include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(../../sysCall/include ../../sysCall/src)

add_executable(RunBasicTest
        framebuffer_tests.cpp
        mmap_tests.cpp
        ../../sysCall/src/syscalls.c
        ../../sysCall/include/syscalls.h)

target_link_libraries(RunBasicTest gtest gtest_main)

add_test(NAME RunBasicTest
        COMMAND RunBasicTest)