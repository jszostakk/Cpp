cmake_minimum_required(VERSION 3.16)
project(zestaw3)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(zestaw3
        src/main.cpp
        src/Punkt.cpp
        src/Figura.cpp)