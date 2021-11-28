//
// Created by viviane on 27/11/2021.
//

#include "LoadLevels.h"

namespace menus{

    LoadLevels::LoadLevels() : Being(), p1(), p2(), healthy() { }

    LoadLevels::~LoadLevels(){    }

    void LoadLevels::initialize(Player* p1, Player* p2){
        this->p1 = p1;
        this->p2 = p2;
        renderLevels();

        run();
    }

    void LoadLevels::run(){
        while (getMenuState(0) == levelState){
            window->clear();
            if (window->pollEvent(&event) && event.type == sf::Event::Closed){
                Being::setMenuState(st_quit_game, 0);
                break;
            }
            if (levelState == st_run_infected_forest){
                infected->run();
            }
            else {
                healthy->run();
            }
            window->display();
        }
    }

    void LoadLevels::renderLevels() {

        if (Being::getMenuState(0) == st_run_infected_forest){
            levelState = st_run_infected_forest;
            infected = new levels::InfectedForest(p1, p2);
        } else {
            levelState = st_run_healthy_forest;
            healthy = new levels::HealthyForest(p1, p2);
        }
    }

}