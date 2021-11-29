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

        WindowManager* window;

    public:

        CollisionManager();

        ~CollisionManager();

        void mapCreatorCollision();

        void setEntityList(EntityList* entities);

        //Retorna false se não tiver mais jogadores
        bool runEntities();

        //Passa pelos elementos da lista e verifica quem atirou por meio de polling
        void shootCurrent(int i);

        //Retira os mortos da lista e os desaloca
        void removeDead();

        //Detecta se está no ar e seja canJump como falso, seta como true caso contrário
        void flying(entities::Entity* entity);

        //Loop para buscar colisões
        void searchCollisions();

        //Detector de colisões entre 2 sprites
        void detectCollisions(entities::Entity* object1, entities::Entity* object2);

        //Chama o subcollision resposável pela colisão atual ou não faz nada se não há interação
        void analyzeCollision(entities::Entity* object1, entities::Entity* object2);

        void setWindow(WindowManager* window);

    };

}

#endif //JOGO_COLLISIONMANAGER_H
