cmake_minimum_required(VERSION 4.1)
project(OOP1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(OOP1 src/main.cpp
        src/World.cpp
        src/World.h
        src/Organism.cpp
        src/Organism.h
        src/Point.h
        src/Organisms/Animal.cpp
        src/Organisms/Animal.h
        src/Organisms/Animals/Wolf.cpp
        src/Organisms/Animals/Wolf.h
        src/Organisms/Plants/Grass.cpp
        src/Organisms/Plants/Grass.h
        src/Organisms/Plant.cpp
        src/Organisms/Plant.h
        src/Organisms/Animals/Sheep.cpp
        src/Organisms/Animals/Sheep.h
        src/Organisms/Human.cpp
        src/Organisms/Human.h)
