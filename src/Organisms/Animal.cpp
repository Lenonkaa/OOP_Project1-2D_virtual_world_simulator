//
// Created by lenai on 4/14/2026.
//


#include "Animal.h"
#include "../World.h"

#include <cstdlib> // dla rand()
#include <iostream>
#include <ostream>

Animal::Animal(World* world, Point position, int strength, int initiative)
    : Organism(world, position, strength, initiative)
{

}



void Animal::action() {
    std::cout << "Animal::action()" << std::endl;
}

void Animal::collision() {
    std::cout << "Animal::collision()" << std::endl;
}

void Animal::move(Point newPosition) {
    std::cout << "Animal::move()" << std::endl;
}


