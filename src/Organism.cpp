//
// Created by lenai on 4/14/2026.
//

#include "Organism.h"

Organism::Organism(World* world, Point position, int strength, int initiative):
    position(position),
    strength(strength),
    initiative(initiative)
{
    this->world = world;
}