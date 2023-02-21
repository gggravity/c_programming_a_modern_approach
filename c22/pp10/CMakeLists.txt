cmake_minimum_required(VERSION 3.20)
project(pp10 C)

set(CMAKE_C_STANDARD 11)


add_executable(pp10 main.c readline.c readline.h operations.c operations.h)
