//
// Created by segalle on 11/23/21.
//

#include "BossGoblin.h"

namespace entities{
    namespace characters{

        BossGoblin::BossGoblin() : Enemy(),
        attack_counter(0){}

        BossGoblin::~BossGoblin() {}

        void BossGoblin::attack() {
            p_position = player->getPosition();
            fire = new Projectile();
            fire->setDamage(projectile_damage);
            fire->setPosition(position.x + sprite->getGlobalBounds().width/2 - 20, position.y + sprite->getGlobalBounds().height/2);

            if (position.x> p_position.x){
                fire->setDirection(-1);
            }
            else{
                fire->setDirection(1);
            }
        }

        void BossGoblin::run() {
            if(attack_counter >= attack_speed) {
                attack();
                attack_counter = 0;
            }
            attack_counter++;
        }

        void BossGoblin::walk(){
            p_position = player->getPosition();
            if(p_position.x + 50 > position.x){
                position.x += walk_speed;
            }
            else{
                position.x -= walk_speed;
            }
        }

        int BossGoblin::projectile_damage = 40;
        int BossGoblin::collision_damage = 70;
        int BossGoblin::attack_speed = 976;
        float BossGoblin::walk_speed = 1;

    }
}