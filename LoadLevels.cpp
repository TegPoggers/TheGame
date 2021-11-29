//
// Created by viviane on 27/11/2021.
//

#include "LoadLevels.h"

namespace menus{

    LoadLevels::LoadLevels() : View(), p1(), p2(), healthy(), levelState(0){ }

    LoadLevels::~LoadLevels(){    }

    void LoadLevels::initialize(Player* p1, Player* p2){
        this->p1 = p1;
        this->p2 = p2;

        renderLevels();

        run();
    }

    void LoadLevels::run(){
        while (Being::getMenuState(0) == levelState){
            window->clear();
            if (window->pollEvent(&event) && event.type == sf::Event::Closed){
                Being::setMenuState(st_quit_game, 0);
                break;
            }
            if (levelState == st_run_infected_forest){
                infected->run();
                if (infected->isFinished()){
                    renderLevels();
                }
            }
            else {
                healthy->run();
                if (healthy->isFinished()){
                    renderLevels();
                }
            }
            window->display();
        }
        addScore();
        Being::setMenuState(st_end_game, 0);
    }

    void LoadLevels::renderLevels() {
        int players = Being::getMenuState(1);

        if (Being::getMenuState(2) < 2){
            if (levelState) {
                if (levelState == st_run_healthy_forest)
                    Being::setMenuState(st_run_infected_forest, 0);
                else if (levelState == st_run_infected_forest)
                    Being::setMenuState(st_run_healthy_forest, 0);
            }

            if (Being::getMenuState(0) == st_run_infected_forest){
                Being::setMenuState((Being::getMenuState(2)+ 1), 2);
                levelState = st_run_infected_forest;
                infected = new levels::InfectedForest(p1, p2);
            } else {
                Being::setMenuState((Being::getMenuState(2)+ 1), 2);
                levelState = st_run_healthy_forest;
                healthy = new levels::HealthyForest(p1, p2);
            }

        }
        else {
            Being::setMenuState(st_end_game, 0);
            Being::setMenuState(players, 1);
        }
    }

    void LoadLevels::addScore() {
        if (levelState == st_run_healthy_forest){
            finalScore = healthy->getScore();
        }
        else if (levelState == st_run_infected_forest) {
            finalScore = infected->getScore();
        }
    }
}