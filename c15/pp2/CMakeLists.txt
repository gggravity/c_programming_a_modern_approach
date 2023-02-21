cmake_minimum_required(VERSION 3.20)
project(pp1 C)

set(CMAKE_C_STANDARD 11)

add_executable(pp1 main.c word.c word.h line.c line.h)
