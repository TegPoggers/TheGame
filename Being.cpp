//
// Created by segalle on 11/10/21.
//

#include "Being.h"

Being::Being() :
id(0)
{}

Being::~Being()
{}

void Being::setId(int id) {
    this->id = id;
}

const int Being::getId() {
    return id;
}

