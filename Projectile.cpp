//
// Created by segalle on 11/19/21.
//

#include "Projectile.h"

namespace entities{

    Projectile::Projectile(Player *creator) :
    creator(creator){
        //Criar a sprite dele que é um círculo preto ou roxo
        //Como apenas o player seta um criador então
    }

    Projectile::~Projectile(){}

    void Projectile::setDamage(int dmg) {
        damage = dmg;
    }

    //Só é chamado quando alguém toma dano
    int Projectile::getDamage() {

        if(creator){
            creator->score(10);
        }

        return damage;
    }

    Player *Projectile::getCreator() {
        return creator;
    }

    void Projectile::setCreator(Player *creator) {
        this->creator = creator;
    }

    void Projectile::run() {
        position.x += speed;
    }

    int Projectile::damage = 10;
    float Projectile::speed = 5;

}