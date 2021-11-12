//
// Created by segalle on 08/11/2021.
//

#ifndef JOGO_MOVINGENTITY_H
#define JOGO_MOVINGENTITY_H

#include "Entity.h"

namespace entities {

    enum Direction{
        Left,
        Right
    };


    class MovingEntity : public Entity {

    protected:

        Direction direction;
        bool moving;

    public:

        MovingEntity();

        ~MovingEntity();

        const bool isMoving() const;

        virtual void run() = 0;

        virtual void move() = 0;

        void setMoving(bool moving);

        void setDirection(Direction direction);

        Direction getDirection();

    };

}

#endif //JOGO_MOVINGENTITY_H
