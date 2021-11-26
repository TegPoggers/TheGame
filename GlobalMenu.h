//
// Created by viviane on 26/11/2021.
//

#ifndef JOGO_GLOBALMENU_H
#define JOGO_GLOBALMENU_H

#include "Menu.h"

namespace menus{

    class GlobalMenu : public Menu {
    private:


    public:
        GlobalMenu();
        ~GlobalMenu();
        void run();
        void initialize();
    };


}




#endif //JOGO_GLOBALMENU_H
