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
#include "PlayerMenu.h"
#include "HealthyForest.h"
#include "InfectedForest.h"
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
    Player p1;
    Player p2;
    levels::HealthyForest* healthy;
    levels::InfectedForest* infected;
    bool onePlayer;
    static int finalScore;

public:

    static sf::Event event;

    Game();

    ~Game();

    void run();

    void renderLevel();

    static void setFinalScore (int score) { finalScore = score; }

    static int getFinalScore() { return finalScore; }

};


#endif //JOGO_GAME_H
