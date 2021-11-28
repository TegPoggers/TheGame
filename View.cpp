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


   /* void View::initialize(){
        setBackground(assets->operator[]("menu"));
        loadFont();

        selectedItem = 1;

        text[0].setFont(*assets->getFont("fontOne"));
        text[0].setFillColor(sf::Color::White);
        text[0].setString("Save Saps");
        text[0].setCharacterSize(220);
        text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

        text[1].setFont(*assets->getFont("fontThree"));
        text[1].setFillColor(sf::Color::Red);
        text[1].setString("Level 1");
        text[1].setCharacterSize(50);
        text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) - 30 - text[1].getGlobalBounds().height);

        text[2].setFont(*assets->getFont("fontThree"));
        text[2].setFillColor(sf::Color::White);
        text[2].setString("Level 2");
        text[2].setCharacterSize(50);
        text[2].setPosition((WINDOW_WIDTH/2 - text[2].getGlobalBounds().width/2 ), WINDOW_HEIGHT/2);

        text[3].setFont(*assets->getFont("fontThree"));
        text[3].setFillColor(sf::Color::White);
        text[3].setString("Quit Game");
        text[3].setCharacterSize(50);
        text[3].setPosition((WINDOW_WIDTH/2 - text[3].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) + 20 + text[3].getGlobalBounds().height);
    }*/

    void View::renderMenu(int items){
        window->draw(background);
        for (int i = 0; i < items; i++){
            window->draw(text[i]);
        }
    }

    void View::renderPlayersMenu(){

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

    int View::GetPressedItem(){
        return selectedItem;
    }

    void View::runEvent(sf::Event* event) {
        renderMenu(MENU_ITENS);
        if (event->type == sf::Event::KeyReleased) {

            if (event->key.code == controls.up) {
                moveUp();
            } else if (event->key.code == controls.down) {
                moveDown();
            } else if (event->key.code == controls.enter) {
                run();
            }
        }
    }
    int View::menu_speed = 72;
    int View::finalScore = 0;

}





