//
// Created by segalle on 11/23/21.
//

#ifndef JOGO_BOSSGOBLIN_H
#define JOGO_BOSSGOBLIN_H

#include "Enemy.h"
#include "EnergyOrb.h"

namespace entities {

    namespace characters {
        class BossGoblin : public Enemy {

        private:

            int attack_counter;
            static int attack_speed;
            static int projectile_damage;
            static int collision_damage;
            static float walk_speed;
            float jump_counter;
            static float jump_speed;
            static float jump_height;

        public:

            BossGoblin();

            ~BossGoblin();

            void attack();

            void run();

            void walk();

            int getCollisionDamage();

            Entity* getProjectile();

            void jump();

        };
    }
}


#endif //JOGO_BOSSGOBLIN_H
