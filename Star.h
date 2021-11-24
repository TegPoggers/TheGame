//
// Created by segalle on 11/24/21.
//

#ifndef JOGO_STAR_H
#define JOGO_STAR_H

#include "Projectile.h"

namespace entities {

    namespace characters{
        class Player;
    }

    class Star : public Projectile {

    private:

        characters::Player* creator;

    public:

        Star();

        Star(characters::Player* creator, int direction = 1);

        ~Star();

        void setCreator(characters::Player* creator);

        void initializeStar();

    };

}

#endif //JOGO_STAR_H
