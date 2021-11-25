//
// Created by segalle on 11/25/21.
//

#include "PlayerCollision.h"

namespace managers {

    PlayerCollision::PlayerCollision() {}

    PlayerCollision::~PlayerCollision() {}

    void PlayerCollision::playerIsAlive(entities::characters::Player *player) {
        if(player->getHealth() <= 0){
            player->die();
        }
    }

    void PlayerCollision::analyzePlayerCollision(entities::characters::Player *player, entities::Entity *object) {

        int id = object->getId();

        switch(id){
            case player_id:
                playerPlayerCollision(player, dynamic_cast<entities::characters::Player*>(object));
            break;

            case weak_goblin_id: case strong_goblin_id: case boss_goblin_id:
                playerEnemyCollision(player, dynamic_cast<entities::characters::Enemy*>(object));
            break;

            case energy_orb_id: case dark_energy_orb_id:
                playerEnemyProjectileCollision(player, dynamic_cast<entities::Projectile*>(object));
            break;
            case fire_pit_id: case bush_id: case spikes_id:
                playerObstacleCollision(player, dynamic_cast<entities::StaticEntity*> (object));
            break;

            default:
                //não faz nada
            break;


        }


    }

    void PlayerCollision::playerPlayerCollision(entities::characters::Player *player1, entities::characters::Player *player2) {
        if(player1->getPosition().x > player2->getPosition().x){
            player1->move(sf::Vector2f (5, 0));
            player2->move(sf::Vector2f (-5, 0));
        }
    }

    void PlayerCollision::playerEnemyCollision(entities::characters::Player *player, entities::characters::Enemy *enemy) {

        if(player->getPosition().x > enemy->getPosition().x){
            player->move(sf::Vector2f (2.5, 0));
            enemy->move(sf::Vector2f (-0.7, 0));
        }
        else if(player->getPosition().x < enemy->getPosition().x){
            player->move(sf::Vector2f (-2.5, 0));
            enemy->move(sf::Vector2f (0.7, 0));
        }

        player->takeDamage(enemy->getCollisionDamage());

        playerIsAlive(player);

    }

    void PlayerCollision::playerEnemyProjectileCollision(entities::characters::Player *player, entities::Projectile *projectile) {

        player->takeDamage(projectile->getCollisionDamage());
        projectile->die();

        playerIsAlive(player);
    }

    void PlayerCollision::playerObstacleCollision(entities::characters::Player *player, entities::StaticEntity *obstacle) {

        int id = obstacle->getId();

        if(id == bush_id){
            if(player->getPosition().x < obstacle->getPosition().x){
                player->move(sf::Vector2f (0.5, 0));
            }
            else if(player->getPosition().x > obstacle->getPosition().x){
                player->move(sf::Vector2f (-0.5, 0));
            }
        }
        else if(id == spikes_id){
            player->setFallSpeed(0);
            if(player->getPosition().x < obstacle->getPosition().x + obstacle->getSprite()->getGlobalBounds().width - 10 && player->getPosition().x +
            player->getSprite()->getGlobalBounds().width > obstacle->getPosition().x + 10){
                player->setFeetPosition(obstacle->getPosition().y);
                player->setGround(true);
            }
            else if(player->getPosition().x > obstacle->getPosition().x){
                player->move(sf::Vector2f (2.5, 0));
            }
            else if(player->getPosition().x < obstacle->getPosition().x){
                player->move(sf::Vector2f (-2.5, 0));
            }
        }

        player->takeDamage(obstacle->getCollisionDamage());

        playerIsAlive(player);

    }

}