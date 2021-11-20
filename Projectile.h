//
// Created by segalle on 11/19/21.
//

#ifndef JOGO_PROJECTILE_H
#define JOGO_PROJECTILE_H

#include "Player.h"
using namespace characters;

namespace entities {
    class Projectile : public Entity{

    private:

        static float speed;
        static int damage;
        Player* creator;

    public:

        Projectile(Player* creator = NULL);

        ~Projectile();

        void run();

        int getDamage();

        void setDamage(int dmg);

        void setCreator(
                Player* creator);

        Entity* getCreator();

    };
}


#endif //JOGO_PROJECTILE_H
