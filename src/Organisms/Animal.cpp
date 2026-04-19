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
    this->moveRandom();
}

void Animal::collision(Organism* other) {
    if (this->isSameSpecies(other)) {
        world->addMessage("Breading " + string(1, this->draw()) +" specie");
        //bread()
        // (Tutaj w przyszłości dodasz logikę losowania wolnego pola i dodawania nowego organizmu)
        return;
    }

    if (other->hasDeflectedAttack(this)) return;


    strongerWins(other);

}

void Animal::strongerWins(Organism* other) {
    if (this->getStrength() >= other->getStrength()) {
        world->addMessage(string(1, this->draw()) + " kills " + string(1, other->draw()));
        other->kill();
        this->changePosition(other->getPosition());
    }
    else {
        world->addMessage(string(1, other->draw()) + " defend itself and kills " + string(1, this->draw()));
        this->kill();
    }
}

void Animal::bread(Organism* other) {
    Point freeSpot = world->getRandomFreeNeighbor(this->getPosition());

    if (freeSpot == this->getPosition()) { //if no free spot around attacker
        freeSpot = world->getRandomFreeNeighbor(other->getPosition());
    }

    if (!(freeSpot == this->getPosition()) && !(freeSpot == other->getPosition())) {
        Animal* child = this->createChild(freeSpot);
        world->addOrganism(child);

        world->addMessage("Breading - new " + string(1, this->draw()) + " born at (" + to_string(freeSpot.x) + "," + to_string(freeSpot.y) + ")");
    }
    else {
        world->addMessage("No more place for " + string(1, this->draw()) + " to bread!");
    }
}


void Animal::moveRandom() {
    Point currentPos = getPosition();
    Point nextPos = world->getRandomNeighbor(currentPos);
    moveYourself(currentPos,nextPos);

}

void Animal::moveYourself(Point currentPos, Point nextPos) {

    if (nextPos == currentPos) return;

    Organism* other = world->getOrganismAtPosition(nextPos);



    if (other == nullptr) {
        // cell is free
        this->changePosition(nextPos);
        world->addMessage(string(1, draw()) + " moved to (" + to_string(nextPos.x) + "," + to_string(nextPos.y) + ")");
    } else{
        this->collision(other);
    }
}




