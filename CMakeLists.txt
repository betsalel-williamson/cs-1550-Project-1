cmake_minimum_required(VERSION 2.8)

include_directories(".")

add_subdirectory(lib)
add_subdirectory(test)
add_subdirectory(test/lib/googletest)

project(Main)

include_directories(${SysCallLibs_SOURCE_DIR}/include
        ${SysCallLibs_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} SysCallLibs)


