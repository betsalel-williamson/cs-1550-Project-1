cmake_minimum_required(VERSION 2.8)

add_subdirectory(lib)
add_subdirectory(test)

project(Main)

include_directories(${lib_SOURCE_DIR}/include
        ${lib_SOURCE_DIR})

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} Project_1_lib)


