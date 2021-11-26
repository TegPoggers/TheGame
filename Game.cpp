//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), spriteLoader(), menu(), p1(), p2(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    spriteLoader.run();
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
        menu.renderGlobalMenu();

        //Rodar o menu

        //Se algo foi pressionado
       menu.run();
        /*healthy->run();*/
        //infected->run();


        window.menuEvents(&event);

        window.display();
    }
}