//
// Created by lenai on 4/19/2026.
//

#include "Fox.h"



#define FOX_STRENGTH 3
#define FOX_INITIATIVE 7


Fox::Fox(World* world, Point position)
    : Animal(world, position, FOX_STRENGTH, FOX_INITIATIVE) {}

char Fox::draw() {
    return 'F';
}

Animal* Fox::createChild(Point pos) {
    return new Fox(this->world, pos);
}


void Fox::action() {
    Point currentPos = getPosition();

    Point nextPos = getRandomSafeNeighbor();

    moveYourself(currentPos, nextPos);


}


vector<Point> Fox::getAllSafeNeighbors(Point p, int range) {
    vector<Point> safeNeighbors;

    for (int dy = -range; dy <= range; dy++) {
        for (int dx = -range; dx <= range; dx++) {
            Point checkedPoint = {p.x + dx, p.y + dy};

            if (!(checkedPoint == p)
            && !checkedPoint.isOutGrid(world->getHeight(), world->getWidth() )
            && isThereSafe(world->getOrganismAtPosition(checkedPoint))) {
                safeNeighbors.push_back(checkedPoint);
            }
        }
    }

    return safeNeighbors;
}

bool Fox::isThereSafe( Organism* occupant) {
    if (occupant == nullptr || occupant->getStrength() <= this->getStrength()) {
        return true;
    }
    return false;
}

Point Fox::getRandomSafeNeighbor() {

    Point currentPos = getPosition();
    vector<Point> safeNeighbors = getAllSafeNeighbors(currentPos);

    if (safeNeighbors.empty()) {
        return currentPos;
    }

    int index = rand() % safeNeighbors.size();
    return safeNeighbors[index];
}
