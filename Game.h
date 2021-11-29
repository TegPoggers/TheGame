//
// Created by segalle on 02/11/2021.
//

#ifndef JOGO_GAME_H
#define JOGO_GAME_H

#include "AssetManager.h"
#include "SpriteLoader.h"
#include "GlobalMenu.h"
#include "LeaderBoard.h"
#include "PlayerMenu.h"
#include "Player.h"
#include "LevelMenu.h"
#include "EndGame.h"

using namespace entities::characters;

class Game {

private:

    WindowManager window;
    AssetManager assets;
    SpriteLoader sprite_loader;
    menus::GlobalMenu menu;
    menus::PlayerMenu player_menu;
    menus::LevelMenu level_menu;
    menus::EndGame end_game;
    menus::LeaderBoard leader_board;
    Player p1;
    Player p2;

public:

    static sf::Event event;

    Game();

    ~Game();

    void run();

};


#endif //JOGO_GAME_H
