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

    void updateAbility();
    void activateAbility();
    void purify() const;

public:
    Human(World* world, Point position);
    ~Human() override = default;
    void action() override;
    char draw() override;
    string messageState() const;


    void setMove(World::MOVE move);
    void setWantsToActivateAbility(bool val) { wantsToActivateAbility = val; }
    OrganismType getType() const override { return OrganismType::HUMAN; }

    //used by others
    void kill() override;
    bool hasDeflectedAttack(Organism* attacker);


    //for saving
    bool getIsAbilityActive() const { return isAbilityActive; }
    int getAbilityDuration() const { return abilityDuration; }
    int getAbilityCooldown() const { return abilityCooldown; }

    //for loading
    void setAbilityState(bool active, int duration, int cooldown);

};


#endif //OOP1_HUMAN_H