cmake_minimum_required(VERSION 3.20.0)

set(BOARD stm32f429i_disc1)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(1_progetto)

# These samples use local static initialization. Since Zephyr doesn't support the
# C++ ABI for thread-safe initialization of local statics and the constructors don't
# appear to require thread safety, we turn it off in the C++ compiler.
set(NO_THREADSAFE_STATICS $<TARGET_PROPERTY:compiler-cpp,no_threadsafe_statics>)
zephyr_compile_options($<$<COMPILE_LANGUAGE:CXX>:${NO_THREADSAFE_STATICS}>)


FILE(GLOB_RECURSE app_sources src/*.cpp src/*.c src/*.h examples/hello_world/*.cpp examples/hello_world/*.c)
target_sources(app PRIVATE ${app_sources})
include_directories(${PROJECT_SOURCE_DIR})

set(DIR_TFLMICRO "src")
add_subdirectory(${DIR_TFLMICRO})
add_subdirectory(examples/hello_world)

#file(GLOB app_sources src/*)
#target_sources(app PRIVATE ${app_sources})