//
// Created by segalle on 11/10/21.
//

#ifndef JOGO_BEING_H
#define JOGO_BEING_H

#include <SFML/Graphics.hpp>
#include "Definitions.h"
#include "AssetManager.h"
#include "WindowManager.h"

class Being {

protected:

    int id;
    static AssetManager* assets;
    static WindowManager* window;

public:

    Being();

    ~Being();

    virtual void run() = 0;

    void setId(int id);

    static void setAssetManager(AssetManager* asset) { assets = asset; }

    static void setWindowManager (WindowManager* wind) { window = wind; }

    const int getId();

    static WindowManager* getPWindow();

};


#endif //JOGO_BEING_H
