//
// Created by viviane on 22/11/2021.
//

#include "InfectedForest.h"

namespace levels{

    InfectedForest::InfectedForest(Player* p1, Player* p2, int playersNum, AssetManager* asset) : Level(p1, p2, playersNum, asset){
        initializeElements();
    }

    InfectedForest::~InfectedForest(){

    }

    void InfectedForest::run(){
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

    void InfectedForest::initializeElements(){
        cout << "Initialize" << endl;
        entityList->eList.push(p1);
        if (playersNum == 2)
            entityList->eList.push(p2);
        assets->LoadSprite(INFECTED_FOREST_PATH, "infectedForest");
        setBackground(assets->operator[]("infectedForest"));
        //setBackground(assets["healthyForest"]);
        setPosition(0,0);
    }

    void InfectedForest::createEnemies(){


    }

    void InfectedForest::createObstacles(){

    }
}