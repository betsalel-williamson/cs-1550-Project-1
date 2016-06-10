cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

include_directories(".")

add_subdirectory(lib)
add_subdirectory(test)

project(Main)

include_directories(${SysCallLibs_SOURCE_DIR}/include
        ${SysCallLibs_SOURCE_DIR})

add_executable(Project1_${PROJECT_NAME} main.c)
target_link_libraries(Project1_${PROJECT_NAME} SysCallLibs)

add_executable(Sample_${PROJECT_NAME} square.c library.c library.h iso_font.h)
#target_link_libraries(Sample_${PROJECT_NAME} SysCallLibs)

add_executable(Single_${PROJECT_NAME} main_single.c library.c library.h iso_font.h)



