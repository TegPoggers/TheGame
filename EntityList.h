//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_ENTITYLIST_H
#define JOGO_ENTITYLIST_H

#include "List.h"
#include "Entity.h"

class EntityList {
public:
    List<entities::Entity> eList;
    EntityList();
    ~EntityList();
    List<entities::Entity>* getList();
};


#endif //JOGO_ENTITYLIST_H
