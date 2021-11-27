//
// Created by segalle on 11/25/21.
//

#include "EnemyCollision.h"
#include "PlayerCollision.h"

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

        if(id == star_id){
            enemyProjectileCollision(enemy, dynamic_cast<entities::Projectile*>(object));
        }

        if(id == spikes_id) {
            enemyObstacleCollision(enemy, dynamic_cast<entities::StaticEntity*> (object));
        }

        enemyIsAlive(enemy);
    }

    void EnemyCollision::enemyProjectileCollision(entities::characters::Enemy *enemy, entities::Projectile *projectile) {
        enemy->takeDamage(projectile->getCollisionDamage());
        projectile->die();

    }

    void EnemyCollision::enemyObstacleCollision(entities::characters::Enemy *enemy, entities::StaticEntity *obstacle) {

        enemy->setFallSpeed(0);
        if (enemy->getPosition().x < obstacle->getPosition().x + obstacle->getSprite()->getGlobalBounds().width - 10 && enemy->getPosition().x +
        enemy->getSprite()->getGlobalBounds().width > obstacle->getPosition().x + 10) {
            enemy->setFeetPosition(obstacle->getPosition().y);
            enemy->setGround(true);
        }
        else if (enemy->getPosition().x > obstacle->getPosition().x) {
            enemy->move(sf::Vector2f(1, 0));
        }
        else if (enemy->getPosition().x < obstacle->getPosition().x) {
            enemy->move(sf::Vector2f(-1, 0));
        }
    }
}

