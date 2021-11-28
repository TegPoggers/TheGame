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
#include "LeaderBoard.h"
#include "PlayerMenu.h"
#include "Player.h"
#include "LevelMenu.h"
#include "EndGame.h"
using namespace entities::characters;
//Incluir menu


class Game {

private:
    WindowManager window;
    AssetManager assets;
    SpriteLoader spriteLoader;
    menus::GlobalMenu menu;
    menus::PlayerMenu playerMenu;
    menus::LevelMenu levelMenu;
    menus::EndGame endGame;
    menus::LeaderBoard leaderBoard;
    Player p1;
    Player p2;
    bool onePlayer;

public:

    static sf::Event event;

    Game();

    ~Game();

    void run();


};


#endif //JOGO_GAME_H
