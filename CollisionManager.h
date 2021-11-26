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

#include "HorizontalPureCollision.h"
#include "PlayerCollision.h"
#include "EnemyCollision.h"

namespace managers {

    class CollisionManager {

    private:

        EntityList* entity_list;

        PlayerCollision player_collisions;

        EnemyCollision enemy_collision;

        HorizontalPureCollision creator_collision;

    public:

        CollisionManager();

        ~CollisionManager();

        void mapCreatorCollision();

        void setEntityList(EntityList* entities);

        //retorna false se não tiver mais jogadores
        bool runEntities();

        void runPhysics();

        void shootCurrent(int i);

        //Retira os mortos da lista e os desaloca
        void removeDead();

        //Detecta se está no ar e seja canJump como falso, seta como true caso contrário
        void flying(entities::Entity* entity);

        void searchCollisions();

        void detectCollisions(entities::Entity* object1, entities::Entity* object2);

        void analyzeCollision(entities::Entity* object1, entities::Entity* object2);


        void analyzeObstacleCollision(entities::StaticEntity* obstacle, entities::Entity* object);

        void ObstacleEnemyCollision(entities::StaticEntity* obstacle, entities::characters::Enemy* enemy);

    };

}

#endif //JOGO_COLLISIONMANAGER_H
