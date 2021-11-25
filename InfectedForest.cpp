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

    /*void InfectedForest::run(){
        window->getPWindow()->clear();
        renderBackground();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->run();

            entityList->eList.getItem(i)->getSprite()->setPosition(entityList->eList.getItem(i)->getPosition()); // Define
            window->getPWindow()->draw(*entityList->eList.getItem(i)->getSprite());
            //Verifica que tipo de inimigo que é e atira um projétil se for válido
            shootCurrent(i);

        }

        /*entities::Entity* orb = p1->getProjectile();

        if(orb != nullptr){
            entityList->eList.push(orb);
            orb->setSprite(assets->operator[]("playerOrb"));
        }

        orb = goblin->getProjectile();
        if(orb){
            entityList->eList.push(orb);orb->setSprite(assets->operator[]("playerOrb"));
        }*/

        //setView();
       // window->getPWindow()->display();
    //}

    void InfectedForest::initializeElements(){

        setBackground(assets->operator[]("infectedForest"));
        setPosition(0,0);

        //Fazer Strong Goblin aleatórios -> Fire vazio
        strongGoblin = new StrongGoblin();
        strongGoblin->setPlayer(p1);
        strongGoblin->setId(3);
        strongGoblin->setPosition(500, 545);
        strongGoblin->setSprite(assets->getSprite("strongGoblin"));
        entityList->eList.push(strongGoblin);
        assets->getSprite("strongGoblin")->setScale(0.7, 0.7);


        //Fazer Strong Boss direito -> Fire está vazio
        bossGoblin = new BossGoblin();
        bossGoblin->setPlayer(p1);
        bossGoblin->setId(4);
        bossGoblin->setPosition(1000, 210);
        bossGoblin->setSprite(assets->getSprite("bossGoblin"));
        entityList->eList.push(bossGoblin);
        assets->getSprite("energyOrb")->setScale(0.1, 0.1);
        assets->getSprite("bossGoblin")->setScale(2, 2);

    }

    void InfectedForest::createEnemies(){


    }

    void InfectedForest::createObstacles(){

    }
}