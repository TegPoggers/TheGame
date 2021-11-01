//
// Created by segalle on 30/10/2021.
//

#include "Game.h"
#include "SplashState.h"

namespace GameName{
    Game::Game(int width, int height, string title) {
        data->window.create(sf::VideoMode(width, height), title, sf::Style::Close | sf::Style::Titlebar);

        data->machine.AddState(StateRef(new SplashState(data)));
        /*
         * Iniciar aqui o primeiro state do jogo (provavelmente menu ou alguma forma de carregamento)
         */


        Run();
    }

    void Game::Run() {
        float new_time = 0, frame_time = 0, interpolation = 0;

        float current_time = 0;
        current_time = clock.getElapsedTime().asSeconds();
        float accumulator = 0.0f;

        while(data->window.isOpen()){
            data->machine.ProcessStateChanges();

            new_time = clock.getElapsedTime().asSeconds();

            frame_time = new_time - current_time;

            if(frame_time > 0.25f){
                current_time = 0.25f;
            }
            current_time = new_time;
            accumulator += frame_time;

            while(accumulator >= dt){
                data->machine.GetActiveState()->HandleInput();
                data->machine.GetActiveState()->Update(dt);

                accumulator -= dt;
            }
            interpolation = accumulator / dt;

            data->machine.GetActiveState()->Draw(interpolation);
        }

    }
}
