include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RunBasicTest framebuffer_tests.cpp mmap_tests.cpp ../../sysCall/syscalls.h ../../sysCall/syscalls.c)

target_link_libraries(RunBasicTest gtest gtest_main)

add_test(NAME RunBasicTest
        COMMAND RunBasicTest)