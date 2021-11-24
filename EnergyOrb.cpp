//
// Created by segalle on 11/24/21.
//

#include "EnergyOrb.h"

namespace entities{

    EnergyOrb::EnergyOrb() : Projectile() {
        initializeStar();
    }

    EnergyOrb::~EnergyOrb() {}

    void EnergyOrb::initializeStar() {
        speed = 2;
        damage = 30;
    }

}