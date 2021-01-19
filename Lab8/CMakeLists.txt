cmake_minimum_required( VERSION 3.0 )
project(Lab8)
include_directories( ./include ./src ./tests )

add_executable(${PROJECT_NAME} ./src/main.cpp )
target_link_libraries(${PROJECT_NAME} PUBLIC -pthread)