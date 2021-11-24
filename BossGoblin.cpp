//
// Created by segalle on 11/23/21.
//

#include "BossGoblin.h"

namespace entities{
    namespace characters{

        BossGoblin::BossGoblin() : Enemy(),
        attack_counter(0){
            assets->LoadSprite(BOSS_GOBLIN, "bossGoblin");
            assets->LoadSprite(BOSS_GOBLIN_ORB, "bossGoblinOrb");
        }

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
            walk();
        }

        void BossGoblin::walk(){
            p_position = player->getPosition();
            if(p_position.x + 50 > position.x){//Esse + 50 vai mudar em função do tamanho do boss (talvez não pois não se pode andar no boss)
                position.x += walk_speed;
            }
            else{
                position.x -= walk_speed;
            }
        }

        int BossGoblin::getCollisionDamage() {

            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

        }

        int BossGoblin::projectile_damage = 40;
        int BossGoblin::collision_damage = 70;
        int BossGoblin::attack_speed = 976;
        float BossGoblin::walk_speed = 0.5;

    }
}