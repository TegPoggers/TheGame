//
// Created by viviane on 24/11/2021.
//

#ifndef JOGO_LEVELMAKER_H
#define JOGO_LEVELMAKER_H

#include <cstdlib>
#include <ctime>

#include "AssetManager.h"
#include "EntityList.h"
#include "WeakGoblin.h"
#include "StrongGoblin.h"
#include "BossGoblin.h"
#include "Spikes.h"
#include "PointyBush.h"
#include "FirePit.h"
#include "Player.h"

using namespace entities::characters;
using namespace entities::obstacles;


namespace levels{

    class LevelMaker {
    private:
        Player* player;
        EntityList* entityList;
        AssetManager* assets;
        int max_entities;
        float Xposition;

    public:
        LevelMaker();
        LevelMaker(Player* p, EntityList* list, AssetManager* asset);
        ~LevelMaker();

        //Pelo menos 3 instâncias de cada tipo (min de 2 tipos)

        void createWeakGoblin();
        void createStrongGoblin();
        void createBossGoblin();
        void createSpikes();
        void createFirePit();
        void createPointyBush();
        void renderObstacles();
    };

}


#endif //JOGO_LEVELMAKER_H
