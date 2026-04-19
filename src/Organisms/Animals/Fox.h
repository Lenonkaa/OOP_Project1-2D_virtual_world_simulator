//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_FOX_H
#define OOP1_FOX_H


#include "../Animal.h"

class Fox : public Animal {
public:

    Fox(World* world, Point position);

    ~Fox() override = default;

    char draw() override;

    Animal* createChild(Point pos) override;
    void action() override;
private:
    vector<Point> getAllSafeNeighbors(Point p, int range=1);
    Point getRandomSafeNeighbor();
    bool isThereSafe( Organism* occupant);
};


#endif //OOP1_FOX_H