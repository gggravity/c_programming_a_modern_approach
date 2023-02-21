cmake_minimum_required(VERSION 3.20)
project(pp7 C)

set(CMAKE_C_STANDARD 11)

add_executable(compress_file compress_file.c)

add_executable(uncompress_file uncompress_file.c)
