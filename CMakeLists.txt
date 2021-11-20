cmake_minimum_required(VERSION 3.10)
project(libjson C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")
if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")
endif ()

add_executable(libjson tests/tests.c json.h json.c lib.h)