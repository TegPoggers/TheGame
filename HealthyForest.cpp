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
  /*  void HealthyForest::run(){
        window->getPWindow()->clear();
        renderBackground();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->run();
            //Erro aqui (?????)
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
        //window->getPWindow()->display();
    //}

    void HealthyForest::initializeElements(){
        setBackground(assets->operator[]("healthyForest"));
        setPosition(0,0);

        //Fazer weak goblin aleatórios //Fazer classe template com 3 parâmetros
        /*weakGoblin = new WeakGoblin();
        weakGoblin->setPlayer(p1); //Fazer try catch para ver se tem outro player
        weakGoblin->setId(2); //COnstrutora
        weakGoblin->setPosition(1060, 540);
        //weakGoblin->setPosition(0, 540);
        weakGoblin->setSprite(assets->getSprite("weakGoblin"));
        entityList->eList.push(weakGoblin);
        assets->getSprite("darkEnergyOrb")->setScale(0.1, 0.1);
        assets->getSprite("weakGoblin")->setScale(0.7, 0.7);*/

        levelMaker.createWeakGoblin();


        //Fazer Strong Goblin aleatórios
        strongGoblin = new StrongGoblin();
        strongGoblin->setPlayer(p1);
        strongGoblin->setId(3);
        strongGoblin->setPosition(600, 550);
        strongGoblin->setSprite(assets->getSprite("strongGoblin"));
        entityList->eList.push(strongGoblin);
        assets->getSprite("strongGoblin")->setScale(0.7, 0.7);

    }

    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}