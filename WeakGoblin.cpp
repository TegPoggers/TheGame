//
// Created by segalle on 11/21/21.
//

#include "WeakGoblin.h"

namespace entities{
    namespace characters{

        WeakGoblin::WeakGoblin() : Enemy(),
        attack_counter(0){}

        WeakGoblin::~WeakGoblin() {}

        void WeakGoblin::attack() {

            p_position = player->getPosition();
            fire = new Projectile();
            fire->setDamage(damage);
            fire->setPosition(position.x + 140, position.y + 130);

            if (position.x - 240 > p_position.x){
                fire->setDirection(-1);
            }
            else{
                fire->setDirection(1);
            }
        }

        void WeakGoblin::run() {
            if(attack_counter >= attack_speed) {
                attack();
                attack_counter = 0;
            }
            attack_counter++;
        }

        int WeakGoblin::attack_speed = 288;
        int WeakGoblin::damage = 5;

    }
}