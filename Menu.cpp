//
// Created by viviane on 25/11/2021.
//

#include "Menu.h"

Menu::Menu(){ }

Menu::~Menu(){

}

void Menu::moveUp(){

}

void Menu::moveDown(){

}

void Menu::run() {
    window->draw(background);
    renderGlobalMenu();
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
    text[0].setFont(*assets->getFont("fontOne"));
    //text[0].setColor(sf::Color::White);
    text[0].setString("Save Saps");
    text[0].setCharacterSize(220);
    text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

    //text[1].setFont(*assets->getFont("fontOne"));
    text[1].setFont(*assets->getFont("fontThree"));
    //text[1].setColor(sf::Color::White);
    text[1].setString("Level 1");
    //text[1].setCharacterSize(100);
    text[1].setCharacterSize(50);
    text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / MENU_ITENS) + 20);

    
    //text[2].setFont(*assets->getFont("fontOne"));
    text[2].setFont(*assets->getFont("fontThree"));
    //text[2].setColor(sf::Color::White);
    text[2].setString("Level 2");
    //text[2].setCharacterSize(100);
    text[2].setCharacterSize(50);
    text[2].setPosition((WINDOW_WIDTH/2 - text[2].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / MENU_ITENS - 1) + 20 );

    //text[3].setFont(*assets->getFont("fontOne"));
   /* text[3].setFont(*assets->getFont("fontThree"));
    //text[3].setColor(sf::Color::White);
    text[3].setString("Quit Game");
    //text[3].setCharacterSize(100);
    text[3].setCharacterSize(50);
    text[3].setPosition((WINDOW_WIDTH/2 - text[3].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / MENU_ITENS) + 20);*/
}

void Menu::renderGlobalMenu(){
    window->draw(text[0]);
    window->draw(text[1]);
    window->draw(text[2]);
   // window->draw(text[3]);


}

void Menu::renderPlayersMenu(){

}

void Menu::loadFont() {
    assets->loadFont(FONT_1, "fontOne");
    assets->loadFont(FONT_3, "fontThree");

}