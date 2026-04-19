//
// Created by lenai on 4/19/2026.
//

#include "CyberSheep.h"



#define CYBERSHEEP_STRENGTH 2
#define CYBERSHEEP_INITIATIVE 1
#define PROBABILITY_MOVE 0.25
#define CYBERSHEEP_DEFLECTION 5



CyberSheep::CyberSheep(World* world, Point position)
    : Animal(world, position, CYBERSHEEP_STRENGTH, CYBERSHEEP_INITIATIVE) {}

char CyberSheep::draw() {
    return CYBER_SHEEP_SYMBOL;
}

Animal* CyberSheep::createChild(Point pos) {
    return new CyberSheep(this->world, pos);
}

void CyberSheep::action() {

    Point currentPos = getPosition();
    Point nextPos = currentPos;
    isHogweed = false;

    Point closestHogweedPos = findClosestHogweed();

    if (isHogweed) {
        string msg = "CyberSheep found Hogweed - moving towards it";
        world->addMessage(msg);

        if (closestHogweedPos.x > currentPos.x) nextPos.x += 1;
        else if (closestHogweedPos.x < currentPos.x) nextPos.x -= 1;

        if (closestHogweedPos.y > currentPos.y) nextPos.y += 1;
        else if (closestHogweedPos.y < currentPos.y) nextPos.y -= 1;
    }

    moveYourself(currentPos, nextPos);
}


Point CyberSheep::findClosestHogweed() {

    Point currentPos = getPosition();

    Point closestHogweedPos = {-1,-1};//nonexistent place
    int minDistance = 999;

    for (int y = 0; y < world->getHeight(); ++y) {
        for (int x = 0; x < world->getWidth(); ++x) {

            Point p = {x, y};
            Organism* org = world->getOrganismAtPosition(p);

            if (org != nullptr && org->draw()==HOGWEED_SYMBOL) {
                isHogweed = true;
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

