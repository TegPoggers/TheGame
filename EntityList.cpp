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