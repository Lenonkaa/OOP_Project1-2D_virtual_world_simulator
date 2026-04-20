//
// Created by lenai on 4/19/2026.
//

#ifndef OOP1_HUMAN_H
#define OOP1_HUMAN_H
#include "Animal.h"

class Animal;

class Human: public Animal {
private:
    bool isAbilityActive;
    bool wantsToActivateAbility;
    int abilityDuration;
    int abilityCooldown;
    World::MOVE currentMove;

    Animal* createChild(Point pos);

    void moveNotRandom();
    void purify() const;

    void activateAbility();

public:
    Human(World* world, Point position);
    ~Human() override = default;
    void action() override;
    char draw() override;

    void setMove(World::MOVE move);
    bool hasDeflectedAttack(Organism* attacker);
    void setWantsToActivateAbility(bool val) { wantsToActivateAbility = val; }
    OrganismType getType() const override { return OrganismType::HUMAN; }
    void kill() override;
    string messageState() const;

};


#endif //OOP1_HUMAN_H