//
// Created by segalle on 11/19/21.
//

#include "Projectile.h"

namespace entities{

    Projectile::Projectile(characters::Player* creator) :
    creator(creator){}

    Projectile::~Projectile(){}

    void Projectile::setDamage(int dmg) {
        damage = dmg;
    }

    //Só é chamado quando alguém toma dano
    int Projectile::getDamage() {
        return damage;
    }

    characters::Player* Projectile::getCreator() {
        return creator;
    }

    void Projectile::setCreator(characters::Player* creator) {
        this->creator = creator;
    }

    void Projectile::run() {
        position.x += speed * direction;
    }

    void Projectile::setDirection(int direction) {
        this->direction = direction;
    }

    int Projectile::getCollisionDamage() {
        return damage;
    }

    int Projectile::damage = 10;
    float Projectile::speed = 7;

}