cmake_minimum_required(VERSION 4.0)
project(grafoed)

set(CMAKE_CXX_STANDARD 20)

add_executable(grafoed main.cpp
        vertice.cpp
        vertice.h
        GrafoMatriz.cpp
        GrafoMatriz.h)
