include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        ${SysCallLibs_SOURCE_DIR}/include
        ${SysCallLibs_SOURCE_DIR})

add_executable(RunBasicTest
        framebuffer_tests.cpp
        mmap_tests.cpp mother.cpp color_tests.cpp draw_tests.cpp)

target_link_libraries(RunBasicTest SysCallLibs gtest gtest_main)

add_test(NAME RunBasicTest
        COMMAND RunBasicTest)