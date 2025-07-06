cmake_minimum_required(VERSION 3.31)
project(Pressy C)

set(CMAKE_C_STANDARD 11)

add_executable(Pressy src/main.c
        src/huffman.c
        src/minheap.c
        src/fileutils.c
        src/pressy.c)
