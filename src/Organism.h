//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_ORGANISM_H
#define OOP1_ORGANISM_H

#include "Point.h"
#include "World.h"
#define CYBER_SHEEP_SYMBOL 'C'
#define HOGWEED_SYMBOL 'h'

class World;

class Organism {
private:
    int strength;
    int initiative;
    Point position;
    int age;
    bool isAlive;

protected:
    World* world;


public:

    Organism(World* world, Point position, int strength, int initiative);

    virtual ~Organism() = default;


    virtual void action() = 0;
    virtual void collision(Organism* other) = 0;
    virtual char draw() = 0;

    //getters and setters
    Point getPosition() const { return position;}
    int getInitiative() const { return initiative; }
    int getAge() const { return age; }
    bool getIsAlive() const { return isAlive; }
    int getStrength() const { return strength; }

    void changePosition(Point newPos);
    void incrementAge() { age++; }
    void strengthBoost(int boost);

    virtual bool hasDeflectedAttack(Organism* attacker) { return false; } //domyslne nieodbijanie
    bool isSameSpecies(Organism* other) { return this->draw() == other->draw(); }
    virtual bool isAnimal() { return false; }
    void kill() { isAlive = false; }
};
#endif //OOP1_ORGANISM_H