//
// Created by segalle on 11/19/21.
//

#ifndef JOGO_PROJECTILE_H
#define JOGO_PROJECTILE_H

#include "Entity.h"

namespace entities {

    class Projectile : public Entity{

    protected:

        float speed;
        int damage;
        int direction;

    public:

        Projectile();

        virtual ~Projectile();

        void run();

        void setDamage(int dmg);

        void setDirection(int direction);

        int getCollisionDamage();

    };
}

#endif //JOGO_PROJECTILE_H
