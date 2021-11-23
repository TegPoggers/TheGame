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
            fire->setPosition(position.x + sprite->getGlobalBounds().width/2 - 20, position.y + sprite->getGlobalBounds().height/2);

            if (position.x> p_position.x){
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