//
// Created by segalle on 11/7/21.
//

#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::setPosition(sf::Vector2f pos) {
    position = pos;
}

void Player::draw() {
}

void Player::setWindow(WindowManager *window) {
    this->window = window;
}

bool Player::isMoving() {
    return is_moving;
}

void Player::setSprite(sf::Sprite* sprite) {
    this->sprite = sprite;
}

void Player::manageInputs() {

    if(inputs->isKeyPressed(sf::Keyboard::A) && inputs->isKeyPressed(sf::Keyboard::D) || !inputs->isKeyPressed(sf::Keyboard::A) &&
    !inputs->isKeyPressed(sf::Keyboard::D)){
        is_moving = false;
    }
    else if(inputs->isKeyPressed(sf::Keyboard::A)){
        is_moving = true;
        //moving_speed = -0.1;
    }
    else if(inputs->isKeyPressed(sf::Keyboard::D)){
        is_moving = true;
        //moving_speed = 0.1;
    }

    //Fazer o atirar e andar

}

void Player::runPhysics() {

    manageInputs();

    if(is_moving){
        //position.x += moving_speed;
    }

}

float Player::moving_speed = 1.5;