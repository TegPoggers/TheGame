//
// Created by viviane on 24/11/2021.
//

#include "SpriteLoader.h"

SpriteLoader::SpriteLoader() {

}

SpriteLoader::~SpriteLoader() {

}

void SpriteLoader::run() {

    loadFailedTexture();

    loadBackgrounds();

    loadEnemies();

    loadObstacles();

    loadPlayers();

    loadProjectiles();

    loadFinishLine();

}

void SpriteLoader::loadFailedTexture(){
    assets->loadSprite(FAILED_TEXTURE, "failedTexture");
}

void SpriteLoader::loadBackgrounds() {
    assets->loadSprite(HEALTHY_FOREST, "healthyForest");
    assets->loadSprite(INFECTED_FOREST, "infectedForest");
    assets->loadSprite(MENU_BACKGROUND, "menu");

}

void SpriteLoader::loadEnemies(){
    assets->loadSprite(WEAK_GOBLIN, "weakGoblin");
    assets->loadSprite(STRONG_GOBLIN, "strongGoblin");
    assets->loadSprite(BOSS_GOBLIN, "bossGoblin");
}


void SpriteLoader::loadObstacles(){
    assets->loadSprite(SPIKES_PATH,"spikes");
    assets->loadSprite(POINTY_BUSH,"pointyBush");
    assets->loadSprite(FIRE_PIT,"firePit");
}

void SpriteLoader::loadPlayers(){
    assets->loadSprite(PLAYER_1,"player1");
    assets->loadSprite(PLAYER_2,"player2");
}

void SpriteLoader::loadProjectiles(){
    assets->loadSprite(PLAYER_ORB, "playerOrb");
    assets->getSprite("playerOrb")->setScale(0.5, 0.5);

    assets->loadSprite(DARK_ENERGY_ORB, "darkEnergyOrb");
    assets->loadSprite(ENERGY_ORB, "energyOrb");
}

void SpriteLoader::loadFinishLine() {
    assets->loadSprite(END_LEVEL_CASTLE, "endLevelCastle");
    assets->getSprite("endLevelCastle")->setScale(0.1, 0.1);
}