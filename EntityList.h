//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_ENTITYLIST_H
#define JOGO_ENTITYLIST_H

#include "List.h"
#include "Entity.h"

class EntityList {
private:
    List<entities::Entity> eList;

public:
    EntityList();
    ~EntityList();
    List<entities::Entity>* getList();
    int getLen();
    entities::Entity* getItem(int pos);
    void push(entities::Entity* entity);
    void pop(entities::Entity* entity);


};


#endif //JOGO_ENTITYLIST_H
