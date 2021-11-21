//
// Created by segalle on 11/21/21.
//

#include "Enemy.h"

namespace entities{
    namespace characters{

        Enemy::Enemy() : MovingEntity(){}

        void Enemy::setPlayer(Player *player) {
            this->player = player;
        }

    }
}