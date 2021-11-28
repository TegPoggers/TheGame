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
        health(100),
        speed(0, 0),
        ground(false){}

        MovingEntity::~MovingEntity() {}


        void MovingEntity::takeDamage(int dmg) {
            health -= dmg;
        }

        const int MovingEntity::getHealth() {
            return health;
        }

        void MovingEntity::fall() {
            if(ground){
                speed.y = 0;
            }
            else{
                speed.y += gravity;
            }
            //position.y += speed.y;
        }

        void MovingEntity::setGround(bool on_ground) {
            ground = on_ground;
            if (ground) {
                speed.y = 0;
            }
        }

        void MovingEntity::setFallSpeed(float speed) {
            this->speed.y = speed;
        }

        float MovingEntity::gravity = 0.2;

    }

}