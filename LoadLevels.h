//
// Created by viviane on 27/11/2021.
//

#ifndef JOGO_LOADLEVELS_H
#define JOGO_LOADLEVELS_H

//#include "Game.h"
#include "Player.h"
#include "HealthyForest.h"
#include "InfectedForest.h"
#include "View.h"
using namespace entities::characters;

namespace menus{

    class LoadLevels : View {

    private:
        Player* p1;
        Player* p2;
        levels::HealthyForest* healthy;
        levels::InfectedForest* infected;
        sf::Event event;
        int levelState;
       // int finalScore;

    public:
        LoadLevels();
        ~LoadLevels();
        void initialize(Player* p1, Player* p2);
        void run();
        void renderLevels();
        void addScore();
        int getFinalScore();
    };

}



#endif //JOGO_LOADLEVELS_H
