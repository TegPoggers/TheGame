//
// Created by viviane on 26/11/2021.
//

#ifndef JOGO_GLOBALMENU_H
#define JOGO_GLOBALMENU_H

#include "View.h"
#include "PlayerMenu.h"

namespace menus{

    class GlobalMenu : public View {

    private:
        //leaderboard

    public:

        GlobalMenu();

        ~GlobalMenu();

        void initialize();

        void run();

    };


}




#endif //JOGO_GLOBALMENU_H
