//
// Created by segalle on 02/11/2021.
//

#ifndef JOGO_GAME_H
#define JOGO_GAME_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
//#include "AssetManager.h"
#include "WindowManager.h"
#include "PlayState.h"


#include "InputManager.h"

namespace saveSaps {
    class Game {
    private:

    public:
        Game();

        ~Game();

        void run();
    };
}

#endif //JOGO_GAME_H
