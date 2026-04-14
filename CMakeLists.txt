cmake_minimum_required(VERSION 4.1)
project(OOP1)

set(CMAKE_CXX_STANDARD 20)

add_executable(OOP1 src/main.cpp
        src/World.cpp
        src/World.h
        src/Organism.cpp
        src/Organism.h
        src/Point.h
        src/Organisms/Animal.cpp
        src/Organisms/Animal.h
        src/Organisms/Animals/Wolf.cpp
        src/Organisms/Animals/Wolf.h)
