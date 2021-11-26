//
// Created by segalle on 11/24/21.
//

#include "DarkEnergyOrb.h"

namespace entities{

    DarkEnergyOrb::DarkEnergyOrb() : Projectile() {
        initializeStar();
    }

    DarkEnergyOrb::~DarkEnergyOrb() {}

    void DarkEnergyOrb::initializeStar() {
        speed = 2;
        damage = 5;
        sprite = assets->getSprite("darkEnergyOrb");
        id = 9;
    }

}