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

WindowManager* Being::getPWindow() {
    return window;
}

int Being::getMenuState(int pos) {
    return menu_state[pos];
}

void Being::setMenuState(int st, int position){
    menu_state[position] = st;
}

bool Being::operator==(int id) {
    bool aux = false;
    this->id == id ? aux = true : aux = false;
    return aux;
}

AssetManager* Being::assets = nullptr;
WindowManager* Being::window = nullptr;
int Being::menu_state[STATES_NUMBER] = {1, 0};