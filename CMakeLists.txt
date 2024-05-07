#
# Copyright (c) 2024 Alesi Mattia s1114418
#
#
cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(1_progetto)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})

include_directories(${PROJECT_SOURCE_DIR})

#include_directories(${PROJECT_SOURCE_DIR}/boards)
#add_subdirectory(${PROJECT_SOURCE_DIR}/boards)



###Add executable and link libraries
#add_executable(app main.cpp foo.cpp)
#target_link_libraries(MyExecutable MyLibrary)

### After compile call 
# >./app
# Hello World!