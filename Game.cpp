//
// Created by segalle on 02/11/2021.
//

#include "Game.h"

Game::Game() : window(WINDOW_WIDTH, WINDOW_HEIGHT), assets(), spriteLoader(), p1(), p2(){
    Being::setAssetManager(&assets);
    Being::setWindowManager(&window);
    spriteLoader.run();
    healthy = new levels::HealthyForest(&p1, &p2);
    infected = new levels::InfectedForest(&p1, &p2);
    cout << "Construtora do Game" << endl;

    run();
}

Game::~Game() {

}

void Game::run(){

    //while(Being::getPWindow()->isOpen()){
    while(window.isOpen()){

        //Rodar o menu
        //Por enquanto chama a healthy
        healthy->run();
        //infected->run();
    }
}