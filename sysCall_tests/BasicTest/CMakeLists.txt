include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(RunBasicTest basic_check.cpp)

target_link_libraries(RunBasicTest gtest gtest_main)

add_test(NAME RunBasicTest
        COMMAND RunBasicTest)