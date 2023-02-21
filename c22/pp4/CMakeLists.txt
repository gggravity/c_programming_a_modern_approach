cmake_minimum_required(VERSION 3.20)
project(pp4 C)

set(CMAKE_C_STANDARD 11)

add_executable(count_chars count_chars.c)
add_executable(count_words count_words.c)
add_executable(count_lines count_lines.c)

