//
// Created by segalle on 11/19/21.
//

#include "Projectile.h"

namespace entities{

    Projectile::Projectile() : Entity(),
    damage(0),
    speed(1),
    direction(1){}

    Projectile::~Projectile(){}

    void Projectile::setDamage(int dmg) {
        damage = dmg;
    }

    //Só é chamado quando alguém toma dano
    int Projectile::getDamage() {
        return damage;
    }

    void Projectile::run() {
        position.x += speed * (float)direction; if (id == 10){cout <<"ué"<<endl;}
    }

    void Projectile::setDirection(int direction) {
        this->direction = direction;
    }

    int Projectile::getCollisionDamage() {
        return damage;
    }

}