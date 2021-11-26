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
            done = false;
            for (int i = 0; i < entity_list->getLen(); i++) {
                for (int j = 0; j < entity_list->getLen(); j++) {
                    bool aux = creator_collision.findCollision(entity_list->getItem(i), entity_list->getItem(j));
                    if(!done) {
                        done = aux;
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

            entity_list->getItem(i)->run();
            entity_list->getItem(i)->getSprite()->setPosition(entity_list->getItem(i)->getPosition()); // Define

            //Verifica que tipo de inimigo que é e atira um projétil se for válido
            shootCurrent(i);
            flying(entity_list->getItem(i));

        }
        if(entity_list->getItem(0)->getId() == 1){
            return true;
        }
        return false;
    }

    void CollisionManager::runPhysics() {

        searchCollisions();
        removeDead();

    }

    void CollisionManager::removeDead() {
        for (int i = 0; i < entity_list->getLen(); i++){

            //Tem que ver esse delete
            if(!entity_list->getItem(i)->isAlive()){
                entity_list->pop(entity_list->getItem(i));
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
        if(entity->getId() == 1){
            entities::characters::Player* player = static_cast<entities::characters::Player*>(entity);
            if(player->getFeetPosition() > 725){
                player->setGround(true);
            }
            else{
                player->setGround(false);
            }
        }
    }

    void CollisionManager::searchCollisions(){
        for (int i = 0; i < entity_list->getLen(); i++){
            for(int j = 0; j < entity_list->getLen(); j++){
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

    }

}