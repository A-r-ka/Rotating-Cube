cmake_minimum_required(VERSION 3.31)
project(RotatingCube)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RotatingCube
        main.cpp
        definitions/CubeSurface.cpp
        definitions/MatrixOperations.cpp
)
