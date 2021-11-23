//
// Created by viviane on 21/11/2021.
//

#ifndef JOGO_HEALTHYFOREST_H
#define JOGO_HEALTHYFOREST_H


#include "Level.h"

namespace levels{

    class HealthyForest : public Level{
    public:
        HealthyForest();
        HealthyForest(Player* p1, Player* p2);
        ~HealthyForest();
        void run();
        void initializeElements();
        void createEnemies();
        void createObstacles();

    };

}


#endif //JOGO_HEALTHYFOREST_H
