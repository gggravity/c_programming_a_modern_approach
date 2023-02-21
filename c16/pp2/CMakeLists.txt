cmake_minimum_required(VERSION 3.20)
project(pp2 C)

set(CMAKE_C_STANDARD 11)

add_executable(pp2 main.c readline.c readline.h operations.c operations.h)
