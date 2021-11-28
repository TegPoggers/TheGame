//
// Created by viviane on 28/11/2021.
//

#include "LeaderBoard.h"


namespace menus{

    LeaderBoard::LeaderBoard(){   }


    LeaderBoard::~LeaderBoard(){   }

    void LeaderBoard::run(){
        renderMenu(LEADERBOARD_ITEMS);

        //For do txt para pegar dados
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
        //player_name = "@exemple";
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

        for (i = 0, scoreBoard.first(); (!scoreBoard.ended() || i < 10); scoreBoard.next(), i++){

            names[i].setFont(*assets->getFont("fontThree"));
            names[i].setFillColor(sf::Color::White);
            names[i].setString(scoreBoard.getCurrent().name);
            names[i].setCharacterSize(35);
            names[i].setPosition((WINDOW_WIDTH/6 ),  170 + (names[i].getGlobalBounds().height * i));
            window->draw(names[i]);

            scores[i].setFont(*assets->getFont("fontThree"));
            scores[i].setFillColor(sf::Color::White);
            scores[i].setString(std::to_string(scoreBoard.getCurrent().score));
            scores[i].setCharacterSize(35);
            //scores[i].setPosition(((WINDOW_WIDTH/6) * 2),  170 + (scores[i].getGlobalBounds().height * i));
            scores[i].setPosition((names[i].getPosition().x + names[i].getGlobalBounds().width + 50),170 + (scores[i].getGlobalBounds().height * i) );
            window->draw(scores[i]);
        }


    }
}
