//
// Created by viviane on 24/11/2021.
//

#ifndef JOGO_SPRITELOADER_H
#define JOGO_SPRITELOADER_H

#include "Being.h"

class SpriteLoader : public Being{
public:
    SpriteLoader();
    //SpriteLoader(AssetManager* assets, WindowManager* window);
    ~SpriteLoader();
    void run();
    void loadFailedTexture();
    void loadBackgrounds();
    void loadEnemies();
    void loadObstacles();
    void loadPlatforms();
    void loadPlayers();
    void loadProjectiles();
};


#endif //JOGO_SPRITELOADER_H
