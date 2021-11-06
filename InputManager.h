//
// Created by segalle on 11/6/21.
//

#ifndef JOGO_INPUTMANAGER_H
#define JOGO_INPUTMANAGER_H

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

class InputManager {
protected:

public:

    InputManager();

    ~InputManager();

    virtual bool isKeyPressed(sf::Keyboard::Key key);

    virtual bool isMouseClicked(sf::Mouse::Button click);

    bool isSpriteClicked(sf::Sprite sprite, sf::RenderWindow* window, sf::Mouse::Button button);

};


#endif //JOGO_INPUTMANAGER_H
