//
// Created by segalle on 03/11/2021.
//

#include "PlayState.h"



PlayState::PlayState(WindowManager* window) :
assets(),
error_sprite(),
display(window)
{
    loadState();
}

PlayState::~PlayState() {//Esvaziar a window manager list

}

void PlayState::loadState() {
    //É pra pegar a textura de erro mesmo

    assets.LoadSprite("../Resources/Textures/Failed.jpg","failed_tex");
    //display->insertSprite(*assets["failed_tex"]);

    assets.LoadSprite("../Resources/Textures/bolinha.png", "bolinha");

    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Teste");



    while(window.isOpen()){
        window.clear();
        for(int i = 0; i < 10000; i++) {
            window.clear();
            window.draw(*assets["failed_tex"]);
            window.display();
        }
        for(int i = 0 ; i < 10000; i++){
            window.clear();
            window.draw(*assets["bolinha"]);
            window.display();
            sf::Vector2f diminui; diminui.x = 0.5;diminui.y = 0.5;
            assets.setScale("bolinha", diminui);
        }
    }

    //sf::Texture lalala;
    //lalala.loadFromFile("../Resources/Textures/Failed.jpg");
    //error_sprite.setTexture(lalala);


    /*display->insertSprite(&error_sprite);
    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Teste");

    while(window.isOpen()){
        window.clear();
        window.draw(error_sprite);
        window.display();
    }*/
}
void PlayState::runState() {
    //Runs the state with everything it may need, this bit controls time
}