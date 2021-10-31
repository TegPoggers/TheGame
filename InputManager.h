//
// Created by david on 15/10/2021.
//

#ifndef JOGO_INPUTMANAGER_H
#define JOGO_INPUTMANAGER_H

#include <SFML/Graphics.hpp>

namespace GameName {

    class InputManager {

    public:
        InputManager();

        ~InputManager();

        //Serve pros menus
        bool isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window);

        sf::Vector2i getMousePosition(sf::RenderWindow& window);

    };

}


#endif //JOGO_INPUTMANAGER_H
