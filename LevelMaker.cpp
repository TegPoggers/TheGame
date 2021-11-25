//
// Created by viviane on 24/11/2021.
//

#include "LevelMaker.h"

//Alterar valores do y pela função do david
namespace levels{

    //FIm do background: 122879998080
    // 9010
    // 12765 (porta)

    LevelMaker::LevelMaker() {  }

    LevelMaker::LevelMaker(Player* p, EntityList* list, AssetManager* asset) :
    player(p),
    entityList(list),
    assets(asset){
        srand(time(NULL));

    }

    LevelMaker::~LevelMaker(){

    }

    void LevelMaker::createWeakGoblin(){
        float positionX = (rand() % 12000) + 800; //De 800 até 11,200 (x)
        int max = rand() % 7;
        cout << "O maximo de weak eh " << max << endl;
        for (int i = 0; i < (3 + max); i++){
            cout << positionX << endl;
            weakGoblin = new WeakGoblin();
            weakGoblin->setPlayer(player); //Fazer try catch para ver se tem outro player
            weakGoblin->setPosition(positionX , 540);
            weakGoblin->setSprite(assets->getSprite("weakGoblin"));
            entityList->eList.push(weakGoblin); // Seg Fault Aqui (?????????????????)
            //entityList->eList.push(static_cast<entities::Entity*>(weakGoblin));
            assets->getSprite("darkEnergyOrb")->setScale(0.1, 0.1);
            assets->getSprite("weakGoblin")->setScale(0.7, 0.7);

        }
    }

    void LevelMaker::createStrongGoblin(){

    }

    void LevelMaker::createBossGoblin(){

    }

    void LevelMaker::createSpikes(){

    }

    void LevelMaker::createFirePit(){

    }

    void LevelMaker::createPointyBush(){

    }
}