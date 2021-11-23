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

    sf::RenderWindow window;
    window.create(sf::VideoMode(1366, 768), "Teste");


    Player p1;
    p1.setId(1);
    p1.setSprite(assets["player1"]);
    p1.getSprite()->setScale(0.5, 0.5);
    p1.setPosition(100, 510);
    //Teste do define
    assets.LoadSprite(PLAYER_ORB_PATH, "playerOrb");
    Player p2;
    p2.setSprite(assets["playerOrb"]);
    p2.getSprite()->setScale(0.5, 0.5);
    p2.setPosition(50,100);

    //HealthyForest level(&p1, &p2, 2, &assets);
     InfectedForest level(&p1, &p2);


    window.setFramerateLimit(144);
    while(window.isOpen()){
        window.clear();

        //Teste de player
        //p2.run(); // Define
        p2.getSprite()->setPosition(p2.getPosition()); // Define
        p1.getSprite()->setPosition(p1.getPosition());
        p1.run();
        /*for (int i = 0; i < level.entityList->eList.getLen(); i++){
            printf("Salvou o player amém\n");
        }
        window.draw(*p1.getSprite());
        window.draw(*p2.getSprite()); //Define */
        level.run();
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