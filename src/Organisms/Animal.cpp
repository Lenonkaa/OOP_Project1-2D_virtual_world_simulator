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
    world->addMessage("animal action");
}

void Animal::collision() {
    world->addMessage("animal collision");
}

void Animal::move(Point newPosition) {
    world->addMessage("animal move");
}


