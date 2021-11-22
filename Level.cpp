//
// Created by viviane on 18/11/2021.
//

#include "Level.h"

namespace levels{

    //NÃO SEI FAZER DESGRAÇAS DE CONSTRUTORAS AAAAAAAAAAAAAAAAAA
    Level::Level(Player* p1, Player* p2, int playersNum, AssetManager* asset) : Being(), background(nullptr), backPosition(), assets(asset){
        this->p1 = p1;
        this->p2 = p2;
        this->playersNum = playersNum;
        entityList = new EntityList();
        window.create(sf::VideoMode(1366, 768), "Fase");
        window.setFramerateLimit(144);
        //Aloca inimigos
        //initializeElements();
    }

    Level::~Level(){

    }

    void Level::setPosition(float x, float y){
        backPosition.x = x;
        backPosition.y = y;
    }

    sf::Vector2f Level::getPosition(){
        return backPosition;
    }

    void Level::setBackground(sf::Sprite* background){
        this->background = background;
        this->background->setScale(GLOBAL_SCALE, GLOBAL_SCALE);

    }

/*
    void Level::initializeElements(){
        cout << "Initialize" << endl;
        entityList->eList.push(p1);
        if (playersNum == 2)
            entityList->eList.push(p2);
        assets->LoadSprite(HEALTHY_FOREST_PATH, "healthyForest");
        setBackground(assets->operator[]("healthyForest"));
        //setBackground(assets["healthyForest"]);
        setPosition(0,0);
    }
*/
    void Level::loadGame(){

    }

    void Level::renderBackground(){
        for (int i = 0; i < 10; i++){
            background->setPosition(i * 1920 * GLOBAL_SCALE, 0);
            window.draw(*background);
        }
        window.setView(sf::View(sf::FloatRect(0, 0, 1366, 768)));
    }

 /*   void Level::run(){
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
*/
    void Level::setView() {
        float radius_left = 130 - (1920 * GLOBAL_SCALE)/2;
        float radius_right = 130 + (1920 * GLOBAL_SCALE)/2;
        //window.setView(sf::View(sf::FloatRect (p1->getPosition().x - radius_left, 0, p1->getPosition().x + radius_right, 768)));
        window.setView(sf::View(sf::FloatRect(2000, 0, 3366, 768)));
    }

}