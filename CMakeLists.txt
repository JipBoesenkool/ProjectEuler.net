cmake_minimum_required(VERSION 3.1)
project(Euler)

file(GLOB PROJECT_HEADERS src/*.hpp)
file(GLOB PROJECT_SOURCES
    src/main.cpp
    src/problems/*.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} ${PROJECT_HEADERS})
