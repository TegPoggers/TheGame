//
// Created by segalle on 11/24/21.
//

#ifndef JOGO_COLLISIONMANAGER_H
#define JOGO_COLLISIONMANAGER_H

#include "list"
using namespace std;

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
#include "EntityList.h"

namespace managers {

    class CollisionManager {

    private:

        EntityList* entity_list;

    public:

        CollisionManager();

        ~CollisionManager();

        void setEntityList(EntityList* entities);

        //retorna false se não tiver mais jogadores
        bool runPlayers();

        void runPhysics();

        //Detecta se está no ar e seja canJump como falso, seta como true caso contrário
        void flying(entities::Entity* entity);

        void detectCollisions(entities::Entity* object1, entities::Entity* object2);

        void analyzeCollision(entities::Entity* object1, entities::Entity* object2);



        void analyzePlayerCollision(entities::characters::Player player, entities::Entity* object);

        void PlayerPlayerCollision(entities::characters::Player player1, entities::characters::Player player2);

        //Tem que ser id de projétil inimigo (Energy e DarkEnergy Ball)
        void PlayerEnemyProjectileCollision(entities::characters::Player* player, entities::Projectile* projectile);

        void PlayerEnemyCollision(entities::characters::Player player, entities::characters::Enemy* enemy);

        void PlayerObstacleCollision(entities::characters::Player player, entities::StaticEntity* obstacle);


        void analyzeObstacleCollision(entities::StaticEntity* obstacle, entities::Entity* object);

        void ObstacleEnemyCollision(entities::StaticEntity* obstacle, entities::characters::Enemy* enemy);


        void analyzeEnemyCollision(entities::characters::Enemy* enemy, entities::Entity*);

        //Tem que ser id de projétil de player (Star)
        void enemyProjectileCollision(entities::characters::Enemy* enemy, entities::Projectile projectile);

    };

}

#endif //JOGO_COLLISIONMANAGER_H
