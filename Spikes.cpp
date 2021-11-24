//
// Created by segalle on 11/23/21.
//

#include "Spikes.h"

namespace entities{
    namespace obstacles{

        Spikes::Spikes() :
        attack_counter(0){}

        Spikes::~Spikes() {}

        void Spikes::run() {
            attack_counter++;
        }

        int Spikes::getCollisionDamage() {
            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

            return 0;

        }

        int Spikes::collision_damage = 10;
        int Spikes::attack_speed = 144;

    }
}