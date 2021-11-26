//
// Created by viviane on 25/11/2021.
//

#ifndef JOGO_MENU_H
#define JOGO_MENU_H

#include "Being.h"
#include <SFML/Graphics.hpp>

namespace menus{

    class Menu : Being{
    private:
        int selectedItem;
        sf::Text text[MENU_ITENS];
        sf::Sprite* background;
        sf::Vector2f backPosition;
        sf::Event event;

    public:
        Menu();
        ~Menu();

        void moveUp();
        void moveDown();
        void run();
        void setBackground(sf::Sprite* background);
        void setPosition(float x, float y);
        sf::Vector2f getPosition();
        void initialize();
        void renderGlobalMenu();
        void renderPlayersMenu();
        void loadFont();

    };


}



#endif //JOGO_MENU_H
