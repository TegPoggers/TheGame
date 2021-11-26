//
// Created by segalle on 11/25/21.
//

#include "HorizontalPureCollision.h"

namespace managers{

    HorizontalPureCollision::HorizontalPureCollision() {}

    HorizontalPureCollision::~HorizontalPureCollision() {}

    bool HorizontalPureCollision::findCollision(entities::Entity* object1, entities::Entity* object2) {
        bool collided = false;

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
                collide(object1, object2);
                collided = true;
            }
        }
        return collided;
    }

    void HorizontalPureCollision::collide(entities::Entity *object1, entities::Entity *object2) {
        if(object1->getPosition().x > object2->getPosition().x){
            object1->move(sf::Vector2f (5, 0));
            object2->move(sf::Vector2f (-5, 0));
        }
        else{
            object1->move(sf::Vector2f (-5, 0));
            object2->move(sf::Vector2f (5, 0));
        }
    }

}