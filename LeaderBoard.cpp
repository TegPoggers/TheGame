//
// Created by viviane on 28/11/2021.
//

#include "LeaderBoard.h"


namespace menus{

    LeaderBoard::LeaderBoard(){   }


    LeaderBoard::~LeaderBoard(){   }

    void LeaderBoard::run(){
        renderMenu(LEADERBOARD_ITEMS);

        showAllScores();

        if (menu_counter > menu_speed) {
            if (inputs->isKeyPressed(controls.enter)) {
                switch (selectedItem) {
                    case 1:
                        setMenuState(st_global_menu, 0);
                        break;
                }
                menu_counter = 0;
            }
        }
        menu_counter++;
    }

    void LeaderBoard::initialize(){
        setBackground(assets->operator[]("menu"));
        loadFont();
        selectedItem = 1;

        text[0].setFont(*assets->getFont("fontOne"));
        text[0].setFillColor(sf::Color::White);
        text[0].setString("Leaderboard");
        text[0].setCharacterSize(150);
        text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

        text[1].setFont(*assets->getFont("fontThree"));
        text[1].setFillColor(sf::Color::Red);
        text[1].setString("Go to main menu");
        text[1].setCharacterSize(40);
        text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), WINDOW_HEIGHT - 70 - text[1].getGlobalBounds().height);

    }

    void LeaderBoard::showAllScores() {
        int i;
        int y_height = 170;

        scoreBoard.readScores();
        for (i = 0, scoreBoard.first(); !scoreBoard.ended() && i < 8; scoreBoard.next(), i++){

            names[i].setFont(*assets->getFont("fontThree"));
            names[i].setFillColor(sf::Color::White);
            names[i].setString(scoreBoard.getCurrent().name);
            names[i].setCharacterSize(40);
            names[i].setPosition((WINDOW_WIDTH/6 ) - 60,  y_height);
            window->draw(names[i]);

            scores[i].setFont(*assets->getFont("fontThree"));
            scores[i].setFillColor(sf::Color::White);
            scores[i].setString(std::to_string(scoreBoard.getCurrent().score));
            scores[i].setCharacterSize(40);
            scores[i].setPosition(WINDOW_WIDTH - (WINDOW_WIDTH/6) - scores[i].getGlobalBounds().width,y_height);
            y_height += 20 + names[i].getGlobalBounds().height;

            window->draw(scores[i]);
        }
    }
}
