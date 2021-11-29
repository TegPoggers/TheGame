//
// Created by viviane on 28/11/2021.
//

#include "EndGame.h"

namespace menus{

    EndGame::EndGame() : View(), player_name(), score_board(){   }

    EndGame::~EndGame(){   }

    void EndGame::run(){
        setFinalVIew();
        renderMenu(PLAYER_MENU_ITENS);

        writeName();

        if (menu_counter > menu_speed) {
            if (inputs->isKeyPressed(controls.up)) {
                moveUp();
                menu_counter = 0;
            } else if (inputs->isKeyPressed(controls.down)) {
                moveDown();
                menu_counter = 0;
            } else if (inputs->isKeyPressed(controls.enter)) {
                switch (selectedItem) {
                    case 3:
                        saveOnTxt();
                        setMenuState(st_leader_board, 0);
                        break;
                }
                menu_counter = 0;
            }
        }
        menu_counter++;

        Being::setMenuState(0, 2);
    }


    void EndGame::initialize(){
        setBackground(assets->operator[]("menu"));
        loadFont();
        player_name = "@exemple";
        selectedItem = 2;

        text[0].setFont(*assets->getFont("fontOne"));
        text[0].setFillColor(sf::Color::White);
        text[0].setString("End Game");
        text[0].setCharacterSize(220);
        text[0].setPosition((WINDOW_WIDTH/2 - text[0].getGlobalBounds().width/2 ), -20);

        text[1].setFont(*assets->getFont("fontThree"));
        text[1].setFillColor(sf::Color::White);
        text[1].setString("Your name:");
        text[1].setCharacterSize(50);
        text[1].setPosition((WINDOW_WIDTH/2 - text[1].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) - 30 - text[1].getGlobalBounds().height);

        text[2].setFont(*assets->getFont("fontThree"));
        text[2].setFillColor(sf::Color::Red);
        text[2].setCharacterSize(50);
        text[2].setPosition((WINDOW_WIDTH/2 - text[2].getGlobalBounds().width/2 ), WINDOW_HEIGHT/2);

        text[3].setFont(*assets->getFont("fontThree"));
        text[3].setFillColor(sf::Color::White);
        text[3].setString("Save");
        text[3].setCharacterSize(50);
        text[3].setPosition((WINDOW_WIDTH/2 - text[3].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) + 30 + text[3].getGlobalBounds().height);

    }

    void EndGame::setFinalVIew() {
        window->setView(sf::View(sf::FloatRect(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT)));
    }

    void EndGame::writeName(){
        while (window->pollEvent(&event) && Being::getMenuState(0) != st_leader_board) {
            if (event.type == sf::Event::TextEntered) {
                if (std::isprint(event.text.unicode))
                    input_text += event.text.unicode;
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::BackSpace) {
                    if (!input_text.empty())
                        input_text.pop_back();
                }
            }
        }

        text_effect_time += clock.restart();

        if (text_effect_time >= sf::seconds(0.5f))
        {
            show_cursor = !show_cursor;
            text_effect_time = sf::Time::Zero;
        }

        player_name = input_text;
        player_name[player_name.size()] = '\0';
        text[2].setString(input_text + (show_cursor ? '_' : ' '));
        text[2].setPosition((WINDOW_WIDTH/2 - text[2].getGlobalBounds().width/2 ), WINDOW_HEIGHT/2);
        window->draw(text[2]);

    }

    void EndGame::saveOnTxt(){
        score_board.addScore(player_name, finalScore);
        score_board.saveScore();
        score_board.readScores();
    }


    sf::Time EndGame::text_effect_time = sf::Time();
    bool EndGame::show_cursor = false; //True -> mostra o underline


}