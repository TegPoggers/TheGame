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

            //Verifica que tipo de inimigo que é e atira um projétil se for válido
            shootCurrent(i);

        }

        /*entities::Entity* orb = p1->getProjectile();

        if(orb != nullptr){
            entityList->eList.push(orb);orb->setSprite(assets->operator[]("playerOrb"));
        }

        orb = goblin->getProjectile();
        if(orb){
            entityList->eList.push(orb);orb->setSprite(assets->operator[]("playerOrb"));
        }*/

        //setView();
        window.display();
    }

    void InfectedForest::initializeElements(){

        assets->LoadSprite(INFECTED_FOREST_PATH, "infectedForest");

        assets->LoadSprite(WEAK_GOBLIN, "weakGoblin");

        assets->LoadSprite(WEAK_GOBLIN_ORB, "weakGoblinOrb");
        assets->getSprite("weakGoblinOrb")->setScale(0.1, 0.1);

        assets->getSprite("weakGoblin")->setScale(0.7, 0.7);

        cout << "Initialize" << endl;
        entityList->eList.push(p1);
        if (playersNum == 2)
            entityList->eList.push(p2);

        setBackground(assets->operator[]("infectedForest"));
        //setBackground(assets["healthyForest"]);
        setPosition(0,0);

        //Apagar
        goblin = new BossGoblin();
        goblin->setPlayer(p1);
        goblin->setId(2);
        goblin->setPosition(500, 540);
        goblin->setSprite(assets->getSprite("weakGoblin"));
        entityList->eList.push(goblin);
    }

    void InfectedForest::createEnemies(){


    }

    void InfectedForest::createObstacles(){

    }
}