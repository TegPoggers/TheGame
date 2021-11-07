//
// Created by segalle on 02/11/2021.
//

#include "AssetManager.h"


AssetManager::AssetManager() {}
AssetManager::~AssetManager(){}

void AssetManager::LoadSprite(std::string path, std::string name) {

    if(!texture.loadFromFile(path)){
        std::cout << "Missing file texture" << std::endl;
    }
    else{
        textures[name] = texture;
        sprite.setTexture(textures[name]);
        sprites[name] = sprite;
    }
}

sf::Sprite AssetManager::GetSprite(std::string name) {
    return sprites[name];
}

sf::Sprite AssetManager::operator[](std::string name) {
    //return &sprites["failed_tex"];
    return sprites[name];
}
