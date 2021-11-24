//
// Created by segalle on 11/23/21.
//

#ifndef JOGO_STATICENTITY_H
#define JOGO_STATICENTITY_H

#include "Entity.h"

namespace entities {

    class StaticEntity : public Entity {

    private:

    public:

        StaticEntity();

        ~StaticEntity();

        virtual void run() = 0;

        virtual int getCollisionDamage() = 0;

    };

}

#endif //JOGO_STATICENTITY_H
