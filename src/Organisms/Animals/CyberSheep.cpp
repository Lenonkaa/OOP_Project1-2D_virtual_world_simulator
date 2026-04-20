//
// Created by lenai on 4/19/2026.
//

#include "CyberSheep.h"
#include "../Plants/SosnowskyHogweed.h"



#define CYBERSHEEP_STRENGTH 11
#define CYBERSHEEP_INITIATIVE 4



CyberSheep::CyberSheep(World* world, Point position)
    : Animal(world, position, CYBERSHEEP_STRENGTH, CYBERSHEEP_INITIATIVE) {}

char CyberSheep::draw() {
    return CYBER_SHEEP_SYMBOL;
}

Animal* CyberSheep::createChild(Point pos) {
    return new CyberSheep(this->getWorld(), pos);
}


// ===================== CYBERSHEEP SPECIAL =======================


void CyberSheep::action() {


    isHogweedOnGrid = false;

    Point closestHogweedPos = findClosestHogweed();

    if (isHogweedOnGrid) {
        goTowardsHogweed(closestHogweedPos);

    }
    else {
        moveRandom();
    }

}


Point CyberSheep::findClosestHogweed() {

    Point currentPos = getPosition();

    Point closestHogweedPos = {-1,-1};//nonexistent place
    int minDistance = 999; //max world size is 500

    for (int y = 0; y < getWorld()->getHeight(); ++y) {
        for (int x = 0; x < getWorld()->getWidth(); ++x) {

            Point p = {x, y};
            Organism* org = getWorld()->getOrganismAtPosition(p);

            if (org != nullptr && typeid(*org) == typeid(SosnowskyHogweed)) {
                isHogweedOnGrid = true;
                int dist = max(abs(p.x - currentPos.x), abs(p.y - currentPos.y));//bo chodzimy tez po skosie

                if (dist < minDistance) {
                    minDistance = dist;
                    closestHogweedPos = p;
                }
            }
        }
    }

    return closestHogweedPos;

}


void CyberSheep::goTowardsHogweed(Point closestHogweedPos){

    Point currentPos = getPosition();
    Point nextPos = currentPos;

    string msg = "CyberSheep found Hogweed - moving towards it";
    getWorld()->addMessage(msg);

    if (closestHogweedPos.x > currentPos.x) nextPos.x += 1;
    else if (closestHogweedPos.x < currentPos.x) nextPos.x -= 1;

    if (closestHogweedPos.y > currentPos.y) nextPos.y += 1;
    else if (closestHogweedPos.y < currentPos.y) nextPos.y -= 1;

    moveYourself(currentPos, nextPos);

}