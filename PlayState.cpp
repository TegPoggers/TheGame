//
// Created by segalle on 03/11/2021.
//

#include "PlayState.h"

namespace saveSaps{

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
        display->insertSprite(assets["failed_tex"]);

        //Testes
        /*InputManager test;
        sf::RenderWindow window;
        window.create(sf::VideoMode(1280, 720), "Teste");

        while(window.isOpen()){
            window.clear();
            window.draw(assets.GetSprite("failed_tex"));
            window.display();
            if(test.isSpriteClicked(assets["failed_tex"], &window, sf::Mouse::Left)){cout << "oie";};
        }*/

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
}

/**PlayState();
        ~PlayState();

        void loadState();

        void runState();*/