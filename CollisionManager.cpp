//
// Created by segalle on 11/24/21.
//

#include "CollisionManager.h"

namespace managers{

    CollisionManager::CollisionManager() {}

    CollisionManager::~CollisionManager() {}

    void CollisionManager::mapCreatorCollision() {
        bool done = false;
        while(!done) {
            done = true;
            for (int i = 0; i < entity_list->getLen(); i++) {
                for (int j = 0; j < entity_list->getLen(); j++) {
                    bool aux = creator_collision.findCollision(entity_list->getItem(i), entity_list->getItem(j));
                    if(aux) {
                        done = false;
                    }
                }
            }
        }
    }

    void CollisionManager::setEntityList(EntityList *entities) {
        entity_list = entities;
    }

    bool CollisionManager::runEntities() {
        for (int i = 0; i < entity_list->getLen(); i++){

            if(window->isOnView(entity_list->getItem(i)->getSprite())) {
                entity_list->getItem(i)->run();
                entity_list->getItem(i)->getSprite()->setPosition(entity_list->getItem(i)->getPosition()); // Define

                //Verifica que tipo de inimigo que é e atira um projétil se for válido
                shootCurrent(i);
                flying(entity_list->getItem(i));
            }
        }
        if(entity_list->getItem(0)->getId() == 1){
            return true;
        }
        return false;
    }

    void CollisionManager::removeDead() {
        for (int i = 0; i < entity_list->getLen(); i++){

            if(entity_list->getItem(i)->getId() >= 8 && entity_list->getItem(i)->getId() <= 10 && !window->isOnView(entity_list->getItem(i)->getSprite
            ())){
                entity_list->getItem(i)->die();
            }
            if(!entity_list->getItem(i)->isAlive()){
                entities::Entity* entity = entity_list->getItem(i);
                if(*entity == player_id) {
                    entity_list->pop(entity_list->getItem(i));
                }
                else{
                    if(entity_list->getItem(i)->getId() >= weak_goblin_id && entity_list->getItem(i)->getId() <= boss_goblin_id &&
                    entity_list->getItem(0)->getId() == player_id){
                        dynamic_cast<entities::characters::Player*>(entity_list->getItem(0))->score(15);
                    }
                    entity_list->pop(entity_list->getItem(i));
                    delete entity;
                }
            }

        }
    }

    void CollisionManager::shootCurrent(int i) {
        int id = entity_list->getItem(i)->getId();
        if(id >= 1 && id <= 4) {
            entities::characters::MovingEntity* shooter = dynamic_cast<entities::characters::MovingEntity*>(entity_list->getItem(i));
            entities::Entity* orb = shooter->getProjectile();
            if(orb != nullptr){
                entity_list->push(orb);
            }
        }
    }

    void CollisionManager::flying(entities::Entity *entity) {
        if(entity->getId() == player_id || entity->getId() == strong_goblin_id || entity->getId() == weak_goblin_id || entity->getId() ==
        boss_goblin_id){
            entities::characters::MovingEntity* faller = dynamic_cast<entities::characters::MovingEntity*>(entity);
            if(faller->getFeetPosition() > 725){
                faller->setGround(true);
            }
            else{
                faller->setGround(false);
            }
        }
    }

    void CollisionManager::searchCollisions(){
        for (int i = 0; i < entity_list->getLen(); i++){
            for(int j = 0; j < entity_list->getLen(); j++){
                if(entity_list->getItem(i)->getPosition().x < -700){
                    entity_list->getItem(i)->setPosition(-700, entity_list->getItem(i)->getPosition().y);
                }
                detectCollisions(entity_list->getItem(i), entity_list->getItem(j));
            }
        }
        removeDead();
    }

    void CollisionManager::detectCollisions(entities::Entity *object1, entities::Entity *object2) {
        //Verificar bounding box dos dois e verificar interseção

        sf::Vector2f top_left1(0, 0), bottom_right1(0,0);

        top_left1 = object1->getPosition();
        bottom_right1.x = object1->getPosition().x + object1->getSprite()->getGlobalBounds().width;
        bottom_right1.y = object1->getPosition().y + object1->getSprite()->getGlobalBounds().height;

        sf::Vector2f top_left2(0, 0), bottom_right2(0, 0);

        top_left2 = object2->getPosition();
        bottom_right2.x = object2->getPosition().x + object2->getSprite()->getGlobalBounds().width;
        bottom_right2.y = object2->getPosition().y + object2->getSprite()->getGlobalBounds().height;

        //Verificar se há colisão
        if(bottom_right1.y >= top_left2.y && top_left1.y <= bottom_right2.y){
            if(bottom_right1.x >= top_left2.x && top_left1.x <= bottom_right2.x) {
                //Começar a calcular colisões com tipo de personagem em mente
                analyzeCollision(object1, object2);
            }
        }

    }

    void CollisionManager::analyzeCollision(entities::Entity *object1, entities::Entity *object2) {

        if(object1->getId() != player_id && object2->getId() == player_id){
            entities::Entity* aux = object1;
            object1 = object2;
            object2 = aux;
        }
        if(object1->getId() == player_id){
            player_collisions.analyzePlayerCollision(dynamic_cast<entities::characters::Player*>(object1), object2);
        }

        if(object1->getId() < weak_goblin_id && object1->getId() > boss_goblin_id && object2->getId() >= weak_goblin_id && object2->getId() <=
        boss_goblin_id){
            entities::Entity* aux = object1;
            object1 = object2;
            object2 = aux;
        }
        if(object1->getId() >= weak_goblin_id && object1->getId() <= boss_goblin_id){
           enemy_collision.analyzeEnemyCollision(dynamic_cast<entities::characters::Enemy*>(object1), object2);
        }

    }

    void CollisionManager::setWindow(WindowManager *window) {
        this->window = window;
    }

}