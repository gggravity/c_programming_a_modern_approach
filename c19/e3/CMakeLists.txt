cmake_minimum_required(VERSION 3.20)
project(e3 C)

set(CMAKE_C_STANDARD 11)

add_executable(e3 main.c queue.c queue.h)
