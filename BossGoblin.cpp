//
// Created by segalle on 11/23/21.
//

#include "BossGoblin.h"

namespace entities{
    namespace characters{

        BossGoblin::BossGoblin() : Enemy(),
        attack_counter(0),
        jump_counter(0){
            sprite = assets->getSprite("bossGoblin");
            setId(boss_goblin_id);
        }

        BossGoblin::~BossGoblin() {}

        void BossGoblin::attack() {
            p_position = player->getPosition();
            fire = new EnergyOrb();
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
            if(jump_counter >= jump_speed) {
                jump();
                jump_counter = 0;
            }
            jump_counter++;
            walk();
        }

        void BossGoblin::walk(){
            p_position = player->getPosition();
            if(p_position.x + 50 > position.x){
                position.x += walk_speed;
            }
            else{
                position.x -= walk_speed;
            }
            fall();
            position.y += speed.y;
        }

        int BossGoblin::getCollisionDamage() {

            if(attack_counter > attack_speed) {

                attack_counter = 0;
                return collision_damage;

            }

            return 0;

        }

        Entity* BossGoblin::getProjectile() {
            Entity* aux = static_cast <Entity*> (fire);
            fire = nullptr;
            return aux;
        }

        void BossGoblin::jump(){
            speed.y = jump_height;
            ground = false;
        }

        int BossGoblin::projectile_damage = 40;
        int BossGoblin::collision_damage = 70;
        int BossGoblin::attack_speed = 976;
        float BossGoblin::walk_speed = 0.35;
        float BossGoblin::jump_speed = 288;
        float BossGoblin::jump_height = -10;

    }
}