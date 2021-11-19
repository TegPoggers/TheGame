//
// Created by segalle on 08/11/2021.
//

#include "MovingEntity.h"

namespace entities {
    namespace characters {

        MovingEntity::MovingEntity() :
                Entity(),
                direction(),
                lives(1) {}

        int MovingEntity::getDirection() {
            return direction;
        }

        void MovingEntity::setLives(int life) {
            this->lives = life;
        }

        int MovingEntity::getLives() {
            return lives;
        }

        void MovingEntity::loseLives() {
            lives--;
        }

        void MovingEntity::addSpeed(sf::Vector2f acceleration) {
            speed += acceleration;
        }

        const sf::Vector2f MovingEntity::getSpeed() const {
            return speed;
        }

        void MovingEntity::setSpeed(sf::Vector2f speed) {
            this->speed = speed;
        }
    }
}