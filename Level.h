//
// Created by viviane on 18/11/2021.
//

#ifndef JOGO_LEVEL_H
#define JOGO_LEVEL_H

#include "Player.h"
using namespace entities::characters;
#include "EntityList.h"

//Monitoria pra entender qual o uso da lista de jogadores, inimigos, etc

namespace  levels {

    class Level {

    protected:
        //Deve precisar de um manager para a window, mas não consegui pensar nisso ainda
        //EntityList* entityList;
        Player* p1;
        Player* p2;
        //Enemy* e1;
        //Enemy* e2; (São dois? Não lembro)
        //Boss* boss;
        virtual void initializeElements(); //Deixar como virtual pura

    public:
        Level(Player* p1);
        ~Level();
        EntityList* entityList; //É protected - apenas pra teste

    };
}



#endif //JOGO_LEVEL_H
