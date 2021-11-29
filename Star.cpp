//
// Created by segalle on 11/24/21.
//

#include "Star.h"

namespace entities{

    Star::Star() : Projectile(){
        initializeStar();
    }

    Star::~Star(){}

    void Star::initializeStar(){
        damage = 40;
        speed = 7;
        sprite = assets->getSprite("playerOrb");
        id = star_id;
    }

}
