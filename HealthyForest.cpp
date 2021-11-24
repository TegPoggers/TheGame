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
        window->getPWindow()->display();
    }

    void HealthyForest::initializeElements(){
        assets->LoadSprite(HEALTHY_FOREST_PATH, "healthyForest");

        entityList->eList.push(p1);
        if (!onePlayer)
            entityList->eList.push(p2);
        setBackground(assets->operator[]("healthyForest"));
        //setBackground((*assets)["healthyForest"]);
        setPosition(0,0);

        //Fazer weak goblin aletórios
        assets->LoadSprite(WEAK_GOBLIN, "weakGoblin");
        assets->LoadSprite(WEAK_GOBLIN_ORB, "weakGoblinOrb");
        assets->getSprite("weakGoblinOrb")->setScale(0.1, 0.1);
        assets->getSprite("weakGoblin")->setScale(0.7, 0.7);

        //Gerar strong goblin
        assets->LoadSprite(STRONG_GOBLIN, "strongGoblin");
        assets->LoadSprite(STRONG_GOBLIN_ORB, "strongGoblinOrb");
        assets->getSprite("strongGoblinOrb")->setScale(0.1, 0.1);
        assets->getSprite("strongGoblin")->setScale(0.7, 0.7);

        //Instanciar Goblin temporário
        //DE ONDE VEM O GOBLIN???
        goblin = new WeakGoblin();
        goblin->setPlayer(p1);
        goblin->setId(2);
        goblin->setPosition(500, 540);
        goblin->setSprite(assets->getSprite("weakGoblin"));
        entityList->eList.push(goblin);

    }

    void HealthyForest::createEnemies(){

    }

    void HealthyForest::createObstacles(){

    }

}