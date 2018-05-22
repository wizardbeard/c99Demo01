cmake_minimum_required(VERSION 3.10)
project(c99Demo01 C)

set(CMAKE_C_STANDARD 99)

file(GLOB_RECURSE SOURCES src/*.c)

# The package name - "user" - corresponds tp the path: ./src/pkg/user found in the above call to file(GLOB_RECURSE ...)
add_library("user" STATIC ${SOURCES})

add_executable(c99Demo01 src/main.c)