//
// Created by segalle on 11/7/21.
//

#include "Player.h"
namespace entities {
    namespace characters {

        Player::Player() {
            inputs = new InputManager();
        }

        Player::~Player() {
            delete inputs;
        }

        void Player::run() {
            //Takes inputs, current speeds and moves accordingly

            position += speed;

            jump();
        }

        void Player::jump() {
            if(ground && inputs->isKeyPressed(sf::Keyboard::W)){
                speed.y = jump_speed;
            }
        }

        //Collision managers precisa rodar essa função all frame pra você não cair pelo chão
        void Player::setGround(bool on_ground) {
            ground = on_ground;
            if(ground){
                speed.y = 0;
            }
        }

        float Player::moving_speed = 1.5;
        float Player::jump_speed = 10;

    }
}