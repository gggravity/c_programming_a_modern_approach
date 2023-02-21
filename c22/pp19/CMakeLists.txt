cmake_minimum_required(VERSION 3.20)
project(pp19 C)

set(CMAKE_C_STANDARD 11)

add_executable(dos2unix dos2unix.c)

add_executable(unix2dos unix2dos.c)
