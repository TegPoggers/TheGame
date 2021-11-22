//
// Created by segalle on 03/11/2021.
//

#ifndef JOGO_PLAYSTATE_H
#define JOGO_PLAYSTATE_H

#include "AssetManager.h"
#include "WindowManager.h"
#include "SFML/Graphics.hpp"


#include "InputManager.h"
#include "Player.h"
using namespace entities::characters;

//Modificações aqui
#include "HealthyForest.h"
#include "InfectedForest.h"
using namespace levels;

class PlayState {

private:
    AssetManager assets;
    sf::Sprite error_sprite;
    WindowManager* display;

public:
    PlayState(WindowManager* window);

    ~PlayState();

    void loadState();

    void runState();

};

#endif //JOGO_PLAYSTATE_H
