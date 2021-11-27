//
// Created by viviane on 26/11/2021.
//

#ifndef JOGO_PLAYERMENU_H
#define JOGO_PLAYERMENU_H

#include "Menu.h"
#include "Player.h"
using namespace entities::characters;

namespace menus{

    class PlayerMenu : public Menu{

    private:
        bool onePlayer;
        Player* p2;

    public:
        PlayerMenu();
        ~PlayerMenu();
        void run();
        bool isOnePlayer();
        void initialize(Player* p2);

    };

}


#endif //JOGO_PLAYERMENU_H
