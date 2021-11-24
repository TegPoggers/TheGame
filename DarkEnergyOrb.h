//
// Created by segalle on 11/24/21.
//

#ifndef JOGO_DARKENERGYORB_H
#define JOGO_DARKENERGYORB_H

#include "Projectile.h"

namespace entities {

    class DarkEnergyOrb : public Projectile {

    public:

        DarkEnergyOrb();

        ~DarkEnergyOrb();

        void initializeStar();

    };

}

#endif //JOGO_DARKENERGYORB_H
