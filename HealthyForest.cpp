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
    void HealthyForest::run(){
        window->getPWindow()->clear();
        renderBackground();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->run();
            //Erro aqui (?????)
            entityList->eList.getItem(i)->getSprite()->setPosition(entityList->eList.getItem(i)->getPosition()); // Define
            window->getPWindow()->draw(*entityList->eList.getItem(i)->getSprite());
        }

        entities::Entity* orb = p1->getProjectile();

        if(orb != nullptr){
            entityList->eList.push(orb);
            orb->setSprite(assets->operator[]("playerOrb"));
        }

        //setView();
        window->getPWindow()->display();
    }

    void HealthyForest::initializeElements(){
        cout << "Initialize" << endl;
        entityList->eList.push(p1);
        if (!onePlayer)
            entityList->eList.push(p2);
        assets->LoadSprite(HEALTHY_FOREST_PATH, "healthyForest");
        setBackground(assets->operator[]("healthyForest"));
        //setBackground((*assets)["healthyForest"]);
        setPosition(0,0);
    }

    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}