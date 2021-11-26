//
// Created by viviane on 22/11/2021.
//

#include "InfectedForest.h"

namespace levels{

    InfectedForest::InfectedForest() : Level(){ }

    InfectedForest::InfectedForest(Player* p1, Player* p2) : Level(p1, p2){
        initializeElements();
    }

    InfectedForest::~InfectedForest(){

    }

    void InfectedForest::initializeElements(){

        setBackground(assets->operator[]("infectedForest"));
        setPosition(0,0);
        levelMaker.createStrongGoblin();
        levelMaker.createWeakGoblin();
        levelMaker.createBossGoblin();
        levelMaker.renderObstacles();
        for (int i = 0; i < entityList->getLen(); i++){
            entityList->getItem(i)->setFeetPosition(725);
            if (entityList->getItem(i)->getId() == fire_pit_id){
                entityList->getItem(i)->setFeetPosition(775);
            }
        }
    }

    void InfectedForest::createEnemies(){


    }

    void InfectedForest::createObstacles(){

    }
}