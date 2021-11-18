//
// Created by segalle on 08/11/2021.
//

#ifndef JOGO_MOVINGENTITY_H
#define JOGO_MOVINGENTITY_H

#include "Entity.h"

namespace entities {
    namespace characters {

        enum Direction {
            Left,
            Right
        };

        class MovingEntity : public Entity {

        protected:

            int direction;
            sf::Vector2f speed;
            int lives;

        public:

            MovingEntity();

            ~MovingEntity();

            virtual void run() = 0;


            virtual void move(sf::Vector2f) = 0;

            int getDirection();

            void setLives(int life);

            void loseLives();

            int getLives();

            const sf::Vector2f getSpeed() const;

            void setSpeed(sf::Vector2f speed);

            void addSpeed(sf::Vector2f acceleration);

        };
    }
}

#endif //JOGO_MOVINGENTITY_H
