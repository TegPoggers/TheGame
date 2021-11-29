//
// Created by viviane on 26/11/2021.
//

#ifndef JOGO_PLAYERMENU_H
#define JOGO_PLAYERMENU_H

#include "View.h"

using namespace entities::characters;

namespace menus{

    class PlayerMenu : public View{

    public:


        PlayerMenu();

        ~PlayerMenu();

        void run();

        void initialize();

    };

}


#endif //JOGO_PLAYERMENU_H
