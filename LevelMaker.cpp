//
// Created by viviane on 24/11/2021.
//

#include "LevelMaker.h"

namespace levels{

    LevelMaker::LevelMaker() {}

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
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            WeakGoblin* weakGoblin = new WeakGoblin();
            weakGoblin->setPlayer(player);
            weakGoblin->setSprite(assets->getSprite("weakGoblin"));
            weakGoblin->setPosition(Xposition);
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(weakGoblin));
                assets->getSprite("darkEnergyOrb")->setScale(0.1, 0.1);
                assets->getSprite("weakGoblin")->setScale(0.7, 0.7);
            }
        }
    }

    void LevelMaker::createStrongGoblin(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            StrongGoblin* strongGoblin = new StrongGoblin();
            strongGoblin->setPlayer(player);
            strongGoblin->setPosition(Xposition);
            strongGoblin->setSprite(assets->getSprite("strongGoblin"));
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(strongGoblin));
                assets->getSprite("strongGoblin")->setScale(0.7, 0.7);
            }
        }
    }

    void LevelMaker::createBossGoblin(){
            BossGoblin* bossGoblin = new BossGoblin();
            bossGoblin->setPlayer(player);
            bossGoblin->setPosition(BOSS_POSITION);
            bossGoblin->setSprite(assets->getSprite("bossGoblin"));
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(bossGoblin));
                assets->getSprite("energyOrb")->setScale(0.1, 0.1);
                assets->getSprite("bossGoblin")->setScale(2, 2);
            }
    }

    void LevelMaker::createSpikes(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            Spikes* spikes = new Spikes();
            spikes->setPosition(Xposition);
            spikes->setSprite(assets->getSprite("spikes"));
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(spikes));
                assets->getSprite("spikes")->setScale(0.7, 0.7);
            }
        }
    }

    void LevelMaker::createFirePit(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            //Ver se teve colisão com alguma coisa
            FirePit* firePit = new FirePit();
            firePit->setPosition(Xposition);
            firePit->setSprite(assets->getSprite("firePit"));
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(firePit));
                assets->getSprite("firePit")->setScale(1.5, 1.5);
            }
        }
    }

    void LevelMaker::createPointyBush(){
        max_entities = rand() % RAND_ENTITIES;
        for (int i = 0; i < (3 + max_entities); i++){
            Xposition = (rand() % POSITION_MAX) + POSITION_MIN;
            PointyBush* pointyBush = new PointyBush();
            pointyBush->setPosition(Xposition);
            pointyBush->setSprite(assets->getSprite("pointyBush"));
            if (entityList && assets){
                entityList->push(static_cast<entities::Entity*>(pointyBush));
                assets->getSprite("pointyBush")->setScale(0.7, 0.7);
            }
        }
    }

    void LevelMaker::renderObstacles(){
        createFirePit();
        createPointyBush();
        createSpikes();
    }

    void LevelMaker::renderFinishLine() {

        entities::FinishLine* finish = new entities::FinishLine();

        if (entityList && assets) {
            entityList->push(static_cast<entities::Entity *>(finish));
            assets->getSprite("pointyBush")->setScale(0.7, 0.7);
        }
    }
}
