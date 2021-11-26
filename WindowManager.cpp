//
// Created by segalle on 03/11/2021.
//

#include "WindowManager.h"



WindowManager::WindowManager() :
sprites(),
x(WINDOW_WIDTH),
y(WINDOW_HEIGHT),
window(){
    window.create(sf::VideoMode(x, y), "Save Saps");
    window.setFramerateLimit(144);
    //view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    createView();
}

WindowManager::WindowManager(int width, int height) :
sprites(),
x(width),
y(height),
window(){
    if(width > 0 && height > 0) {
        window.create(sf::VideoMode(width, height), "Save Saps");
    }
    else{
        std::cout << "Not a valid window creation, reset to default size" << std::endl;
        x = 1280;
        y = 720;
        window.create(sf::VideoMode(x, y), "Save Saps");
    }
    window.setFramerateLimit(144);
    //view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
    createView();
}

WindowManager::~WindowManager(){}

bool WindowManager::isOpen() {
    return window.isOpen();
}

void WindowManager::draw(sf::Sprite* sprite) {
    window.draw(*sprite);
}

bool WindowManager::isOnView(sf::Sprite* sprite){
    float viewCenter = view.getCenter().x;
    float halfExtents = view.getSize().x / 2.0f;
    float viewMin = viewCenter - halfExtents;
    float viewMax = viewCenter + halfExtents;

    if ((sprite->getPosition().x + sprite->getGlobalBounds().width >= viewMin)  && (sprite->getPosition().x <= viewMax)){
        return true;
    }
    return false;
}

sf::View& WindowManager::getView() {
    return view;
}

void WindowManager::createView() {
    view.reset(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT));
}

void WindowManager::setView(const sf::View view){
    window.setView(view);
}

void WindowManager::clear() {
    window.clear();
}

void WindowManager::display() {
    window.display();
}