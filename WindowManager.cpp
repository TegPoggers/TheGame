//
// Created by segalle on 03/11/2021.
//

#include "WindowManager.h"



WindowManager::WindowManager() :
sprites(),
x(1280),
y(720),
window(){
    window.create(sf::VideoMode(x, y), "Save Saps");
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
}

WindowManager::~WindowManager(){}

void WindowManager::insertSprite(sf::Sprite sprite) {
    if(sprite.getTexture() != NULL){
        sprites.push_back(sprite);
    }
}

void WindowManager::render() {
    window.clear();

    if(!sprites.empty()){
        for(it = sprites.begin(); it != sprites.end(); it++){
            window.draw(*it);
            sf::Vector2f pos;
            pos.x = 0.1; pos.y = 0.1;
            it->move(pos);cout << sprites.begin()->getPosition().x << endl;
        }

        //Event manager
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    window.display();
}

bool WindowManager::isOpen() {
    return window.isOpen();
}

void WindowManager::draw(sf::Sprite* sprite) {
    window.draw(*sprite);
}
