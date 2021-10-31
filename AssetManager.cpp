//
// Created by david on 13/10/2021.
//

#include "AssetManager.h"

namespace GameName{

    AssetManager::AssetManager() {

    }

    AssetManager::~AssetManager() {

    }


    void AssetManager::LoadTexture(string name, string file_name) {
        sf::Texture tex;
        if(tex.loadFromFile(file_name)){
            texture[name]= tex;
        }
    }

    sf::Texture &AssetManager::GetTexture(string name) {
        return texture.at(name);
    }

    void AssetManager::LoadFont(string name, string file_name) {
        sf::Font f;
        if(f.loadFromFile(file_name)){
            font[name] = f;
        }
    }

    sf::Font &AssetManager::GetFont(string name) {
        return font.at(name);
    }


}