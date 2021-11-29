//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_LEADERBOARD_H
#define JOGO_LEADERBOARD_H

#include "View.h"
#include "ScoreBoard.h"

namespace menus {

    class LeaderBoard : public View{

    private:

        scoreboards::ScoreBoard scoreBoard;
        sf::Text names[SCORES_MAX];
        sf::Text scores[SCORES_MAX];


    public:


        LeaderBoard();

        ~LeaderBoard();

        void run();

        void initialize();

        void showAllScores();

    };

}


#endif //JOGO_LEADERBOARD_H
