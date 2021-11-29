//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_ENDGAME_H
#define JOGO_ENDGAME_H

#include "View.h"
#include <locale>
#include "ScoreBoard.h"


namespace menus{

    class EndGame : public View{

    private:

       std::string input_text;
       std::string player_name;
       sf::Clock clock;
       static sf::Time text_effect_time;
       static bool show_cursor;
       scoreboards::ScoreBoard score_board;

    public:

        EndGame();

        ~EndGame();

        void run();

        void initialize();

        void setFinalVIew();

        void writeName();

        void saveOnTxt();
    };
}


#endif //JOGO_ENDGAME_H
