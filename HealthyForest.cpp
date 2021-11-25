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
    }

    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}