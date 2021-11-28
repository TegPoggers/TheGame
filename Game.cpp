//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), spriteLoader(), menu(), p1(), p2(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    spriteLoader.run();
    //Chamar initialize dos dois menus
    menu.initialize();
    playerMenu.initialize();
    levelMenu.initialize(&p1, &p2);
    endGame.initialize();
    //levelMenu.initialize(&p1, &p2);
    //healthy = new levels::HealthyForest(&p1, &p2);
    //infected = new levels::InfectedForest(&p1, &p2);
    cout << "Construtora do Game" << endl;

    run();
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
                playerMenu.run();
                break;

            case st_level_menu:
                levelMenu.run();
                //renderLevel();
                break;

            case st_end_game:
                cout << "Estou no end game" << endl;
                endGame.run();
                //Mudar para o leaderboard
                break;

            case st_leader_board:
                cout << "Estou no leader" << endl;
                break;

            case st_quit_game:
                window.close();
                break;

        }

        window.display();

    }

}

void Game::renderLevel(){
    if (Being::getMenuState(0) == st_run_healthy_forest){

        healthy->renderPlayers(Being::getMenuState(1)); //Seg fault

    } else if (Being::getMenuState(0) == st_run_infected_forest){
        (onePlayer) ? infected->initializePlayers(&p1, nullptr) : infected->initializePlayers(&p1, &p2);
        infected->initializeElements();
        //infected->run();
    }
}

sf::Event Game::event = sf::Event();
int Game::finalScore = 0;