//
// Created by lenai on 4/14/2026.
//

#ifndef OOP1_ANIMAL_H
#define OOP1_ANIMAL_H


#include "../Organism.h"

class Animal : public Organism {

public:

    Animal(World* world, Point position, int strength, int initiative);

    virtual ~Animal() = default;

    // Wspólne zachowania dla wszystkich zwierząt
    void action() override;    // Ruch na sąsiednie pole
    void collision() override; // Walka lub rozmnażanie

protected:
    // Metody pomocnicze do logiki zwierząt
    virtual void move(Point newPosition);
   // virtual void breed(Organism* partner);
};


#endif //OOP1_ANIMAL_H