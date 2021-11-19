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



    sf::Texture texture;
    texture.loadFromFile("../Resources/Textures/bolinha.png");
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Teste");

    window.setFramerateLimit(144);
    while(window.isOpen()){
        window.clear();
        //sf::Sprite* a;
        //a = assets["failed_tex"];
        //sf::Vector2f position = teste.getPosition();
        //sprite.setPosition(position);
        window.draw(sprite);
        sprite.move(0.5, 1);
        window.display();
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