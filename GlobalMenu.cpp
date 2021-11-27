//
// Created by viviane on 26/11/2021.
//

#include "GlobalMenu.h"

namespace menus{

    GlobalMenu::GlobalMenu() : Menu(){  }

    GlobalMenu::~GlobalMenu(){   }

    /*void GlobalMenu::run(sf::Event* event){

    cout << "To no run " << endl;
        //switch (event.type) {
          //   case :
         //}


    }*/

    void GlobalMenu::run(){
        renderMenu(GLOBAL_MENU_ITENS);
        //Receber um ponteiro pro evento

        cout << "Tô no run " << endl;
        //setMenuState(st_run_healthy_forest_p2);
        cout << "State " << Being::getMenuState(0) << endl;
            //sf::Event event;
            cout << "Teve evento?" << endl;

            /*if (inputs->isKeyPressed(controls.up)){
                moveUp();
            } else if (inputs->isKeyPressed(controls.down)){
                moveDown();
            } else if (inputs->isKeyPressed(controls.enter)){
                switch (selectedItem) {
                    case 1:
                        cout << "Case 1" << endl;
                        setMenuState(st_player_menu, 0);
                       // setMenuState(st_run_healthy_forest, 1);
                       //chamar o menu players
                       break;
                    case 2:
                        cout << "Case 2" << endl;
                        setMenuState(st_player_menu, 0);
                        //setMenuState(st_run_infected_forest,  1);
                        break;
                    case 3:
                        cout << "Case 3" << endl;
                        setMenuState(st_quit_game, 0);
                        break;
                }
            }*/
//Daqui
           if (menu_counter > menu_speed){// && event.type == sf::Event::KeyReleased){

                if (inputs->isKeyPressed(controls.up)){
                    moveUp();
                    menu_counter = 0;
                } else if (inputs->isKeyPressed(controls.down)){
                    moveDown();
                    menu_counter = 0;
                } else if (inputs->isKeyPressed(controls.enter)){
                    switch (selectedItem) {
                        case 1:
                            cout << "Case 1" << endl;
                            setMenuState(st_player_menu, 0);
                            setMenuState(st_run_healthy_forest, 1);
                            //chamar o menu players
                            break;
                        case 2:
                            cout << "Case 2" << endl;
                            setMenuState(st_player_menu, 0);
                            setMenuState(st_run_infected_forest,  1);
                            break;
                        case 3:
                            cout << "Case 3" << endl;
                            setMenuState(st_quit_game, 0);
                            break;
                    }
                    menu_counter = 0;
                }
           }
           menu_counter++;
//Até aqui

    }

    void GlobalMenu::initialize(){
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
        text[3].setPosition((WINDOW_WIDTH/2 - text[3].getGlobalBounds().width/2 ), (WINDOW_HEIGHT / 2) + 30 + text[3].getGlobalBounds().height);
    }


}