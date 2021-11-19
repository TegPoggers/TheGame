//
// Created by segalle on 11/7/21.
//

#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "MovingEntity.h"

namespace entities{
    namespace characters {
        class Player : public MovingEntity {

        private:
            static float moving_speed;//1.5 é um bom número pra 144 fps
            static float jump_speed;
            InputManager *inputs;
            int health;
            sf::Vector2f speed;
            bool ground;
            

        public:

            Player();

            ~Player();

            void setGround(bool on_ground);

            void jump();

            void run();

        };
    }
}

#endif //JOGO_PLAYER_H

