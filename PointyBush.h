//
// Created by segalle on 11/23/21.
//

#ifndef JOGO_POINTYBUSH_H
#define JOGO_POINTYBUSH_H

#include "StaticEntity.h"

namespace entities {
    namespace obstacles{
            class PointyBush : public StaticEntity {

            public:

                PointyBush();

                ~PointyBush();

                void run();

                int getCollisionDamage();

            };
    }
}


#endif //JOGO_POINTYBUSH_H
