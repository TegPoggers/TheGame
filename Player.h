//
// Created by segalle on 11/7/21.
//

#ifndef JOGO_PLAYER_H
#define JOGO_PLAYER_H

#include "InputManager.h"
#include <SFML/Graphics.hpp>
#include"WindowManager.h"


class Player { //:MovingEntity

private:
    static float moving_speed;
    static float jump_speed;
    InputManager* inputs;

public:

    Player();

    ~Player();

    void move(short int direction);

    bool canJump();//Precisa de collision manager

    void jump();

    void manageInputs();

    //Parte que estará em MovingEntity

private:

    sf::Vector2f position;
    WindowManager* window;
    bool is_moving;

public:
    bool isMoving();
    void runPhysics();

    //Parte que estará em Entity

private:

    sf::Sprite sprite;

public:

    void setWindow(WindowManager* window);
    void setSprite(sf::Sprite sprite);
    void draw();
    void setPosition(sf::Vector2f pos);

};

//float Player::moving_speed = 0.1;
//float Player::jump_speed = 1;

#endif //JOGO_PLAYER_H

