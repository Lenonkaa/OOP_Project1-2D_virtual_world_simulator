//
// Created by lenai on 4/19/2026.
//

#include "Human.h"

#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4
#define ABILITY_DURATION 5
#define ABILITY_COOLDOWN 5

Human::Human(World* world, Point position)
    : Animal(world, position, HUMAN_STRENGTH, HUMAN_INITIATIVE) {
    this->isAbilityActive = false;
    this->abilityCooldown = 0;
    this->abilityDuration = ABILITY_DURATION;
    this->wantsToActivateAbility = false;
}

char Human::draw() {
    return 'H';
}

void Human::setMove(World::MOVE move) {
    this->currentMove = move;
}

void Human::action() {

    if (isAbilityActive) {
        abilityDuration--;
        if (abilityDuration == 0) {
            isAbilityActive = false;
            abilityCooldown = ABILITY_COOLDOWN;
            world->addMessage("Human purifying ability finished. Wait " + to_string(abilityCooldown) + " turns to use again");
        }
    } else if (abilityCooldown > 0) {
        abilityCooldown--;
    }

    if (wantsToActivateAbility) {
        activateAbility();
        wantsToActivateAbility = false;
    }
    if (currentMove != World::MOVE::STAY) {
        moveNotRandom();
    }

    if (isAbilityActive) {
        purify();
    }


}

void Human::moveNotRandom() {
    Point currentPos = getPosition();
    Point nextPos = currentPos;

    switch (currentMove) {
        case World::UP:    nextPos.y -= 1; break;
        case World::DOWN:  nextPos.y += 1; break;
        case World::LEFT:  nextPos.x -= 1; break;
        case World::RIGHT: nextPos.x += 1; break;
        default: break; // STAY or other
    }
    if (nextPos.isOutGrid(world->getHeight(), world->getWidth())) {
        world->addMessage("Human tried to go out of the world, stays in place");
        return;
    }

    moveYourself(currentPos, nextPos);
}

Animal* Human::createChild(Point pos) {
    return nullptr;
}

void Human::activateAbility() {
    if (!isAbilityActive && abilityCooldown == 0) {
        isAbilityActive = true;
        abilityDuration = ABILITY_DURATION;
        world->addMessage("Human activates purifying, neighbors will be destroyed");
    } else if (isAbilityActive) {
        world->addMessage("Human ability active. Turns left:" + to_string(abilityDuration));
    } else {
        world->addMessage("Human ability is restoring. Turns left: " + to_string(abilityCooldown));
    }
}

bool Human::hasDeflectedAttack(Organism* attacker) {
    if (isAbilityActive) {
        world->addMessage("Human puryfies attacking" + string(1, attacker->draw()));
        attacker->kill();
        return true;
    }
    return false;
}

void Human::purify() const {
    Point p = getPosition();
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            Point checkPos = {p.x + dx, p.y + dy};

            if (!(checkPos == p)
                && !checkPos.isOutGrid(world->getHeight(), world->getWidth())) {

                Organism* occupant = world->getOrganismAtPosition(checkPos);

                if (occupant != nullptr && occupant->getIsAlive()) {
                    world->addMessage("Human kills " + string(1, occupant->draw()) + " by purifying");
                    occupant->kill();
                }
            }
        }
    }
}


void Human::kill() {
    Organism::kill();

    world->setIfHumanAlive(false);

    world->addMessage("Human is dead!");
}

string Human::messageState() const {
    string msg;
    if (this->getIsAlive()) {
        msg = "Human is at (" + to_string(this->getPosition().x) + "," + to_string(this->getPosition().y) + ")";
        if (isAbilityActive) {
            msg += "    Purification is active for " + to_string(abilityDuration) + " turns";
        }
        else {
            msg+= "     Wait "+ to_string(abilityCooldown) + " turns to activate purification";
        }
    }
    else {
        msg = "Human is not alive";
    }
    return msg;
}