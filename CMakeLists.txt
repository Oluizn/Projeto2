cmake_minimum_required(VERSION 3.27)
project(Projeto2 C)

set(CMAKE_C_STANDARD 17)

add_executable(Projeto2 main.c
        libprj.h
        libprj.c)
