//
// Created by segalle on 11/22/21.
//

#ifndef JOGO_STRONGGOBLIN_H
#define JOGO_STRONGGOBLIN_H

#include "Enemy.h"

namespace entities {
    namespace characters {
        class StrongGoblin : public Enemy {

        private:

            int attack_counter;
            static int attack_speed;
            static int damage;
            static float walk_speed;

        public:

            StrongGoblin();

            ~StrongGoblin();

            void attack();

            void run();

            void walk();

        };
    }
}
#endif //JOGO_STRONGGOBLIN_H
