//
// Created by segalle on 08/11/2021.
//

#include "Entity.h"

namespace entities{

    Entity::Entity() : Being(),
    sprite(nullptr),
    position(0, 0),
    alive(true)
    {}

    Entity::~Entity() {
        sprite = assets->getSprite("failedTexture");
    }


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

    const sf::Vector2f Entity::getPosition() const {
        return position;
    }

    sf::Sprite *Entity::getSprite() {

        sprite->setPosition(position);
        return sprite;

    }

    float Entity::getFeetPosition() {
        return sprite->getPosition().y + sprite->getGlobalBounds().height;
    }

    void Entity::setFeetPosition(float feet_position) {
        position.y = feet_position - sprite->getGlobalBounds().height;
    }

    void Entity::die() {
        alive = false;
    }

    bool Entity::getIsAlive(){
        return alive;
    }

    void Entity::move(sf::Vector2f amount) {
        position += amount;
    }

    void Entity::setIsAlive(bool isAlive){
        alive = isAlive;
    }


}




