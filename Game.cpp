//
// Created by segalle on 02/11/2021.
//

#include "Game.h"
namespace saveSaps {
    Game::Game() {}

    Game::~Game() {}

    void Game::run(){

        WindowManager window(1280, 720);

        PlayState state(&window);

        while(window.isOpen()){
            window.render();
        }

        /*sf::RenderWindow window(sf::VideoMode(1280, 720), "Save Saps");

        //Draw a texture for testing (delete)

        AssetManager asset_manager;
        asset_manager.LoadTexture("../Resources/Textures/Failed.jpg", "failed_tex");

        sf::Texture failed_tex;
        failed_tex = asset_manager.GetTexture("failed_tex");
        sf::Sprite sprite;
        sprite.setTexture(failed_tex);

        while (window.isOpen())
        {


            sf::Event event;

            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }
            window.clear();
            window.draw(sprite);
            window.display();
        }*/
    }

}