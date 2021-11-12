//
// Created by segalle on 08/11/2021.
//

#include "MovingEntity.h"

namespace entities {

    MovingEntity::MovingEntity() :
    Entity(),
    moving(false) {}

    const bool MovingEntity::isMoving() const {
        return moving;
    }

    void MovingEntity::setMoving(bool moving) {
        this->moving = moving;
    }

    void MovingEntity::setDirection(Direction) {
        this->direction = direction;
    }

}