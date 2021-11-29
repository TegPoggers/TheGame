//
// Created by viviane on 25/11/2021.
//

#include "View.h"

namespace menus {

    View::View() : Being() , text(), background(), backPosition(), inputs(nullptr), controls(){
        selectedItem = 1;
        menu_counter = 0;
        inputs = new InputManager();
    }

    View::~View(){

    }

    void View::setBackground(sf::Sprite* background){
        this->background = background;
        this->background->setScale(GLOBAL_SCALE, GLOBAL_SCALE);
        setPosition(0,0);
    }

    void View::setPosition(float x, float y){
        backPosition.x = x;
        backPosition.y = y;
    }

    sf::Vector2f View::getPosition(){
        return backPosition;
    }

    void View::renderMenu(int items){
        window->draw(background);
        for (int i = 0; i < items; i++){
            window->draw(text[i]);
        }
    }

    void View::loadFont() {
        assets->loadFont(FONT_1, "fontOne");
        assets->loadFont(FONT_3, "fontThree");
    }

    void View::moveUp(){
        if (selectedItem - 1 >= 1){
            text[selectedItem].setFillColor(sf::Color::White);
            selectedItem--;
            text[selectedItem].setFillColor(sf::Color::Red);
        }
    }


    void View::moveDown(){
        if (selectedItem + 1 < MENU_ITENS){
            text[selectedItem].setFillColor(sf::Color::White);
            selectedItem++;
            text[selectedItem].setFillColor(sf::Color::Red);
        }
    }

    int View::menu_speed = 72;
    int View::finalScore = 0;

}





