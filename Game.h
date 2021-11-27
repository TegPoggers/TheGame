//
// Created by segalle on 02/11/2021.
//

#ifndef JOGO_GAME_H
#define JOGO_GAME_H

/*#include <SFML/Window.hpp> //Precisa desse?
#include <SFML/Graphics.hpp>
#include "WindowManager.h"
#include "InputManager.h" */
//#include "PlayState.h"
#include "AssetManager.h"
#include "SpriteLoader.h"
#include "GlobalMenu.h"
#include "HealthyForest.h"
#include "InfectedForest.h"
#include "Player.h"
using namespace entities::characters;
//Incluir menu


class Game {

private:
    WindowManager window;
    AssetManager assets;
    SpriteLoader spriteLoader;
    menus::GlobalMenu menu;
    Player p1;
    Player p2;
    levels::HealthyForest* healthy;
    levels::InfectedForest* infected;
    sf::Event event;
    bool onePlayer;

public:

    Game();

    ~Game();

    void run();

};


#endif //JOGO_GAME_H
