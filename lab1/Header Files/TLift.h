#ifndef TLIFT_H
#define TLIFT_H

#include <vector>
#include "TState.h"

#define FLOORS 10

class TLift
{
private:
    // State _current_state = State::Start;
    State _current_state = State::Standing0;
    //char _current_floor = 0;
    //char _target_floor = 0;
    //std::vector <char> _queue = {};
    bool CheckButtons(int arr[], int start, int end);
public:
    TLift();
    ~TLift();
    State GetCurrentState();
    void Transition(int symbol);
    void SetCurrentState(State state);
};

#endif