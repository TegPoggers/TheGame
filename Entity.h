//
// Created by segalle on 08/11/2021.
//

#ifndef JOGO_ENTITY_H
#define JOGO_ENTITY_H

#include "SFML/Graphics.hpp"
#include "WindowManager.h"
#include "Being.h"

namespace entities {

    class Entity : public Being {

    protected:

        sf::Vector2f position;
        sf::Sprite* sprite;

    public:

        Entity();

        ~Entity();

        virtual void run() = 0;

        virtual int getCollisionDamage() = 0;

        sf::Vector2f getPosition();

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y);

        sf::Sprite* getSprite();

        void setSprite(sf::Sprite* sprite);

    };

}

#endif //JOGO_ENTITY_H