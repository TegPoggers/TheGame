//
// Created by segalle on 11/7/21.
//

#include "Player.h"
namespace entities {
    namespace characters {

        Player::Player() : MovingEntity(),
        health(100),
        speed(0, 0),
        ground(true),
        inputs(nullptr),
        points(0),
        counter(0)
        {

            inputs = new InputManager();

        }

        Player::~Player() {
            delete inputs;
        }

        void Player::run() {
            //Takes inputs, current speeds and moves accordingly
            if(inputs->isKeyPressed(sf::Keyboard::A) && inputs->isKeyPressed(sf::Keyboard::D)){
                speed.x = 0;
            }
            else if(inputs->isKeyPressed(sf::Keyboard::A)){
                speed.x = -moving_speed;
                direction = -1;
            }
            else if(inputs->isKeyPressed(sf::Keyboard::D)){
                speed.x = moving_speed;
                direction = 1;
            }
            else{
                speed.x = 0;
            }
            fire = nullptr;;

            attackCounter();

            attack();

            jump();

            position += speed;

        }

        void Player::attack() {
            if(can_attack && inputs->isKeyPressed(sf::Keyboard::Space)){
                fire = new Projectile(this);
                fire->setDirection(direction);
                //fire->setPosition(position.x, position.y);
                float width = sprite->getGlobalBounds().width;
                float height = sprite->getGlobalBounds().height;

                fire->setPosition(sprite->getGlobalBounds().width/2 + position.x - 40, sprite->getGlobalBounds().height/2 + position.y - 20);
                counter = 0;
            }
        }

        void Player::jump() {
            if (ground && inputs->isKeyPressed(sf::Keyboard::W)) {
                speed.y = jump_speed;
                ground = false;
            }
            else if(ground){
                speed.y = 0;
            }
            else{
                speed.y += gravity;
            }
        }

        //Collision managers precisa rodar essa função all frame pra você não cair pelo chão
        void Player::setGround(bool on_ground) {
            ground = on_ground;
            if (ground) {
                speed.y = 0;
            }
        }

        void Player::score(int points) {
            this->points += points;
        }

        void Player::attackCounter() {
            counter++;
            if(counter < 144){
                can_attack = false;
            }
            else{
                can_attack = true;
            }
        }

        float Player::moving_speed = 2.5;
        float Player::jump_speed = -12;
        float Player::gravity = 0.1;

    }

}