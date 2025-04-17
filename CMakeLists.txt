cmake_minimum_required(VERSION 3.15)
project(figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Папка с заголовками
include_directories(${CMAKE_SOURCE_DIR}/include)

# Список исходников (можно glob, но явный список надёжнее)
add_executable(figures
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
