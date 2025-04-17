cmake_minimum_required(VERSION 3.30)
project(netology_cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(netology_cpp main.cpp
        Figure.cpp
        Figure.h
        Triangle.cpp
        Triangle.h
        RightTriangle.cpp
        RightTriangle.h
        IsoscelesTriangle.cpp
        IsoscelesTriangle.h
        EquilateralTriangle.cpp
        EquilateralTriangle.h
        Quadrangle.cpp
        Quadrangle.h
        Parallelogram.cpp
        Parallelogram.h
        Rectangle.cpp
        Rectangle.h
        Rhombus.cpp
        Rhombus.h
        Square.cpp
        Square.h)
