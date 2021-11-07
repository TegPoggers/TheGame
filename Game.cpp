//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() {}

Game::~Game() {}

void Game::run(){

    WindowManager window(1280, 720);

    PlayState state(&window);

    //Remover
    InputManager test;

    while(window.isOpen()){
        window.render();
        if(test.isKeyPressed(sf::Keyboard::A)){cout << "a";}
        if(test.isKeyPressed(sf::Keyboard::S)){cout << "s";}
    }
}