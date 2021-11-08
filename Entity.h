//
// Created by segalle on 08/11/2021.
//

#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include "SFML/Graphics.hpp"
#include "WindowManager.h"

class Entity {

private:

    sf::Vector2f position;

    sf::Sprite* sprite;

    WindowManager* window;//Pode acabar virando uma struct

public:

    Entity();

    Entity(WindowManager* window);

    ~Entity();

    void setSprite(sf::Sprite* sprite);

    void draw();

    void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition();

    void setWindow(WindowManager* window);



};


#endif //JOGO_ENTITY_H
