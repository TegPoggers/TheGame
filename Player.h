//
// Created by segalle on 11/7/21.
//

#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "MovingEntity.h"
//#include "Level.h"
#include "Star.h"

namespace levels{
    class Level;
}

namespace entities{
    namespace characters {
        class Player : public MovingEntity {

        private:
            static float moving_speed;//1.5 é um bom número pra 144 fps
            static float jump_speed;
            InputManager *inputs;
            int points;
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

            void score(int points);

            int getCollisionDamage();

            Entity* getProjectile();

            void setMapping(Actions actions);

            void operator++();

        };
    }
}

#endif //JOGO_PLAYER_H

