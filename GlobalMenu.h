//
// Created by viviane on 26/11/2021.
//

#ifndef JOGO_GLOBALMENU_H
#define JOGO_GLOBALMENU_H

#include "Menu.h"

namespace menus{

    class GlobalMenu : public Menu {

    public:

        GlobalMenu();

        ~GlobalMenu();

        //void run(sf::Event* event);

        void initialize();

        void run();



       // void run(sf::Event* event);



    };


}




#endif //JOGO_GLOBALMENU_H
