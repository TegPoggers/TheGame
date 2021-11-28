//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_LEADERBOARD_H
#define JOGO_LEADERBOARD_H

#include "View.h"

namespace menus {

    class LeaderBoard : public View{

    public:
        LeaderBoard();
        ~LeaderBoard();
        void run();
        void initialize();
    };

}


#endif //JOGO_LEADERBOARD_H
