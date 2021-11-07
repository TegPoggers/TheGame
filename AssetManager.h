//
// Created by segalle on 02/11/2021.
//

#ifndef JOGO_ASSETMANAGER_H
#define JOGO_ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <string>
#include <iostream>


class AssetManager {
private:
    std::map<std::string, sf::Sprite> sprites;
    std::map<std::string, sf::Font*> fonts;
    std::map<std::string, sf::Texture> textures;

    sf::Texture texture;
    sf::Font* font;
    sf::Sprite sprite;

public:
    AssetManager();
    ~AssetManager();

    void LoadSprite(std::string path = "../Resources/Textures/Failed.jpg", std::string name = "failed");

    sf::Sprite GetSprite(std::string name = "failed");

    sf::Sprite operator[](std::string name);

};


#endif //JOGO_ASSETMANAGER_H
