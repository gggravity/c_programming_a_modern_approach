cmake_minimum_required(VERSION 3.20)
project(e C)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")


set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99 -Wall -pedantic")
#set(CMAKE_C_STANDARD 11)

add_executable(e main.c)
