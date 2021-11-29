//
// Created by viviane on 18/11/2021.
//

#include "Level.h"

namespace levels{

    Level::Level() : Being() { }

    //NÃO SEI FAZER DESGRAÇAS DE CONSTRUTORAS AAAAAAAAAAAAAAAAAA
    Level::Level(Player* p1, Player* p2) : Being(),
    entityList(new EntityList()),
    background(nullptr),
    backPosition(),
    physics(),
    levelMaker(p1, entityList, assets)
    {
        this->p1 = p1;
        this->p2 = p2;
        won = false;
        physics.setEntityList(entityList);
        physics.setWindow(window);

       /* if (this->p1 && this->p2)
            onePlayer = false;
        else if (!this->p1)
            p1 = new Player();*/

        renderPlayers(Being::getMenuState(1));
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

    void Level::renderBackground(){
        for (int i = -1; i < 12; i++){
            background->setPosition(i * 1920 * GLOBAL_SCALE, 0);
            window->draw(background);
        }
    }

    //Teste com a lista ao invés do p1
    //Lembrar de testar quando o player1 morre, se a view funciona com o player 2
    void Level::setView() {
        if (entityList != nullptr){
            entities::Entity* entity = entityList->getItem(0);
            if (entity && entity->getId() == 1){
                window->getView().setCenter((entity->getPosition().x + entity->getSprite()->getGlobalBounds().width/2), WINDOW_HEIGHT/2);
            }
        }
        window->setView(window->getView());
    }

    //Mudar onePLayer para int
    void Level::renderPlayers(int players){
        InputManager inputs;
        p1->setId(1);
        p1->setSprite(assets->operator[]("player1"));
        p1->getSprite()->setScale(0.5, 0.5);
        p1->setPosition(0);
        entityList->push(p1);
        p1->setMapping(inputs.setLayout1());
        p1->setHealth(100);
        if (players == 2){
            p2->setId(1);
            p2->setSprite(assets->operator[]("player2"));
            p2->getSprite()->setScale(0.5, 0.5);
            p2->setPosition(-160);
            entityList->push(p2);
            p2->setMapping(inputs.setLayout2());
            p2->setHealth(100);

        }
    }

    void Level::run(){

        window->clear();

        renderBackground();

        players_alive = physics.runEntities();//Teste de colocar na master

        //isFinished();

        physics.searchCollisions();

        for (int i = 0; i < entityList->getLen(); i++){
            if(entityList->getItem(i)->getId() >= weak_goblin_id && entityList->getItem(i)->getId() <= boss_goblin_id){
                dynamic_cast<Enemy*>(entityList->getItem(i))->setPlayer(entityList->getItem(0));
            }
            entityList->getItem(i)->getSprite()->setPosition(entityList->getItem(i)->getPosition());
            window->draw(entityList->getItem(i)->getSprite());
        }

        if (isFinished() || !getPlayersAlive()){
            score = (p2 != nullptr) ? (p1->getScore() + p2->getScore()) : p1->getScore();
            if (!getPlayersAlive())
                Being::setMenuState(st_end_game, 0);
        }
        setView();

    }

    bool Level::isFinished() {

        if(entityList->getItem(0)->getPosition().x > DOOR_POSITION || entityList->getItem(1)->getPosition().x > DOOR_POSITION){
            won = true;
        }
        return won;
    }

    bool Level::getPlayersAlive(){
        return players_alive;
    }

    int Level::getScore() {
        return score;
    }

    bool Level::players_alive = false;

}