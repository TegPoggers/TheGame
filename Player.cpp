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
        inputs(nullptr) {

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
            }
            else if(inputs->isKeyPressed(sf::Keyboard::D)){
                speed.x = moving_speed;
            }
            else{
                speed.x = 0;
            }

            attack();

            jump();

            position += speed;

        }

        void Player::attack() {
            //projétil goes brrrrr
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

        float Player::moving_speed = 3;
        float Player::jump_speed = -12;
        float Player::gravity = 0.1;

    }

}