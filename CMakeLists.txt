cmake_minimum_required(VERSION 3.30)
project(netology_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(netology_cpp main.cpp
        FigureError.cpp
        FigureError.h
        Figure.cpp
        Figure.h
        Triangle.cpp
        Triangle.h
        RightTriangle.cpp
        RightTriangle.h
        Quadrangle.cpp
        Quadrangle.h
        Rectangle.cpp
        Rectangle.h)
