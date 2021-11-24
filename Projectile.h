//
// Created by segalle on 11/19/21.
//

#ifndef JOGO_PROJECTILE_H
#define JOGO_PROJECTILE_H

#include "Entity.h"
//#include "Player.h"
//using namespace entities::characters;


namespace entities {

    class Projectile : public Entity{

    protected:

        float speed;
        int damage;
        int direction;

    public:

        Projectile();

        ~Projectile();

        void run();

        int getDamage();

        void setDamage(int dmg);

        void setDirection(int direction);

        int getCollisionDamage();

    };
}

#endif //JOGO_PROJECTILE_H
