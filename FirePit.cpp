//
// Created by segalle on 11/23/21.
//

#include "FirePit.h"

namespace entities{
    namespace obstacles{

        FirePit::FirePit() :
        attack_counter(0){}

        FirePit::~FirePit() {}

        void FirePit::run() {}

        int FirePit::getCollisionDamage() {
            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

            return 0;

        }

        int FirePit::attack_speed = 14;
        int FirePit::collision_damage = 1;

    }
}