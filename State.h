//
// Created by david on 13/10/2021.
//

#ifndef JOGO_STATE_H
#define JOGO_STATE_H

namespace GameName {
    class State {

    public:
        virtual void Init() = 0;

        virtual void HandleInput() = 0;

        virtual void Update(float dt) = 0;

        //dt representa o tempo entre frames pra fazer o jogo independente do fps
        virtual void Draw(float dt) = 0;

        virtual void pause(){}

        virtual void Resume(){}
    };
}


#endif //JOGO_STATE_H
