//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), spriteLoader(), menu(), p1(), p2(), event(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    spriteLoader.run();
    onePlayer = true;
    //Chamar initialize dos dois menus
    menu.initialize();
    playerMenu.initialize(&p1);
    healthy = new levels::HealthyForest(&p1, &p2);
    infected = new levels::InfectedForest(&p1, &p2);
    cout << "Construtora do Game" << endl;

    run();
}

Game::~Game() {

}

/*
void Game::run(){

   while(window.isOpen()){
        window.clear();
        //menu.renderMenu(GLOBAL_MENU_ITENS);
       // &event = window.pollEvent(&event);
       /* while (window.pollEvent(&event)){
            switch (event.type) {

                case sf::Event::KeyPressed:
                    //fechar o menu e mostrar a fase
                    menu.run();
                    break;

                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    //infected->run();
                    break;
            }
        }*/

        //Rodar o menu

        //Se algo foi pressionado
        //menu.renderMenu(GLOBAL_MENU_ITENS);
        //menu.run();*/
        //healthy->run();
       // infected->run();


        //window.menuEvents(&event);
/*
        window.display();
    }
}*/

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
                //healthy->run();
                //infected->run();
                cout << "State no game" << Being::getMenuState(0) << endl;
                //[0] = st_player_menu [1] fase
                break;

                //State como um vetor[2]. posição 0 -> pra onde manda, 1, informção adicional
            case st_player_menu:
                playerMenu.run(); // [0]menuP = [1] fase e [1] 0 = onePlayer
                //onePlayer = playerMenu.isOnePlayer(); //Talvez ignorar isso
                //
                //
                // renderLevel();
                //[0] = fase  [1] = players
                break;

            case st_run_healthy_forest:
                //
                // playerMenu.run();
                cout << "Era pra rodar aqui" << endl;
                healthy->run();
                //renderLevel();
                break;

            case st_run_infected_forest:
                //healthy->run();
                //renderLevel();
                infected->run();
                break;

            case st_leader_board:
                break;

            case st_quit_game:
                window.close();
                break;

            case st_load_game:
                break;

            /* E so setar o state como menu
            case st_return:
                menu.run();
                break;*/
        }



        window.display();

    }

}

void Game::renderLevel(){
    if (Being::getMenuState(0) == st_run_healthy_forest){
        //(onePlayer) ? healthy->initializePlayers(&p1, nullptr) : healthy->initializePlayers(&p1, &p2);
       // healthy->initializePlayers(&p1, &p2);
        //healthy->initializeElements();
        cout << "Rendeu a healthy " << endl;
        healthy->renderPlayers(Being::getMenuState(1)); //Seg fault
        //healthy->run();
        /*if (Being::getMenuState(1) == 2){
            healthy = new levels::HealthyForest(&p1, &p2);
        } else {
            healthy = new levels::HealthyForest(&p1, nullptr);
        }*/
    } else if (Being::getMenuState(0) == st_run_infected_forest){
        (onePlayer) ? infected->initializePlayers(&p1, nullptr) : infected->initializePlayers(&p1, &p2);
        infected->initializeElements();
        //infected->run();
    }
}
