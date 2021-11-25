//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_LEVEL_H
#define JOGO_LEVEL_H

#include "Player.h"
#include "AssetManager.h"
#include "EntityList.h"
#include "WeakGoblin.h"
#include "StrongGoblin.h"
#include "BossGoblin.h"
#include "InputManager.h"
#include "LevelMaker.h"
#include "CollisionManager.h"

using namespace entities::characters;

//Monitoria pra entender qual o uso da lista de jogadores, inimigos, etc
// weak ( atira)
// strong (anda e soca)
// Boss (atira)  - Ver oq seria diferente o suficiente
namespace  levels {

    class Level : public Being {

    protected:
        EntityList* entityList;
        bool onePlayer;
        LevelMaker levelMaker;
        Player* p1;
        Player* p2;
        sf::Sprite* background;
        sf::Vector2f backPosition;

    public:
        Level();
        Level(Player* p1, Player* p2);
        ~Level();

        void run();
        void renderPlayers(bool onePlayer);
        void loadGame(); // Roda a fase
        void renderBackground();
        void setPosition(float x, float y);
        void setBackground(sf::Sprite* background);
        sf::Vector2f getPosition();
        void setView();
        virtual void initializeElements() = 0; //Deixar como virtual pura
        virtual void createEnemies() = 0;
        virtual void createObstacles() = 0;
        void shootCurrent(int i);
    };
}



#endif //JOGO_LEVEL_H
