//
// Created by viviane on 21/11/2021.
//

#include "HealthyForest.h"

namespace levels{

    HealthyForest::HealthyForest(Player* p1, Player* p2, int playersNum, AssetManager* asset) : Level(p1, p2, playersNum, asset){
        initializeElements();
    }

    //Não sei fazer desgraça de destrutora
    HealthyForest::~HealthyForest(){

    }
    void HealthyForest::run(){
        window.clear();
        renderBackground();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->run();

            entityList->eList.getItem(i)->getSprite()->setPosition(entityList->eList.getItem(i)->getPosition()); // Define
            window.draw(*entityList->eList.getItem(i)->getSprite());
        }

        entities::Entity* orb = p1->getProjectile();

        if(orb != nullptr){
            entityList->eList.push(orb);orb->setSprite(assets->operator[]("playerOrb"));
        }

        //setView();
        window.display();
    }

    void HealthyForest::initializeElements(){
        cout << "Initialize" << endl;
        entityList->eList.push(p1);
        if (playersNum == 2)
            entityList->eList.push(p2);
        assets->LoadSprite(HEALTHY_FOREST_PATH, "healthyForest");
        setBackground(assets->operator[]("healthyForest"));
        //setBackground(assets["healthyForest"]);
        setPosition(0,0);
    }
    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}