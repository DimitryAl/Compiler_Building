#ifndef TLIFT_H
#define TLIFT_H

#include <vector>
#include "TState.h"

#define FLOORS 10

class TLift
{
private:
    State currentState = State::Standing0;
    bool CheckButtons(int arr[], int start, int end);
    void PassangerOut(std::vector <int>& arr, int i);
    int PassangerIn(std::vector <int>& arr, int i);
    int GetFloor();
public:
    TLift();
    ~TLift();
    State GetCurrentState();
    void Transition(std::vector <int>& pressedOuterButtons, std::vector <int>& pressedInnerButtons);
    void SetCurrentState(State state);
};

#endif