//
// Created by david on 13/10/2021.
//

#ifndef JOGO_ASSETMANAGER_H
#define JOGO_ASSETMANAGER_H

#include <string>
#include <map>//Will store assets
using namespace std;
#include <SFML/Graphics.hpp>

namespace GameName {

    //This bit of code is designed to load the textures and fonts that will be used in game to a map container

    class AssetManager {

    private:
        map<string, sf::Texture> texture;
        map<string, sf::Font> font;
        int a;

    public:
        AssetManager();

        ~AssetManager();

        //Name is assigned to the texture for later use, file_name includes the path and name of the file
        void LoadTexture(string name, string file_name);

        sf::Texture &GetTexture(string name);

        void LoadFont(string name, string file_name);

        sf::Font &GetFont(string name);
    };

}

#endif //JOGO_ASSETMANAGER_H
