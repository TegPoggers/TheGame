//
// Created by segalle on 11/19/21.
//

#ifndef JOGO_PROJECTILE_H
#define JOGO_PROJECTILE_H

#include "Entity.h"
//#include "Player.h"
//using namespace entities::characters;



namespace entities {

    namespace characters{
        class Player;
    }

    class Projectile : public Entity{

    private:

        static float speed;
        static int damage;
        characters::Player* creator;
        int direction;

    public:

        Projectile(characters::Player* creator = nullptr);

        ~Projectile();

        void run();

        int getDamage();

        void setDamage(int dmg);

        void setCreator(characters::Player* creator);

        characters::Player* getCreator();

        void setDirection(int direction);

    };
}


#endif //JOGO_PROJECTILE_H
