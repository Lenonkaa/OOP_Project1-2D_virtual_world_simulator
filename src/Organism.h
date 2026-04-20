//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_ORGANISM_H
#define OOP1_ORGANISM_H

#include "Point.h"
#include "World.h"
#define CYBER_SHEEP_SYMBOL 'C'
#define HOGWEED_SYMBOL 'h'

enum class OrganismType {
    HUMAN,
    ANIMAL,
    PLANT
};

class World;

class Organism {
private:
    int strength;
    int initiative;
    Point position;
    int age;
    bool isAlive;
    World* world;


protected:

    World* getWorld() const { return world; }

    virtual void collision(Organism* other) = 0;

    void changePosition(Point newPos);
    bool isSameSpecies(Organism* other);



public:

    Organism(World* world, Point position, int strength, int initiative);
    virtual ~Organism() = default;


    virtual void action() = 0;
    virtual char draw() = 0;

    //getters and setters
    Point getPosition() const { return position;}
    int getInitiative() const { return initiative; }
    int getAge() const { return age; }
    bool getIsAlive() const { return isAlive; }
    int getStrength() const { return strength; }

    void incrementAge() { age++; }

    //for loading
    void setStrength(int newStrength) { strength = newStrength; }
    void setAge(int newAge) { age = newAge; }

    //used on other organisms
    virtual bool hasDeflectedAttack(Organism* attacker) { return false; } //domyslne nieodbijanie
    virtual OrganismType getType() const = 0;

    virtual void kill();
    void strengthBoost(int boost);


};
#endif //OOP1_ORGANISM_H