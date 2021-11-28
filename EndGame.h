//
// Created by viviane on 28/11/2021.
//

#ifndef JOGO_ENDGAME_H
#define JOGO_ENDGAME_H

#include "View.h"

namespace menus{

    class EndGame : public View{

    private:

    public:
        EndGame();
        ~EndGame();
        void run();
        void initialize();
        void setFinalVIew();
    };
}


#endif //JOGO_ENDGAME_H
