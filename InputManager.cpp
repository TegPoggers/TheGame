//
// Created by segalle on 11/6/21.
//

#include "InputManager.h"

InputManager::InputManager() {}

InputManager::~InputManager() {}

Actions InputManager::setLayout1() {
    Actions key_package;
    key_package.jump = sf::Keyboard::W;
    key_package.left = sf::Keyboard::A;
    key_package.right = sf::Keyboard::D;
    key_package.shoot = sf::Keyboard::Space;

    return key_package;
}

Actions InputManager::setLayout2() {
    Actions key_package;
    key_package.jump = sf::Keyboard::Up;
    key_package.left = sf::Keyboard::Left;
    key_package.right = sf::Keyboard::Right;
    key_package.shoot = sf::Keyboard::Enter;

    return key_package;
}

bool InputManager::isKeyPressed(sf::Keyboard::Key key) {
    if(sf::Keyboard::isKeyPressed(key)){
        return true;
    }
    return false;
}
