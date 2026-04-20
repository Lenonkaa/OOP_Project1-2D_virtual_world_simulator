//
// Created by lenai on 4/14/2026.
//

#include "Organism.h"


Organism::Organism(World* world, Point position, int strength, int initiative):
    position(position),
    strength(strength),
    initiative(initiative),
    age(0)
{
    this->world = world;
    this->isAlive = true;
}

void Organism::changePosition(Point newPos) {
    getWorld()->setOrganismAt(this->position, nullptr);

    this->position = newPos;

    getWorld()->setOrganismAt(this->position, this);
}


//====================== used by others ==============

bool Organism::isSameSpecies(Organism* other) {
    return typeid(*this) == typeid(*other);
}



void Organism::strengthBoost(int boost) {
    this->strength += boost;
}

void Organism::kill() {
    isAlive = false;
}