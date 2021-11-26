//
// Created by viviane on 18/11/2021.
//

#include "Level.h"

namespace levels{

    Level::Level() : Being() { }

    //NÃO SEI FAZER DESGRAÇAS DE CONSTRUTORAS AAAAAAAAAAAAAAAAAA
    Level::Level(Player* p1, Player* p2) : Being(), entityList(new EntityList()), background(nullptr), backPosition(), levelMaker(p1, entityList, assets){
        this->p1 = p1;
        this->p2 = p2;
        onePlayer = true;
        physics.setEntityList(entityList);

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
        for (int i = -1; i < 12; i++){
            background->setPosition(i * 1920 * GLOBAL_SCALE, 0);
            window->getPWindow()->draw(*background);
        }
    }

    //Teste com a lista ao invés do p1
    //Lembrar de testar quando o player1 morre, se a view funciona com o player 2
    void Level::setView() {
        sf::View view(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
        if (entityList){
            entities::Entity* entity = entityList->eList.getItem(0);
            if (entity && entity->getId() == 1){
                view.setCenter((entity->getPosition().x + entity->getSprite()->getGlobalBounds().width/2), WINDOW_HEIGHT/2);
            }
        }
        window->getPWindow()->setView(view);
    }

    void Level::renderPlayers(bool onePlayer){
        InputManager inputs;
        p1->setId(1);
        p1->setSprite(assets->operator[]("player1"));
        p1->getSprite()->setScale(0.5, 0.5);
        p1->setPosition(0);
        entityList->eList.push(p1);
        p1->setMapping(inputs.setLayout1());
        if (!onePlayer){
            p2->setId(1);
            p2->setSprite(assets->operator[]("player2"));
            p2->getSprite()->setScale(0.5, 0.5);
            p2->setPosition(-160);
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

        physics.runEntities();

        physics.searchCollisions();

        for (int i = 0; i < entityList->eList.getLen(); i++){

            entityList->eList.getItem(i)->run();
            entityList->eList.getItem(i)->getSprite()->setPosition(entityList->eList.getItem(i)->getPosition()); // Define
            window->draw(entityList->eList.getItem(i)->getSprite());
            //Verifica que tipo de inimigo que é e atira um projétil se for válido
            //shootCurrent(i);  managers::CollisionManager collide; collide.flying(entityList->eList.getItem(i));

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