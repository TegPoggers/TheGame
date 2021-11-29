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
        bool alive;

    public:

        Entity();

        virtual ~Entity();

        virtual void run() = 0;

        virtual int getCollisionDamage() = 0;

        const sf::Vector2f getPosition() const;

        void setPosition(sf::Vector2f position);
        void setPosition(float x, float y = 0);

        sf::Sprite* getSprite();

        void setSprite(sf::Sprite* sprite);

        float getFeetPosition();

        void setFeetPosition(float feet_position = 725);

        void die();

        bool getIsAlive();

        void move(sf::Vector2f amount);

        void setIsAlive(bool isAlive);

    };

}

#endif //JOGO_ENTITY_H