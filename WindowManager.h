//
// Created by segalle on 03/11/2021.
//

#ifndef JOGO_WINDOWMANAGER_H
#define JOGO_WINDOWMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <iostream>
#include "Definitions.h"
using namespace std;


class WindowManager {

private:

    int x, y;
    sf::RenderWindow window;
    sf::View view;

public:

    WindowManager();

    WindowManager(int width, int height);

    ~WindowManager();

    bool isOpen();

    void draw(sf::Sprite* sprite);

    bool isOnView(sf::Sprite* sprite);

    sf::View &getView();

    void createView();

    void setView(sf::View view);

    void clear();

    void close();

    void display();

    void draw(sf::Text font);

    bool pollEvent(sf::Event* event);

};


#endif //JOGO_WINDOWMANAGER_H
