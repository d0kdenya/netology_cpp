cmake_minimum_required(VERSION 3.15)
project(ext_array LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(tests
        test_ext_array.cpp
        catch_amalgamated.cpp
)
