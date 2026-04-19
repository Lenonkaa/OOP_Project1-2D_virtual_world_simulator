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
    this->move();
}

void Animal::collision() {
    world->addMessage("animal collision");
}

void Animal::move() {
    Point currentPos = getPosition();
    Point nextPos = world->getRandomNeighbor(currentPos);

    if (nextPos == currentPos) return;


    Organism* other = world->getOrganismAtPosition(nextPos);

    if (other == nullptr) {
        // cell is free
        this->changePosition(nextPos);
        world->addMessage(string(1, draw()) + " moved to (" + to_string(nextPos.x) + "," + to_string(nextPos.y) + ")");
    } else {
        //cell is occupied
        //przekazać 'other' do metody collision
        this->collision();
    }
}


