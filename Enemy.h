//
// Created by segalle on 11/21/21.
//

#ifndef JOGO_ENEMY_H
#define JOGO_ENEMY_H

#include "MovingEntity.h"
#include "Player.h"
#include "Projectile.h"

namespace entities {
    namespace characters {

        class Enemy : public MovingEntity{

        protected:

            Player* player;
            sf::Vector2f p_position;

        public:

            Enemy();

            ~Enemy();

            void setPlayer(Player* player);

            virtual void run() = 0;

            virtual void attack() = 0;

        };

    }
}

#endif //JOGO_ENEMY_H
