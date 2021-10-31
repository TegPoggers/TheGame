//
// Created by segalle on 30/10/2021.
//

#ifndef JOGO_GAME_H
#define JOGO_GAME_H

#include <memory>
#include <string>
using namespace std;
#include <SFML/Graphics.hpp>
#include "StateMachine.h"
#include "AssetManager.h"
#include"InputManager.h"

namespace GameName {
    struct GameData{
        StateMachine machine;
        sf::RenderWindow window;
        AssetManager assets;
        InputManager input;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {

    private:

        //O jogo vai rodar a 144 fps pq eu quis e meu monitor e assim
        const float dt = 1.0f / 144.f;

        sf::Clock clock;

        GameDataRef data = std::make_shared<GameData>();

        void Run();

    public:
        Game(int width = 1920, int height = 1080, string title = "");
    };
}

#endif //JOGO_GAME_H
