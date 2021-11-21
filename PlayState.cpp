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

    assets.LoadSprite("../Resources/Textures/bolinha.png","bolinha");
    //display->insertSprite(*assets["failed_tex"]);

    sf::RenderWindow window;
    window.create(sf::VideoMode(1280, 720), "Teste");

    Player p1;
    Level level(&p1);
    p1.setSprite(assets["bolinha"]);
    p1.getSprite()->setScale(0.5, 0.5);
    p1.setPosition(100, 500);


    window.setFramerateLimit(144);
    while(window.isOpen()){
        window.clear();

        //Teste de player
        p1.run();
        p1.getSprite()->setPosition(p1.getPosition());
        p1.run();
        for (int i = 0; i < level.entityList->eList.getLen(); i++){
            printf("Salvou o player amém\n");
        }
        window.draw(*p1.getSprite());

        //Fim do teste

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