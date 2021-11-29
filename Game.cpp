//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), sprite_loader(), menu(), p1(), p2(), player_menu(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    sprite_loader.run();
    menu.initialize();
    player_menu.initialize();
    level_menu.initialize(&p1, &p2);
    end_game.initialize();
    leader_board.initialize();
}

Game::~Game() {

}


void Game::run() {

    while (window.isOpen()){
        window.clear();

        if (window.pollEvent(&event) && event.type == sf::Event::Closed){
            window.close();
            break;
        }

        switch (Being::getMenuState(0)) {

            case st_global_menu:
                menu.run();
                break;

            case st_player_menu:
                player_menu.run();
                break;

            case st_level_menu:
                level_menu.run();
                break;

            case st_end_game:
                end_game.run();
                p1.setHealth(100);
                p2.setHealth(100);
                p1.setScore(0);
                break;

            case st_leader_board:
                leader_board.run();
                break;

            case st_quit_game:
                window.close();
                break;

        }

        window.display();

    }

}


sf::Event Game::event = sf::Event();
