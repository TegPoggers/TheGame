//
// Created by david on 15/10/2021.
//

#include "InputManager.h"

namespace GameName{

    InputManager::InputManager() {

    }

    InputManager::~InputManager(){

    }

    bool InputManager::isSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow& window){
        if(sf::Mouse::isButtonPressed(button)) {
            sf::IntRect temp_rect(object.getPosition().x, object.getPosition().y, object.getGlobalBounds().width,
                                  object.getGlobalBounds().height);

            if (temp_rect.contains(sf::Mouse::getPosition(window))) {
                return true;
            }
        }
        return false;
    }

    sf::Vector2i InputManager::getMousePosition(sf::RenderWindow& window){
        return sf::Mouse::getPosition(window);
    }

}
