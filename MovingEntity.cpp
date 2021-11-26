//
// Created by segalle on 08/11/2021.
//

#include "MovingEntity.h"

namespace entities {
    namespace characters {

        MovingEntity::MovingEntity() :
        Entity(),
        lives(1),
        fire(nullptr),
        health(100){}

        MovingEntity::~MovingEntity() {}

        void MovingEntity::setLives(int life) {
            this->lives = life;
        }

        int MovingEntity::getLives() {
            return lives;
        }

        void MovingEntity::loseLives() {
            lives--;
        }

        void MovingEntity::takeDamage(int dmg) {
            health -= dmg;
        }

        int MovingEntity::getHealth() {
            return health;
        }
    }
}