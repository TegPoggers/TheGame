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
    list<sf::Sprite> sprites;
    list<sf::Sprite>::iterator it;
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

    void menuEvents(sf::Event* event);

    bool pollEvent(sf::Event* event);

    sf::RenderWindow* getPtWindow() { return &window; }

};


#endif //JOGO_WINDOWMANAGER_H
