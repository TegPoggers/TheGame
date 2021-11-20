//
// Created by segalle on 11/7/21.
//

#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "MovingEntity.h"
#include "Projectile.h"
//#include "Level.h"

namespace entities{
    namespace characters {
        class Player : public MovingEntity {

        private:
            static float moving_speed;//1.5 é um bom número pra 144 fps
            static float jump_speed;
            static float gravity;
            InputManager *inputs;
            int health;
            sf::Vector2f speed;
            bool ground;
            int points;
            //Level* level;

        public:

            Player();

            ~Player();

            void setGround(bool on_ground);

            void jump();

            void run();

            void attack();

            void score(int points);

        };
    }
}

#endif //JOGO_PLAYER_H

