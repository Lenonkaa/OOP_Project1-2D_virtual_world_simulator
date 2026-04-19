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
        src/Organisms/Human.h
        src/Organisms/Plants/Sonchus.cpp
        src/Organisms/Plants/Sonchus.h
        src/Organisms/Plants/Guarana.cpp
        src/Organisms/Plants/Guarana.h
        src/Organisms/Plants/Belladonna.cpp
        src/Organisms/Plants/Belladonna.h
        src/Organisms/Plants/SosnowskyHogweed.cpp
        src/Organisms/Plants/SosnowskyHogweed.h
        src/Organisms/Animals/Antelope.cpp
        src/Organisms/Animals/Antelope.h
        src/Organisms/Animals/Fox.cpp
        src/Organisms/Animals/Fox.h)
