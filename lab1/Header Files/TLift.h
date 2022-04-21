#ifndef TLIFT_H
#define TLIFT_H

#include <vector>
#include "TState.h"

#define FLOORS 10

class TLift
{
private:

    State current_state = State::Standing0;

    bool CheckButtons(int arr[], int start, int end);
public:
    TLift();
    ~TLift();
    State GetCurrentState();
    void Transition(std::vector <int> pressedOuterButtons, std::vector <int> pressedInnerButtons);
    void SetCurrentState(State state);
};

#endif