//
// Created by segalle on 11/6/21.
//

#ifndef JOGO_INPUTMANAGER_H
#define JOGO_INPUTMANAGER_H

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

typedef struct {
    sf::Keyboard::Key jump;
    sf::Keyboard::Key left;
    sf::Keyboard::Key right;
    sf::Keyboard::Key shoot;
}Actions;

class InputManager {

public:

    InputManager();

    ~InputManager();

    void setLayout1();

    void setLayout2();

    virtual bool isKeyPressed(sf::Keyboard::Key key);

    virtual bool isMouseClicked(sf::Mouse::Button click);

    bool isSpriteClicked(sf::Sprite sprite, sf::RenderWindow* window, sf::Mouse::Button button);

};


#endif //JOGO_INPUTMANAGER_H
