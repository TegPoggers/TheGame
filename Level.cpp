//
// Created by viviane on 18/11/2021.
//

#include "Level.h"

namespace levels{


    Level::Level(Player* p1){
        entityList = new EntityList();
        //Aloca inimigos
        initializeElements();
    }

    Level::~Level(){

    }

    void Level::initializeElements(){
        entityList->eList.push(p1);
    }

}