Project(Test_project CXX C)

include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        ${SysCallLibs_SOURCE_DIR}/include
        ${SysCallLibs_SOURCE_DIR})

add_executable(${PROJECT_NAME}
        framebuffer_tests.cpp
        mmap_tests.cpp)

target_link_libraries(${PROJECT_NAME} SysCallLibs gtest gtest_main)

add_test(NAME ${PROJECT_NAME}
        COMMAND RunBasicTest)

add_subdirectory(lib/googletest)