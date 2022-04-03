#ifndef TLIFT_H
#define TLIFT_H

#include <vector>
#include "TState.h"

class TLift
{
private:
    State _current_state = State::Start;
    char _current_floor = 0;
    char _target_floor = 0;
    std::vector <char> _queue = {};
public:
    TLift();
    ~TLift();
    State GetCurrentState();
    State Transition(/*State current_state, char symbol*/int outer[], int inner[]);
    void SetCurrentState(State state);

};

#endif