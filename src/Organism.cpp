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
    world->setOrganismAt(this->position, nullptr);

    this->position = newPos;

    world->setOrganismAt(this->position, this);
}

void Organism::strengthBoost(int boost) {
    this->strength += boost;
}
