cmake_minimum_required(VERSION 3.16)
project(zestaw1)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(zestaw1
        src/main.cpp
        src/Pojazd.cpp)