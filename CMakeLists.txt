cmake_minimum_required(VERSION 3.15)

project(my_first_cmake_project LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_first_cmake_program
        main.cpp
)

if (WIN32)
    add_definitions(-DUNICODE -D_UNICODE)
endif()
