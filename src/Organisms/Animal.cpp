//
// Created by lenai on 4/14/2026.
//


#include "Animal.h"
#include "../World.h"

#include <iostream>

Animal::Animal(World* world, Point position, int strength, int initiative)
    : Organism(world, position, strength, initiative){}


void Animal::action() {
    this->moveRandom();
}

void Animal::collision(Organism* other) {
    if (this->isSameSpecies(other)) {
        getWorld()->addMessage("Breading " + string(1, this->draw()) +" species");
        bread(other);
        return;
    }

    if (other->hasDeflectedAttack(this)) return;

    strongerWins(other);

}


void Animal::moveYourself(Point currentPos, Point nextPos) {

    if (nextPos == currentPos) return;

    Organism* other = getWorld()->getOrganismAtPosition(nextPos);

    if (other == nullptr) {
        // cell is free
        this->changePosition(nextPos);
        getWorld()->addMessage(string(1, draw()) + " moved to (" + to_string(nextPos.x) + "," + to_string(nextPos.y) + ")");
    } else{
        this->collision(other);
    }
}

//======================== ONLY FOR ANIMALS - PRIVATE ===============

void Animal::strongerWins(Organism* other) {

    if (this->getStrength() >= other->getStrength()) {

        getWorld()->addMessage(string(1, this->draw()) +" (" + to_string(getPosition().x) + "," + to_string(getPosition().y)
                + ") kills " + string(1, other->draw()) +" (" + to_string(other->getPosition().x) + "," + to_string(other->getPosition().y) + ")");

        other->kill();

        this->changePosition(other->getPosition());
    }
    else {

        getWorld()->addMessage(string(1, other->draw()) + " (" + to_string(other->getPosition().x) + "," + to_string(other->getPosition().y)
            + ") defends itself and kills " + string(1, this->draw())
            +" (" + to_string(getPosition().x) + "," + to_string(getPosition().y) + ")");

        this->kill();
    }
}

void Animal::bread(Organism* other) {

    Point freeSpot = getWorld()->getRandomFreeNeighbor(this->getPosition());

    if (freeSpot == this->getPosition()) { //if no free spot around attacker - looking around other
        freeSpot = getWorld()->getRandomFreeNeighbor(other->getPosition());
    }

    if (!(freeSpot == this->getPosition()) && !(freeSpot == other->getPosition())) {
        Animal* child = this->createChild(freeSpot);
        getWorld()->addOrganism(child);

        getWorld()->addMessage("Breading - new " + string(1, this->draw()) + " born at (" + to_string(freeSpot.x) + "," + to_string(freeSpot.y) + ")");
    }
    else {
        getWorld()->addMessage("No more place for " + string(1, this->draw()) + " to bread!");
    }
}


void Animal::moveRandom() {
    Point currentPos = getPosition();
    Point nextPos = getWorld()->getRandomNeighbor(currentPos);
    moveYourself(currentPos,nextPos);

}





