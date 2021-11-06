//
// Created by segalle on 11/6/21.
//

#include "InputManager.h"

InputManager::InputManager() {}

InputManager::~InputManager() {}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    if(sf::Keyboard::isKeyPressed(key)){
        return true;
    }
    return false;
}

bool InputManager::isMouseClicked(sf::Mouse::Button click) {
    if(sf::Mouse::isButtonPressed(click)){
        return true;
    }
    return false;
}

bool InputManager::isSpriteClicked(sf::Sprite sprite, sf::RenderWindow *window, sf::Mouse::Button button) {
    if(sf::Mouse::isButtonPressed(button)){
        sf::IntRect box (sprite.getPosition().x, sprite.getPosition().y, sprite.getGlobalBounds().width, sprite.getGlobalBounds().height);

        if(box.contains(sf::Mouse::getPosition(*window))){
            return true;
        }
    }
    return false;
}