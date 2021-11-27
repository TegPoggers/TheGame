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

        switch (Being::getMenuState()) {

            case st_global_menu:
                //menu.run();
                healthy->run();
                //infected->run();
                //cout << "State " << Being::getMenuState << endl;
                break;

            case st_player_menu:
                break;

            case st_run_healthy_forest_p1:
                break;

            case st_run_healthy_forest_p2:
                break;

            case st_run_infected_forest_p1:
                break;

            case st_run_infected_forest_p2:
                //cout << "run da healthy" << endl;
               // healthy->run();
                break;

            case st_leader_board:
                break;

            case st_quit_game:
                break;

            case st_load_game:
                break;

            case st_return:
                break;
        }



        window.display();
    }
}
