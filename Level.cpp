//
// Created by viviane on 18/11/2021.
//

#include "Level.h"

namespace levels{

    Level::Level() : Being() { }

    //NÃO SEI FAZER DESGRAÇAS DE CONSTRUTORAS AAAAAAAAAAAAAAAAAA
    Level::Level(Player* p1, Player* p2) : Being(), background(nullptr), backPosition(){
        this->p1 = p1;
        this->p2 = p2;
        onePlayer = true;
        entityList = new EntityList();

        if (this->p1 && this->p2)
            onePlayer = false;
        else if (!this->p1)
            p1 = new Player();

        renderPlayers(onePlayer);
        //Aloca inimigos
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

    void Level::loadGame(){

    }

    void Level::renderBackground(){
        for (int i = -1; i < 10; i++){
            background->setPosition(i * 1920 * GLOBAL_SCALE, 0);
            window->getPWindow()->draw(*background);
        }
    }

    void Level::setView() {
        sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        view.setCenter((p1->getPosition().x + p1->getSprite()->getGlobalBounds().width/2), WINDOW_HEIGHT/2);
        window->getPWindow()->setView(view);
    }

    void Level::renderPlayers(bool onePlayer){
        InputManager inputs;
        p1->setId(1);
        p1->setSprite(assets->operator[]("player1"));
        p1->getSprite()->setScale(0.5, 0.5);
        p1->setPosition(0, 510);
        entityList->eList.push(p1);
        p1->setMapping(inputs.setLayout1());
        if (!onePlayer){
            p2->setId(1);
            p2->setSprite(assets->operator[]("player2"));
            p2->getSprite()->setScale(0.5, 0.5);
            p2->setPosition(-160, 510);
            entityList->eList.push(p2);
            p2->setMapping(inputs.setLayout2());

        }
    }

    void Level::shootCurrent(int i) {
        int id = entityList->eList.getItem(i)->getId();
        if(id >= 1 && id <= 4) {
            MovingEntity* shooter = dynamic_cast<MovingEntity*>(entityList->eList.getItem(i));
            entities::Entity* orb = shooter->getProjectile();if(id == 4){cout << "hello " << endl;}
            if(orb != nullptr){
                entityList->eList.push(orb);
            }
        }
        /*if(id == 2){
            MovingEntity* shooter = static_cast<WeakGoblin*>(entityList->eList.getItem(i));
            entities::Entity* orb = shooter->getProjectile();
            if(orb != nullptr){
                entityList->eList.push(orb);
                orb->setSprite(assets->operator[]("weakGoblinOrb"));
            }
        }*/
    }

    void Level::run(){
        window->getPWindow()->clear();
        renderBackground();
        for (int i = 0; i < entityList->eList.getLen(); i++){
            entityList->eList.getItem(i)->run();
            entityList->eList.getItem(i)->getSprite()->setPosition(entityList->eList.getItem(i)->getPosition()); // Define
            window->draw(entityList->eList.getItem(i)->getSprite());
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

        setView();
        window->getPWindow()->display();
    }

}