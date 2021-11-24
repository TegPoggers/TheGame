//
// Created by segalle on 08/11/2021.
//

#include "Entity.h"

namespace entities{

    Entity::Entity() :
    sprite(nullptr),
    position(0, 0),
    Being()
    {}

    Entity::~Entity() {}


    void Entity::setSprite(sf::Sprite *sprite) {
        this->sprite = sprite;
    }

    void Entity::setPosition(sf::Vector2f position) {
        this->position = position;
    }

    void Entity::setPosition(float x, float y) {
        position.x = x;
        position.y = y;
    }

    sf::Vector2f Entity::getPosition() {
        return position;
    }

    sf::Sprite *Entity::getSprite() {
        //Teste porque a sprite do orb tá ficando nula
       if (sprite == nullptr){
            sprite = assets->getSprite("playerOrb");
        }

        sprite->setPosition(position);
        return sprite;
    }

}




