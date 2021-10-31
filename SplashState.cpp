//
// Created by segalle on 31/10/2021.
//

#include "SplashState.h"

namespace GameName{
    SplashState::SplashState(GameDataRef Data) :
    data(Data) {

    }

    void SplashState::Init(){
        data->assets.LoadFont("Splash screen.png", SPLASH_SCENE_BACKGROUND_FILEPATH);

        background.setTexture(data->assets.GetTexture("Splash screen.png"));
    }

    void SplashState::HandleInput() {
        sf::Event event;
        while(data->window.pollEvent(event)){
            if(sf::Event::Closed == event.type){
                data->window.close();
            }
            //Colocar aqui ajustes de resolução, tela inteira e afins
        }
    }

    void SplashState::Update(float dt) {
        if(clock.getElapsedTime().asSeconds() > SPLASH_SHOW_TIME){
            //switch to main menu
            cout << "Go to main menu" << endl;
        }
    }

    void SplashState::Draw(float dt) {
        data->window.clear(sf::Color::Black);

        data->window.draw(background);

        data->window.display();
    }


}
