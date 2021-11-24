//
// Created by segalle on 11/22/21.
//

#include "StrongGoblin.h"

namespace entities{
    namespace characters{

        StrongGoblin::StrongGoblin() : Enemy(),
        attack_counter(0){
            assets->LoadSprite(STRONG_GOBLIN, "strongGoblin");
            assets->LoadSprite(GENERAL_GOBLIN_ORB, "strongGoblinOrb");
        }

        StrongGoblin::~StrongGoblin(){}

        void StrongGoblin::run() {
            walk();
            attack_counter++;
        }

        void StrongGoblin::walk() {
            p_position = player->getPosition();
            if(p_position.x + 50 > position.x){
                position.x += walk_speed;
            }
            else{
                position.x -= walk_speed;
            }
        }

        int StrongGoblin::getCollisionDamage() {
            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

            return 0;

        }

        void StrongGoblin::attack() {

        }

        int StrongGoblin::attack_speed = 72;
        int StrongGoblin::collision_damage = 10;
        float StrongGoblin::walk_speed = 0.7;

    }
}