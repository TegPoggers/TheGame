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
        cout << "State " << Being::getMenuState(0) << "  level state " << levelState << endl;

        while (Being::getMenuState(0) == levelState){
            window->clear();
            if (window->pollEvent(&event) && event.type == sf::Event::Closed){
                Being::setMenuState(st_quit_game, 0);
                break;
            }
            if (levelState == st_run_infected_forest){
                infected->run();
                if (infected->isFinished()){ //Considera o isFinished (tá pegando como se estivesse na posição da porta?)
                    cout << "Fase terminou???????????????????????" << endl;
                    renderLevels();
                }
            }
            else {
                healthy->run();
                if (healthy->isFinished()){
                    cout << "Fase terminou???????????????????????" << endl;
                    renderLevels();
                }
            }
            window->display();
        }
        //Somar pontuação ao finalScore
        addScore();
        Being::setMenuState(st_end_game, 0);
        //Verificar qual próxima fase (Comparar com o LevelState e jogadas) ou salvar pontuação
        //renderLevels(); //Faço o render levels fora do while, então não roda
    }

    //Problema está para passar de uma fase pra outra
    //Roda uma vez e leva pro end game
    void LoadLevels::renderLevels() {

        if (Being::getMenuState(2) < 2){
            if (levelState) {
                cout << "Era pra mudar de fase ------------------------------------ " << endl;
                if (levelState == st_run_healthy_forest){
                    Being::setMenuState(st_run_infected_forest, 0);
                   // healthy->setPlayersAlive(true);
                }
                else if (levelState == st_run_infected_forest){
                    Being::setMenuState(st_run_healthy_forest, 0);
                  //  infected->setPlayersAlive(true);
                }
            }

            if (Being::getMenuState(0) == st_run_infected_forest){
                Being::setMenuState((Being::getMenuState(2)+ 1), 2);
                cout << "Iniciei a infected --------------------------" << endl;
                levelState = st_run_infected_forest;
                infected = new levels::InfectedForest(p1, p2);
                cout << "Aloquei a infected --------------------------" << endl;
            } else {
                Being::setMenuState((Being::getMenuState(2)+ 1), 2);
                levelState = st_run_healthy_forest;
                healthy = new levels::HealthyForest(p1, p2);
            }

        }
        else {
            Being::setMenuState(st_end_game, 0);
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

    int LoadLevels::getFinalScore(){
        return finalScore;
    }


}