//
// Created by segalle on 11/25/21.
//

#ifndef JOGO_ENEMYCOLLISION_H
#define JOGO_ENEMYCOLLISION_H

#include "DarkEnergyOrb.h"
#include "EnergyOrb.h"
#include "Enemy.h"
#include "StaticEntity.h"

namespace managers {

    class EnemyCollision {

    public:

        EnemyCollision();

        ~EnemyCollision();

        void enemyIsAlive(entities::characters::Enemy* enemy);

        void analyzeEnemyCollision(entities::characters::Enemy* enemy, entities::Entity* object);

        //Tem que ser id de projétil de player (Star)
        void enemyProjectileCollision(entities::characters::Enemy* enemy, entities::Projectile* projectile);

        void enemyObstacleCollision(entities::characters::Enemy *enemy, entities::StaticEntity *obstacle);

    };

}

#endif //JOGO_ENEMYCOLLISION_H
