//
// Created by david on 13/10/2021.
//

#include "StateMachine.h"

namespace GameName {

    void StateMachine::AddState(StateRef State, bool replacing) {
        is_adding = true;
        is_replacing = replacing;
        new_state = std::move(State);

    }

    void StateMachine::RemoveState() {
        is_removing = true;
    }

    void StateMachine::ProcessStateChanges() {
        if (is_removing && !states.empty()) {
            states.pop();

            if (!states.empty()) {
                states.top()->Resume();
            }
            is_removing = false;
        }
        if (is_adding) {
            if (!states.empty()) {
                if (is_replacing) {
                    states.pop();
                } else {
                    states.top()->pause();
                }
            }

        }
        states.push(std::move(new_state));
        states.top()->Init();
        is_adding = false;


    }

    StateRef &GameName::StateMachine::GetActiveState() {
        return states.top();
    }
}