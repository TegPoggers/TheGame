//
// Created by segalle on 08/11/2021.
//

#ifndef JOGO_MOVINGENTITY_H
#define JOGO_MOVINGENTITY_H

#include "Entity.h"

class MovingEntity : public Entity {

protected:

    bool moving;

public:

    MovingEntity();

    ~MovingEntity();

    const bool isMoving() const;

    virtual void runPhysics() = 0;

    virtual void move() = 0;

    void setMoving(bool moving);

};


#endif //JOGO_MOVINGENTITY_H
