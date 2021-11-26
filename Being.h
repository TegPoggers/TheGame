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
    menu_id = 10
};

class Being {

protected:

    int id;
    static AssetManager* assets;
    static WindowManager* window;

public:

    Being();

    virtual ~Being();

    virtual void run() = 0;

    void setId(int id);

    static void setAssetManager(AssetManager* asset) { assets = asset; }

    static void setWindowManager (WindowManager* wind) { window = wind; }

    const int getId();

    static WindowManager* getPWindow();

};


#endif //JOGO_BEING_H
