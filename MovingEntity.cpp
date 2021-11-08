//
// Created by segalle on 08/11/2021.
//

#include "MovingEntity.h"

MovingEntity::MovingEntity() : Entity(),
moving(false){}

const bool MovingEntity::isMoving() const {
    return moving;
}

void MovingEntity::setMoving(bool moving) {
    this->moving = moving;
}