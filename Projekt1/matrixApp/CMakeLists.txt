cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 20)

include_directories(../matrixLib/include)
add_executable(Projekt1 main.cpp)
target_link_libraries(Projekt1 matrixLib)