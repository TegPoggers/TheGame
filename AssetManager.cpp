//
// Created by segalle on 02/11/2021.
//

#include "AssetManager.h"

namespace saveSaps{
    AssetManager::AssetManager() {}
    AssetManager::~AssetManager(){}

    void AssetManager::LoadSprite(std::string path, std::string name) {
        if(!texture.loadFromFile(path)){
            std::cout << "Missing file texture" << std::endl;
        }
        else{
            textures[name] =texture;
            sprite.setTexture(texture);
            sprites[name] = sprite;
        }
    }

    sf::Sprite AssetManager::GetSprite(std::string name) {
        return sprites[name];
    }

    sf::Sprite AssetManager::operator[](std::string name) {
        return sprites[name];
    }

}