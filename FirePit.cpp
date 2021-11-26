//
// Created by segalle on 11/23/21.
//

#include "FirePit.h"

namespace entities{
    namespace obstacles{

        FirePit::FirePit() :
        attack_counter(0){
            sprite = assets->getSprite("firePit");
            setId(fire_pit_id);
        }

        FirePit::~FirePit() {}

        void FirePit::run() {}

        int FirePit::getCollisionDamage() {
            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

            return 0;

        }

        int FirePit::attack_speed = 28;
        int FirePit::collision_damage = 1;

    }
}