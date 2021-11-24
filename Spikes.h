//
// Created by segalle on 11/23/21.
//

#ifndef JOGO_SPIKES_H
#define JOGO_SPIKES_H

#include "StaticEntity.h"

namespace entities {
    namespace obstacles {

        class Spikes : public StaticEntity{

        private:

            static int collision_damage;
            static int attack_speed;
            int attack_counter;

        public:

            Spikes();

            ~Spikes();

            void run();

            int getCollisionDamage();

        };

    }
}

#endif //JOGO_SPIKES_H
