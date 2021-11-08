//
// Created by segalle on 08/11/2021.
//

#include "Entity.h"

Entity::Entity() :
position(0, 0),
sprite(nullptr),
window(nullptr)
{}

Entity::Entity(WindowManager *window):
position(0, 0),
sprite(nullptr),
window(window) {
    if(window == nullptr){
        cout << "Foi passada uma janela nula a entidade" << endl;
    }
}

Entity::~Entity() {
    window = nullptr;
    sprite = nullptr;
    position.x = position.y = 0;
}

void Entity::draw() {
    window->draw(sprite);
}

sf::Vector2f Entity::getPosition() {
    return position;
}

void Entity::setPosition(sf::Vector2f position) {
    this->position = position;
}

void Entity::setSprite(sf::Sprite* sprite) {
    this->sprite = sprite;
}

void Entity::setWindow(WindowManager *window) {
    this->window = window;
    if(this->window == nullptr){
        cout << "Foi passada uma janela nula a entidade" << endl;
    }
}









