//
// Created by segalle on 11/23/21.
//

#include "PointyBush.h"

namespace entities{
    namespace obstacles{

        PointyBush::PointyBush() : StaticEntity(){}

        PointyBush::~PointyBush() {}

        void PointyBush::run() {}

        int PointyBush::getCollisionDamage() {
            return 0;
        }
    }
}