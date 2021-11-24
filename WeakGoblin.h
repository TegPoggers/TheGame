//
// Created by segalle on 11/21/21.
//

#ifndef JOGO_WEAKGOBLIN_H
#define JOGO_WEAKGOBLIN_H

#include "Enemy.h"

namespace entities {
    namespace characters {

        class WeakGoblin : public Enemy{

        private:

            int attack_counter;
            static int attack_speed;
            static int damage;

        public:

            WeakGoblin();

            ~WeakGoblin();

            void attack();

            void run();

            int getCollisionDamage();

        };

    }
}
#endif //JOGO_WEAKGOBLIN_H
