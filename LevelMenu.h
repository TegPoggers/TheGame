//
// Created by viviane on 27/11/2021.
//

#ifndef JOGO_LEVELMENU_H
#define JOGO_LEVELMENU_H

#include "View.h"
#include "LoadLevels.h"
//#include "HealthyForest.h"
#include "InfectedForest.h"
using namespace levels;

namespace menus {


    class LevelMenu : public View{

    private:
        Player* p1;
        Player* p2;
        //HealthyForest* healthy;
        LoadLevels loadLevels;
        InfectedForest* infected;

    public:
        LevelMenu();
        ~LevelMenu();
        void run();
        void initialize(Player* p1, Player* p2);
    };
}


#endif //JOGO_LEVELMENU_H
