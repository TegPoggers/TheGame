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

public:
    WindowManager();

    WindowManager(int width, int height);

    ~WindowManager();

    void insertSprite(sf::Sprite texture);

    void render();

    bool isOpen();

    void draw(sf::Sprite* sprite);

    sf::RenderWindow* getPWindow();

};


#endif //JOGO_WINDOWMANAGER_H
