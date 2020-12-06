cmake_minimum_required( VERSION 3.0 )
project(Lab5)
include_directories( ./include ./src )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/matrix.cpp)