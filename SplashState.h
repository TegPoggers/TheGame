//
// Created by segalle on 31/10/2021.
//

#ifndef JOGO_SPLASHSTATE_H
#define JOGO_SPLASHSTATE_H

#include <SFML/Graphics.hpp>

#include "Definitions.h"

#include "State.h"

#include "Game.h"

#include <sstream>

#include <iostream>
using namespace std;

namespace GameName {

        class SplashState : public State {

        private:
            GameDataRef data;

            sf::Clock clock;

            sf::Sprite background;

            sf::Texture background_texture;

        public:
            SplashState(GameDataRef Data);

            void Init();

            void HandleInput();

            void Update(float dt);

            void Draw(float dt);

        };
}

#endif //JOGO_SPLASHSTATE_H
