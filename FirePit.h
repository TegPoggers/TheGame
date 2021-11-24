//
// Created by segalle on 11/23/21.
//

#ifndef JOGO_FIREPIT_H
#define JOGO_FIREPIT_H

#include "StaticEntity.h"
namespace entities {
    namespace obstacles {

        class FirePit : public StaticEntity{

        private:

            static int collision_damage;
            static int attack_speed;
            int attack_counter;

        public:

            FirePit();

            ~FirePit();

            void run();

            int getCollisionDamage();

        };

    }
}


#endif //JOGO_FIREPIT_H
