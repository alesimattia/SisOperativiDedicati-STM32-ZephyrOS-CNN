#
# Copyright (c) 2024 Alesi Mattia s1114418
#
#
cmake_minimum_required(VERSION 3.20.0)
set(BOARD stm32f429i_disc1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(2_integrazione)
FILE(GLOB app_sources src/*.cpp)
target_sources(app PRIVATE ${app_sources})
include_directories(${PROJECT_SOURCE_DIR})


set(NO_THREADSAFE_STATICS $<TARGET_PROPERTY:compiler-cpp,no_threadsafe_statics>)
zephyr_compile_options($<$<COMPILE_LANGUAGE:CXX>:${NO_THREADSAFE_STATICS}>)

set (CMAKE_CXX_fLAGS "${CMAKE_CXX_FLAGS} -DCMAKE_PREFIX_PATH=${PROJECT_SOURCE_DIR}/TF_C_API/lib/libtensorflow.so")

zephyr_include_directories(cppflow)
zephyr_include_directories(TF_C_API/include/tensorflow/c)
zephyr_include_directories(TF_C_API/include/tensorflow/core/platform)


#FILE(GLOB includes STemWin/*)
#include_directories(${includes})

#FILE(GLOB includes Core/*)
#include_directories(${includes})

#FILE(GLOB includes Middlewares/ST/STemWin/*)
#include_directories(${includes})

#FILE(GLOB includes Drivers/BSP/*)
#include_directories(${includes})

### -------------------------- TF_C_API dependencies --------------------------- ###
target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/TF_C_API/include/tensorflow/c/")
target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/TF_C_API/include/tensorflow/c/eager/")
target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/TF_C_API/include/tensorflow/core/platform/")
target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/TF_C_API/include/tsl/c")
target_include_directories(app PUBLIC "${PROJECT_SOURCE_DIR}/TF_C_API/include/tsl/platform/")


add_library(TF_C_API STATIC IMPORTED)
set_property(TARGET TF_C_API PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/TF_C_API/lib/libtensorflow.so")
set_property(TARGET TF_C_API PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/TF_C_API/lib/libtensorflow_framework.so")

### -------------------------- CPP_Flow dependencies --------------------------- ###
FILE(GLOB includes cppflow/*.h)
include_directories(${includes})
target_include_directories(app PRIVATE cppflow)

### ------------------------ From Zephyr external lib documentation ------------- ###

# The external static library that we are linking with does not know
# how to build for this platform so we export all the flags used in
# this zephyr build to the external build system.
#
# Other external build systems may be self-contained enough that they
# do not need any build information from zephyr. Or they may be
# incompatible with certain zephyr options and need them to be
# filtered out.
zephyr_get_include_directories_for_lang_as_string(       C includes)
zephyr_get_system_include_directories_for_lang_as_string(C system_includes)
zephyr_get_compile_definitions_for_lang_as_string(       C definitions)
zephyr_get_compile_options_for_lang_as_string(           C options)


###--------------------------------------------------------------------------------###

### Una delle due
#target_link_libraries(${PROJECT_NAME} PUBLIC STemWin)
#target_link_libraries(${PROJECT_SOURCE_DIR} PUBLIC STemWin)


###Add executable and link libraries
#add_executable(app main.cpp foo.cpp)
#target_link_libraries(MyExecutable MyLibrary)

#### After compile call ####
# >./app
# Hello World!