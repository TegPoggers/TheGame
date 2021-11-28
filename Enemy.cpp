//
// Created by segalle on 11/21/21.
//

#include "Enemy.h"

namespace entities{
    namespace characters{

        Enemy::Enemy() : MovingEntity(),
        player(nullptr),
        p_position(0, 0){}

        Enemy::~Enemy() {}

        void Enemy::setPlayer(Entity *player) {
            if(player->getId() == player_id) {
                this->player = dynamic_cast<Player*>(player);
            }
        }

    }
}