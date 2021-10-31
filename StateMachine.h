//
// Created by david on 13/10/2021.
//

#ifndef JOGO_STATEMACHINE_H
#define JOGO_STATEMACHINE_H

#include <memory>
#include <stack>
using namespace std;
#include "State.h"

namespace GameName {
    typedef std::unique_ptr<State> StateRef;
    class StateMachine {


    public:
        StateMachine(){}

        ~StateMachine(){}

        void AddState (StateRef State, bool replacing = true);

        void RemoveState();

        void ProcessStateChanges();

        StateRef &GetActiveState();



    private:
        stack<StateRef> states;
        StateRef new_state;
        bool is_removing;
        bool is_replacing;
        bool is_adding;
    };
}


#endif //JOGO_STATEMACHINE_H
