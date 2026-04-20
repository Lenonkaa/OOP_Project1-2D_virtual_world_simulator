//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_CYBERSHEEP_H
#define OOP1_CYBERSHEEP_H


#include "../Animal.h"

class CyberSheep : public Animal {
public:

    CyberSheep(World* world, Point position);

    ~CyberSheep() override = default;

    char draw() override;

    void action() override;

protected:
    Animal* createChild(Point pos) override;

private:
    bool isHogweedOnGrid;
    Point findClosestHogweed();
    void goTowardsHogweed(Point closestHogweedPos);

};


#endif //OOP1_CYBERSHEEP_H