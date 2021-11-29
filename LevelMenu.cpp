//
// Created by viviane on 27/11/2021.
//

#include "LevelMenu.h"

namespace menus{

    LevelMenu::LevelMenu() : View(), p1(), p2(), loadLevels(){
    }

    LevelMenu::~LevelMenu(){

    }

    void LevelMenu::run(){
        renderMenu(PLAYER_MENU_ITENS);
        if (menu_counter > menu_speed) {
            if (inputs->isKeyPressed(controls.up)) {
                moveUp();
                menu_counter = 0;
            } else if (inputs->isKeyPressed(controls.down)) {
                moveDown();
                menu_counter = 0;
            } else if (inputs->isKeyPressed(controls.enter)) {
                switch (selectedItem) {
                    case 1:
                        setMenuState(st_run_healthy_forest, 0);
                        loadLevels.initialize(p1, p2);
                        break;
                    case 2:
                        setMenuState(st_run_infected_forest, 0);
                        loadLevels.initialize(p1, p2);
                        break;
                    case 3:
                        setMenuState(st_player_menu, 0);
                        break;
                }
                menu_counter = 0;
            }
        }
        menu_counter++;
    }

    void LevelMenu::initialize(Player* p1, Player* p2){
        setBackground(assets->operator[]("menu"));
        loadFont();

        this->p1 = p1;
        this->p2 = p2;
        selectedItem = 1;

        text[0].setFont(*assets->getFont("fontOne"));
        text[0].setFillColor(sf::Color::White);
        text[0].setString("Save Saps");
        text[0].setCharacterSize(220);
        text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

        text[1].setFont(*assets->getFont("fontThree"));
        text[1].setFillColor(sf::Color::Red);
        text[1].setString("Level One");
        text[1].setCharacterSize(50);
        text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) - 30 - text[1].getGlobalBounds().height);

        text[2].setFont(*assets->getFont("fontThree"));
        text[2].setFillColor(sf::Color::White);
        text[2].setString("Level Two");
        text[2].setCharacterSize(50);
        text[2].setPosition((WINDOW_WIDTH/2 - text[2].getGlobalBounds().width/2 ), WINDOW_HEIGHT/2);

        text[3].setFont(*assets->getFont("fontThree"));
        text[3].setFillColor(sf::Color::White);
        text[3].setString("Return");
        text[3].setCharacterSize(50);
        text[3].setPosition((WINDOW_WIDTH/2 - text[3].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) + 30 + text[3].getGlobalBounds().height);

    }


}