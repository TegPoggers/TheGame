//
// Created by segalle on 11/24/21.
//

#include "Star.h"

namespace entities{

    Star::Star() : Projectile(),
    creator(nullptr){
        initializeStar();
    }

    Star::Star(characters::Player* creator, int direction) : Projectile(),
    creator(creator){
        this->direction = direction;
        initializeStar();
    }

    Star::~Star(){}

    void Star::setCreator(characters::Player *creator) {
        this->creator = creator;
    }

    void Star::initializeStar(){
        damage = 40;
        speed = 7;
        assets->LoadSprite(PLAYER_ORB_PATH, "playerOrb");
        sprite = assets->getSprite("playerOrb");
    }

}
