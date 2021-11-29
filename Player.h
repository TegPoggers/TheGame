//
// Created by segalle on 11/7/21.
//

#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "MovingEntity.h"
#include "Star.h"

namespace levels{
    class Level;
}

namespace entities{
    namespace characters {
        class Player : public MovingEntity {

        private:
            static float moving_speed;
            static float jump_speed;
            InputManager *inputs;
            static int points;
            Star* fire;
            int counter;
            bool can_attack;
            Actions actions;

        public:

            Player();

            ~Player();

            void jump();

            void run();

            void attack();

            void attackCounter();

            static void score(int score);

            int getCollisionDamage();

            Entity* getProjectile();

            void setMapping(Actions actions);

            void operator++();

            int getScore();

            virtual void setScore(int value);

        };
    }
}

#endif //JOGO_PLAYER_H

