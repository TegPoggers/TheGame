//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), spriteLoader(), menu(), p1(), p2(), event(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    spriteLoader.run();
    //Chamar initialize dos dois menus
    menu.initialize();
    healthy = new levels::HealthyForest(&p1, &p2);
    infected = new levels::InfectedForest(&p1, &p2);
    cout << "Construtora do Game" << endl;

    run();
}

Game::~Game() {

}

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

       /* //Se algo foi pressionado
        menu.renderMenu(GLOBAL_MENU_ITENS);
        menu.run();*/
        healthy->run();
       // infected->run();


        //window.menuEvents(&event);

        window.display();
    }
}