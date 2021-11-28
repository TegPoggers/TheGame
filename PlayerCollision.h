//
// Created by segalle on 11/25/21.
//

#ifndef JOGO_PLAYERCOLLISION_H
#define JOGO_PLAYERCOLLISION_H

#include "WeakGoblin.h"
#include "StrongGoblin.h"
#include "BossGoblin.h"

#include "Player.h"

#include "DarkEnergyOrb.h"
#include "EnergyOrb.h"
#include "Star.h"

#include "Spikes.h"
#include "FirePit.h"
#include "PointyBush.h"

#include "FinishLine.h"

namespace managers {

    class PlayerCollision {

    public:

        PlayerCollision();

        ~PlayerCollision();

        void playerIsAlive(entities::characters::Player *player);

        void analyzePlayerCollision(entities::characters::Player *player, entities::Entity *object);

        void playerPlayerCollision(entities::characters::Player *player1, entities::characters::Player *player2);

        //Tem que ser id de projétil inimigo (Energy e DarkEnergy Ball)
        void playerEnemyProjectileCollision(entities::characters::Player *player, entities::Projectile *projectile);

        void playerEnemyCollision(entities::characters::Player *player, entities::characters::Enemy *enemy);

        void playerObstacleCollision(entities::characters::Player *player, entities::StaticEntity *obstacle);

        void playerFinishCollision(entities::characters::Player *player, entities::FinishLine *finish);

    };

}

#endif //JOGO_PLAYERCOLLISION_H
