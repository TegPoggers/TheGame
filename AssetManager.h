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

    //é necessário carregar texturas antes de torna-las sprites
    std::map<std::string, sf::Sprite*> sprites;
    std::map<std::string, sf::Font*> fonts;
    std::map<std::string, sf::Texture*> textures;

    std::map<std::string, sf::Sprite*>::iterator itS;
    std::map<std::string, sf::Font*>::iterator itF;
    std::map<std::string, sf::Texture*>::iterator itT;

    sf::Texture* texture;
    sf::Font* font;
    sf::Sprite* sprite;

public:

    AssetManager();

    ~AssetManager();

    void loadSprite(std::string path = "../Resources/Textures/Failed.jpg", std::string name = "failed");

    sf::Sprite* getSprite(std::string name = "failed");

    sf::Sprite* operator[](std::string name);

    void loadFont(std::string path, std::string name);

    sf::Font* getFont(std::string name);


};


#endif //JOGO_ASSETMANAGER_H