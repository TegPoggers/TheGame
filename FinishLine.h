//
// Created by segalle on 11/26/21.
//

#ifndef JOGO_FINISHLINE_H
#define JOGO_FINISHLINE_H

#include "Entity.h"

namespace entities {
    class FinishLine : public Entity {

    public:

        FinishLine();

        ~FinishLine();

        void run();

        int getCollisionDamage();

    };
}

#endif //JOGO_FINISHLINE_H
