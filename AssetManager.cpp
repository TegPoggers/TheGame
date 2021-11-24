//
// Created by segalle on 02/11/2021.
//

#include "AssetManager.h"


AssetManager::AssetManager():
        sprite(nullptr),
        texture(nullptr),
        font(nullptr),
        sprites(),
        textures(),
        fonts()
{
    printf("to no Assets"); // Teste da textura (23/11)
}
AssetManager::~AssetManager() {

    for(itF = fonts.begin();itF != fonts.end(); itF++){
        font = itF->second;
        delete font;
        font = NULL;
        fonts.erase(itF);
    }
    fonts.clear();

    for(itT = textures.begin();itT != textures.end(); itT++){
        texture = itT->second;
        delete texture;
        texture = NULL;
        textures.erase(itT);
    }
    textures.clear();

    for(itS = sprites.begin(); itS != sprites.end(); itS++){
        sprite = itS->second;
        delete sprite;
        sprite = NULL;
        sprites.erase(itS);
    }
    sprites.clear();

}

void AssetManager::LoadSprite(std::string path, std::string name) {

    texture = new sf::Texture();

    if (!texture->loadFromFile(path)) {
        std::cout << "Missing file texture" << std::endl;
        delete texture;

    }
    else {
        textures[name] = texture;

        sprite = new sf::Sprite();
        sprite->setTexture(*textures[name]);

        sprites[name] = sprite;
    }

}

sf::Sprite* AssetManager::getSprite(std::string name) {
    return sprites[name];
}

sf::Sprite* AssetManager::operator[](std::string name) {
    return sprites[name];
}

void AssetManager::setScale(std::string name, sf::Vector2f absolute_multiplyer) {
    if(sprites[name]) {
        sprite = sprites[name];
        sprite->setScale(absolute_multiplyer);
    }
}

void AssetManager::scale(std::string name, sf::Vector2f multiplier) {
    if(sprites[name]){
        sprite = sprites[name];
        sprite->scale(multiplier);
    }
}