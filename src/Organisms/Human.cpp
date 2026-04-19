//
// Created by lenai on 4/19/2026.
//

#include "Human.h"

#define HUMAN_STRENGTH 5
#define HUMAN_INITIATIVE 4

Human::Human(World* world, Point position)
    : Animal(world, position, HUMAN_STRENGTH, HUMAN_INITIATIVE) {
    this->isAbilityActive = false;
}

char Human::draw() {
    return 'H';
}

void Human::setMove(World::MOVE move) {
    this->currentMove = move;
}

void Human::action() {

    if (currentMove == World::MOVE::SPECIAL) {
        //activateAbility();
        // Możemy pozwolić graczowi wcisnąć specjalny i jeszcze strzałkę,
        // lub uznać turę za zakończoną - zależnie od preferencji.
    }
    else {
        moveNotRandom();
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

    moveYourself(currentPos, nextPos);
}

Animal* Human::createChild(Point pos) {
    return new Human(this->world, pos);
}