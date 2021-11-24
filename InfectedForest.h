//
// Created by viviane on 22/11/2021.
//

#ifndef JOGO_INFECTEDFOREST_H
#define JOGO_INFECTEDFOREST_H

#include "Level.h"

namespace levels {

    class InfectedForest : public Level{
    public:
        InfectedForest();
        InfectedForest(Player* p1, Player* p2);
        ~InfectedForest();
        void run();
        void initializeElements();
        void createEnemies();
        void createObstacles();

        //Apagar
    private:
        BossGoblin* goblin;

    };
}




#endif //JOGO_INFECTEDFOREST_H
