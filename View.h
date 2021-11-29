//
// Created by viviane on 25/11/2021.
//

#ifndef JOGO_VIEW_H
#define JOGO_VIEW_H

#include "Player.h"
#include "Being.h"
#include "InputManager.h"
#include <SFML/Graphics.hpp>

using namespace entities::characters;

namespace menus{

    class View : public Being{
    protected:

        int selectedItem;
        sf::Text text[MENU_ITENS];
        sf::Sprite* background;
        sf::Vector2f backPosition;
        sf::Event event;
        InputManager *inputs;
        Controls controls;
        static int menu_speed;
        int menu_counter;
        static int finalScore;


    public:

        View();
        ~View();


        void moveUp();

        void moveDown();

        void setBackground(sf::Sprite* background);

        void setPosition(float x, float y);

        sf::Vector2f getPosition();

        void renderMenu(int items);

        void loadFont();

    };

}

#endif //JOGO_VIEW_H
