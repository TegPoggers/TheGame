//
// Created by viviane on 24/11/2021.
//

#ifndef JOGO_SPRITELOADER_H
#define JOGO_SPRITELOADER_H

#include "Being.h"

class SpriteLoader : public Being{
public:

    SpriteLoader();

    ~SpriteLoader();

    void run();

    void loadFailedTexture();

    void loadBackgrounds();

    void loadEnemies();

    void loadObstacles();

    void loadPlayers();

    void loadProjectiles();

    void loadFinishLine();

};


#endif //JOGO_SPRITELOADER_H
