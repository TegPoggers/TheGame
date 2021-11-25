//
// Created by segalle on 11/25/21.
//

#include "EnemyCollision.h"

namespace managers{

    EnemyCollision::EnemyCollision() {}

    EnemyCollision::~EnemyCollision() {}

    void EnemyCollision::enemyIsAlive(entities::characters::Enemy* enemy) {
        if(enemy->getHealth() <= 0){
            enemy->die();
        }
    }

    void EnemyCollision::analyzeEnemyCollision(entities::characters::Enemy *enemy, entities::Entity *object) {

        int id = object->getId();

       if(id = star_id){
           enemyProjectileCollision(enemy, dynamic_cast<entities::Projectile*>(object));
       }

    }

    void EnemyCollision::enemyProjectileCollision(entities::characters::Enemy *enemy, entities::Projectile *projectile) {
        enemy->takeDamage(projectile->getCollisionDamage());
        projectile->die();
    }

}