cmake_minimum_required( VERSION 3.0 )
project(Lab5)
include_directories( include src libs)
add_executable(${PROJECT_NAME} src/main.cpp src/matrix.cpp libs/sqlite3/sqlite3.c src/database.cpp )