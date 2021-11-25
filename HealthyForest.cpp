//
// Created by viviane on 21/11/2021.
//

#include "HealthyForest.h"

namespace levels{

    HealthyForest::HealthyForest() : Level() { }

    HealthyForest::HealthyForest(Player* p1, Player* p2) : Level(p1, p2){
        initializeElements();
    }

    //Não sei fazer desgraça de destrutora
    HealthyForest::~HealthyForest(){

    }

    void HealthyForest::initializeElements(){
        setBackground(assets->operator[]("healthyForest"));
        setPosition(0,0);
        levelMaker.createWeakGoblin();
        levelMaker.createStrongGoblin();
        levelMaker.renderObstacles();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->setFeetPosition(725);
            if (entityList->eList.getItem(i)->getId() == fire_pit_id){
                entityList->eList.getItem(i)->setFeetPosition(775);
            }
        }
    }

    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}