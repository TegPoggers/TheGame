//
// Created by segalle on 11/24/21.
//

#include "CollisionManager.h"

namespace managers{

    CollisionManager::CollisionManager() {}

    CollisionManager::~CollisionManager() {}

    void CollisionManager::setEntityList(EntityList *entities) {
        entity_list = entities;
    }

    bool CollisionManager::runEntities() {
        for (int i = 0; i < entity_list->eList.getLen(); i++){

            entity_list->eList.getItem(i)->run();
            entity_list->eList.getItem(i)->getSprite()->setPosition(entity_list->eList.getItem(i)->getPosition()); // Define

            //Verifica que tipo de inimigo que é e atira um projétil se for válido
            shootCurrent(i);

        }
    }

    void CollisionManager::runPhysics() {

        searchCollisions();
        removeDead();

    }

    void CollisionManager::removeDead() {
        for (int i = 0; i < entity_list->eList.getLen(); i++){

            //Tem que ver esse delete
            /*if(!entity_list->eList.getItem(i)->isAlive()){
                entities::Entity* remove = entity_list->eList.getItem(i);
                entity_list->eList.pop(remove);
                delete remove;
            }*/

        }
    }

    void CollisionManager::shootCurrent(int i) {
        int id = entity_list->eList.getItem(i)->getId();
        if(id >= 1 && id <= 4) {
            entities::characters::MovingEntity* shooter = dynamic_cast<entities::characters::MovingEntity*>(entity_list->eList.getItem(i));
            entities::Entity* orb = shooter->getProjectile();if(id == 4){cout << "hello " << endl;}
            if(orb != nullptr){
                entity_list->eList.push(orb);
            }
        }
    }

    void CollisionManager::flying(entities::Entity *entity) {
        if(entity->getId() == 1){
            entities::characters::Player* player = static_cast<entities::characters::Player*>(entity);
            if(player->getFeetPosition() > 725){
                player->setGround(true);
                player->setPosition(player->getPosition().x, 725 - player->getSprite()->getGlobalBounds().height);
            }
            else{
                player->setGround(false);
            }
        }
    }

    void CollisionManager::searchCollisions(){
        for (int i = 0; i < entity_list->eList.getLen(); i++){
            for(int j = 0; j < entity_list->eList.getLen(); j++){
                detectCollisions(entity_list->eList.getItem(i), entity_list->eList.getItem(j));
            }
        }
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
            //Testar o id dos outros e rodar colisão de acordo com isso
        }

    }

}