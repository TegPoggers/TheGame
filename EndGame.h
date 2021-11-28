//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_ENDGAME_H
#define JOGO_ENDGAME_H

#include "View.h"
#include <locale>

namespace menus{

    class EndGame : public View{

    private:
       std::string input_text;
       std::string player_name;
       // sf::Text iText("", font));
       sf::Clock clock;
       static sf::Time text_effect_time;
       static bool show_cursor;

    public:
        EndGame();
        ~EndGame();
        void run();
        void initialize();
        void setFinalVIew();
        void writeName();
    };
}


#endif //JOGO_ENDGAME_H
