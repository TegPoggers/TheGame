//
// Created by segalle on 11/24/21.
//

#ifndef JOGO_ENERGYORB_H
#define JOGO_ENERGYORB_H

#include "Projectile.h"

namespace entities {

    class EnergyOrb : public Projectile {

    public:

        EnergyOrb();

        ~EnergyOrb();

        void initializeStar();

    };

}

#endif //JOGO_ENERGYORB_H
