Project(Test_project CXX C)

include_directories(${gtest_SOURCE_DIR}/include
        ${gtest_SOURCE_DIR}
        ${lib_SOURCE_DIR}/include
        ${lib_SOURCE_DIR})

add_executable(${PROJECT_NAME}
        framebuffer_tests.cpp
        mmap_tests.cpp)

target_link_libraries(${PROJECT_NAME} Project_1_lib gtest gtest_main)

add_test(NAME ${PROJECT_NAME}
        COMMAND RunBasicTest)


#project(MyUtilities_Test)
#
#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#
#add_executable(RunBasicTest
#        framebuffer_tests.cpp
#        mmap_tests.cpp)
#
#target_link_libraries(RunBasicTest gtest gtest_main)
#
#add_test(NAME RunBasicTest
#        COMMAND RunBasicTest)