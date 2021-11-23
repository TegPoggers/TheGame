//
// Created by segalle on 11/22/21.
//

#include "StrongGoblin.h"

namespace entities{
    namespace characters{

        StrongGoblin::StrongGoblin() : Enemy(),
        attack_counter(0){}

        StrongGoblin::~StrongGoblin(){}

        void StrongGoblin::run() {
            attack();
            walk();
        }

        void StrongGoblin::attack() {
            p_position = player->getPosition();
            if(p_position.x < position.x + 150 && p_position.x > position.x - 150 && p_position.y < p_position.x - 100){
                player->takeDamage(damage);
            }
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

        int StrongGoblin::attack_speed = 72;
        int StrongGoblin::damage = 10;
        float StrongGoblin::walk_speed = 0.7;

    }
}