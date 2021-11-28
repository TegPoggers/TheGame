//
// Created by segalle on 11/10/21.
//

#ifndef JOGO_BEING_H
#define JOGO_BEING_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "AssetManager.h"
#include "WindowManager.h"

enum id{
    player_id = 1,
    weak_goblin_id = 2,
    strong_goblin_id = 3,
    boss_goblin_id = 4,
    spikes_id = 5,
    fire_pit_id = 6,
    bush_id = 7,
    star_id = 8,
    dark_energy_orb_id = 9,
    energy_orb_id = 10,
    menu_id = 11,
    finish_line_id = 12
};

enum states_id{
    st_global_menu = 1,
    st_player_menu = 2,
    st_level_menu = 3,
    st_run_healthy_forest = 4,
    st_run_infected_forest = 5,
    st_leader_board = 6,
    st_quit_game = 7,
};

class Being {

protected:

    int id;
    static AssetManager* assets;
    static WindowManager* window;
    static int menu_state[STATES_NUMBER];

public:

    Being();

    virtual ~Being();

    virtual void run() = 0;

    void setId(int id);

    static void setAssetManager(AssetManager* asset) { assets = asset; }

    static void setWindowManager (WindowManager* wind) { window = wind; }

    const int getId();

    static WindowManager* getPWindow();

    static int getMenuState(int pos);

    static void setMenuState(int st, int position);

    bool operator==(int id);

};


#endif //JOGO_BEING_H
