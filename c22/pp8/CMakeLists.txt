cmake_minimum_required(VERSION 3.20)
project(pp8 C)

set(CMAKE_C_STANDARD 11)

add_executable(pp8 main.c readline.c readline.h operations.c operations.h)
