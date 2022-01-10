cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 20)
project(Projekt2)
include_directories(../include)
add_executable(Projekt2 main.cpp
        Entity.cpp
        Enemy.cpp
        Hero.cpp
        lib.cpp)