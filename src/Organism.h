//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_ORGANISM_H
#define OOP1_ORGANISM_H

#include "Point.h"

class World;

class Organism {
private:
    int strength;
    int initiative;
    Point position;
    int age;

protected:
    World* world;

public:

    Organism(World* world, Point position, int strength, int initiative);

    virtual ~Organism() = default;


    virtual void action() = 0;
    virtual void collision() = 0;
    virtual char draw() = 0;

    //getters and setters
    Point getPosition() const { return position;}
    int getInitiative() const { return initiative; }
    int getAge() const { return age; }

    void setPosition(Point p) { position.x = p.x; position.y= p.y; }
    void incrementAge() { age++; }
};
#endif //OOP1_ORGANISM_H