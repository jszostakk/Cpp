cmake_minimum_required(VERSION 3.16)
project(zestaw2)
set(CMAKE_CXX_STANDARD 20)
include_directories(include)
add_executable(zestaw2
        src/main.cpp
        src/Prostopadloscian.cpp
        src/Kula.cpp
        src/FunkcjaKwadratowa.cpp
        src/Student.cpp
        )