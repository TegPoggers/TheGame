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

namespace  levels {

    class Level : public Being {

    protected:

        EntityList* entityList;
        LevelMaker levelMaker;
        Player* p1;
        Player* p2;
        sf::Sprite* background;
        sf::Vector2f backPosition;
        managers::CollisionManager physics;
        bool won;
        static bool players_alive;
        int score;

    public:

        Level();

        Level(Player* p1, Player* p2);

        ~Level();


        void run();

        void renderPlayers(int players);

        void renderBackground();

        void setPosition(float x, float y);

        void setBackground(sf::Sprite* background);

        sf::Vector2f getPosition();

        void setView();

        virtual void initializeElements() = 0;

        bool isFinished();

        bool getPlayersAlive();

        int getScore() const;

    };
}



#endif //JOGO_LEVEL_H
