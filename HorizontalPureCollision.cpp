//
// Created by segalle on 11/25/21.
//

#include "HorizontalPureCollision.h"

namespace managers{

    HorizontalPureCollision::HorizontalPureCollision() {}

    HorizontalPureCollision::~HorizontalPureCollision() {}

    bool HorizontalPureCollision::findCollision(entities::Entity* object1, entities::Entity* object2) {
        bool collided = false;

        float top_left1 = object1->getPosition().x;
        float top_right1 = object1->getPosition().x + object1->getSprite()->getGlobalBounds().width;

        float top_left2 = object2->getPosition().x;
        float top_right2 = object2->getPosition().x + object2->getSprite()->getGlobalBounds().width;

        if(top_left1 < top_right2 && top_left2 < top_right1){
            collide(object1, object2);
            collided = true;
        }

        return collided;

    }

    void HorizontalPureCollision::collide(entities::Entity *object1, entities::Entity *object2) {
        if(object1->getPosition().x < object2->getPosition().x) {
            object1->move(sf::Vector2f(-20, 0));
        }
        else{
            object1->move(sf::Vector2f(20, 0));
        }
    }

}