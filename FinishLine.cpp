//
// Created by segalle on 11/26/21.
//

#include "FinishLine.h"

namespace entities{

    FinishLine::FinishLine() {
        position = sf::Vector2f(DOOR_POSITION , 0);
        sprite = assets->getSprite("endLevelCastle");
        id = finish_line_id;
    }

    FinishLine::~FinishLine(){

    }

    void FinishLine::run(){}

    int FinishLine::getCollisionDamage() {
        return -1000;
    }

}