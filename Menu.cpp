//
// Created by viviane on 25/11/2021.
//

#include "Menu.h"

namespace menus {

    Menu::Menu() : Being() , text(), background(), backPosition(){
        selectedItem = 1;
    }

    Menu::~Menu(){

    }

    void Menu::run() {
       // window->draw(background);
       // renderGlobalMenu();


         switch (event.type) {
             //case sf::Event::Closed:
                 //window->close();
         }




    }

    void Menu::setBackground(sf::Sprite* background){
        this->background = background;
        this->background->setScale(GLOBAL_SCALE, GLOBAL_SCALE);
        setPosition(0,0);
    }

    void Menu::setPosition(float x, float y){
        backPosition.x = x;
        backPosition.y = y;
    }

    sf::Vector2f Menu::getPosition(){
        return backPosition;
    }


    void Menu::initialize(){
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
    }

    void Menu::renderGlobalMenu(){
        window->draw(background);
        for (int i = 0; i < MENU_ITENS; i++){
            window->draw(text[i]);
        }
    }

    void Menu::renderPlayersMenu(){

    }

    void Menu::loadFont() {
        assets->loadFont(FONT_1, "fontOne");
        assets->loadFont(FONT_3, "fontThree");
    }

    void Menu::moveUp(){
        if (selectedItem - 1 >= 1){
            text[selectedItem].setFillColor(sf::Color::White);
            selectedItem--;
            text[selectedItem].setFillColor(sf::Color::Red);
        }
    }


    void Menu::moveDown(){
        if (selectedItem + 1 < MENU_ITENS){
            text[selectedItem].setFillColor(sf::Color::White);
            selectedItem++;
            text[selectedItem].setFillColor(sf::Color::Red);
        }
    }

    sf::Event* Menu::event = nullptr;

}

