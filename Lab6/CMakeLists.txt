cmake_minimum_required( VERSION 3.0 )
project(Lab6)
include_directories( ./include ./src ./tests )
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/HRMS.cpp ./src/employee.cpp )