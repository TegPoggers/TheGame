//
// Created by viviane on 18/11/2021.
//

#include "EntityList.h"

EntityList::EntityList() : eList(){

}

EntityList::~EntityList(){

}

List<entities::Entity> *EntityList::getList() {
    return &eList;
}

int EntityList::getLen(){
    return eList.getLen();
}

entities::Entity* EntityList::getItem(int pos){
    return eList.getItem(pos);
}

void EntityList::push(entities::Entity* entity){
    eList.push(entity);
}

void EntityList::pop(entities::Entity* entity){
    eList.pop(entity);
}