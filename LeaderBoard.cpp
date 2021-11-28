//
// Created by viviane on 28/11/2021.
//

#include "LeaderBoard.h"


namespace menus{

    LeaderBoard::LeaderBoard(){   }


    LeaderBoard::~LeaderBoard(){   }

    void LeaderBoard::run(){
        renderMenu(LEADERBOARD_ITEMS);
    }

    void LeaderBoard::initialize(){
        setBackground(assets->operator[]("menu"));
        loadFont();
        //player_name = "@exemple";
        selectedItem = 1;

        text[0].setFont(*assets->getFont("fontOne"));
        text[0].setFillColor(sf::Color::White);
        text[0].setString("Leaderboard");
        text[0].setCharacterSize(200);
        text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

        text[1].setFont(*assets->getFont("fontThree"));
        text[1].setFillColor(sf::Color::Red);
        text[1].setString("Go to main menu");
        text[1].setCharacterSize(50);
        text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), WINDOW_HEIGHT - 10 - text[1].getGlobalBounds().height);

    }
}
