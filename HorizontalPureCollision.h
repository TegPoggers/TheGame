//
// Created by segalle on 11/25/21.
//

#ifndef JOGO_HORIZONTALPURECOLLISION_H
#define JOGO_HORIZONTALPURECOLLISION_H

#include "Entity.h"

namespace managers {

    class HorizontalPureCollision {

    public:

        HorizontalPureCollision();

        ~HorizontalPureCollision();

        bool findCollision(entities::Entity* object1, entities::Entity* object2);

        void collide(entities::Entity* object1, entities::Entity* object2);

    };
}

#endif //JOGO_HORIZONTALPURECOLLISION_H
