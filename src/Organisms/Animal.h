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

    // Wspólne zachowania dla wszystkich zwierząt
    virtual void action() override;    // Ruch na sąsiednie pole
    virtual void collision(Organism* other) override; // Walka lub rozmnażanie

protected:
    void moveYourself(Point currentPos, Point nextPos);
    void moveRandom();
    virtual Animal* createChild(Point pos) = 0;
};


#endif //OOP1_ANIMAL_H