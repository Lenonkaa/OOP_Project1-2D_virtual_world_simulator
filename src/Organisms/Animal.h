//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_ANIMAL_H
#define OOP1_ANIMAL_H


#include "../Organism.h"



class Animal : public Organism {
private:
    void bread(Organism* other);
    void strongerWins(Organism* other);


public:

    Animal(World* world, Point position, int strength, int initiative);

    virtual ~Animal() = default;


    virtual void action() override;
    virtual void collision(Organism* other) override;

    OrganismType getType() const override { return OrganismType::ANIMAL; }

protected:
    void moveYourself(Point currentPos, Point nextPos);
    virtual Animal* createChild(Point pos) = 0;

    void moveRandom();

};


#endif //OOP1_ANIMAL_H