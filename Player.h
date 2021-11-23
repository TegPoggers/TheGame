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
#include "Projectile.h"

namespace levels{
    class Level;
}

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
            levels::Level* level;
            //Projectile* fire;
            int counter;
            bool can_attack;

        public:

            Player();

            ~Player();

            void setGround(bool on_ground);

            void jump();

            void run();

            void attack();

            void attackCounter();

            void score(int points);

            //Entity* getProjectile();

        };
    }
}

#endif //JOGO_PLAYER_H

