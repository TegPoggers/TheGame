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
        Xposition = 0;
        max_entities = 0;
    }

    LevelMaker::~LevelMaker(){

    }

    void LevelMaker::createWeakGoblin(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN; //De 800 até 11,200 (x)
            cout << Xposition << endl;
            //Ver se teve colisão com alguma coisa
            WeakGoblin* weakGoblin = new WeakGoblin();
            weakGoblin->setPlayer(player); //Fazer try catch para ver se tem outro player
            weakGoblin->setPosition(Xposition , 540);
            weakGoblin->setSprite(assets->getSprite("weakGoblin"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(weakGoblin));
                assets->getSprite("darkEnergyOrb")->setScale(0.1, 0.1);
                assets->getSprite("weakGoblin")->setScale(0.7, 0.7);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
        }
    }

    void LevelMaker::createStrongGoblin(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN; //De 800 até 11,200 (x)
            cout << Xposition << endl;
            //Ver se teve colisão com alguma coisa
            StrongGoblin* strongGoblin = new StrongGoblin();
            strongGoblin->setPlayer(player); //Fazer try catch para ver se tem outro player
            strongGoblin->setPosition(Xposition , 540);
            strongGoblin->setSprite(assets->getSprite("strongGoblin"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(strongGoblin));
                assets->getSprite("strongGoblin")->setScale(0.7, 0.7);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
        }
    }

    void LevelMaker::createBossGoblin(){
            //Ver se teve colisão com alguma coisa
            BossGoblin* bossGoblin = new BossGoblin();
            bossGoblin->setPlayer(player); //Fazer try catch para ver se tem outro player
            bossGoblin->setPosition(BOSS_POSITION, 210);
            bossGoblin->setSprite(assets->getSprite("bossGoblin"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(bossGoblin));
                assets->getSprite("energyOrb")->setScale(0.1, 0.1);
                assets->getSprite("bossGoblin")->setScale(2, 2);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
    }

    void LevelMaker::createSpikes(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            //Ver se teve colisão com alguma coisa
            Spikes* spikes = new Spikes();
            spikes->setPosition(Xposition , 540);
            spikes->setSprite(assets->getSprite("spikes"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(spikes));
                assets->getSprite("spikes")->setScale(0.7, 0.7);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
        }
    }

    void LevelMaker::createFirePit(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            //Ver se teve colisão com alguma coisa
            FirePit* firePit = new FirePit();
            firePit->setPosition(Xposition , 540);
            firePit->setSprite(assets->getSprite("firePit"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(firePit));
                assets->getSprite("firePit")->setScale(1.5, 1.5);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
        }
    }

    void LevelMaker::createPointyBush(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            //Ver se teve colisão com alguma coisa
            PointyBush* pointyBush = new PointyBush();
            pointyBush->setPosition(Xposition , 540);
            pointyBush->setSprite(assets->getSprite("pointyBush"));
            if (entityList && assets){
                entityList->eList.push(static_cast<entities::Entity*>(pointyBush));
                assets->getSprite("pointyBush")->setScale(0.7, 0.7);
            } else {
                cout << "Asset Manager or Entity List pointer is null" << endl;
            }
        }
    }

    void LevelMaker::renderObstacles(){
        createFirePit();
        createPointyBush();
        createSpikes();
    }
}