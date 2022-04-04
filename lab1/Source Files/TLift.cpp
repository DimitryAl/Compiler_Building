#include "../Header Files/TLift.h"
#include "../Header Files/Funcs.h"



TLift::TLift() {}

TLift::~TLift() {}

State TLift::GetCurrentState()
{
    return _current_state;
}

bool CheckButtons(int arr[], int start, int end)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == 1) return true;
    }
    return false;
}

void TLift::Transition(/*State current_state,  char symbol*/ int outer[], int inner[])
{
    switch (_current_state)
    {
    case State::Standing0:
        //if there is pressed buttons on higher floor go up
        if (CheckButtons(outer, 1, FLOORS))
        {
            _current_state = State::Going0_Up;
            break;
        }       
        if (CheckButtons(inner, 1, FLOORS))
        {
            _current_state = State::Going0_Up;
        }
        //if smbd leaves lift on this floor 
        if (inner[0] == 1)
        {
            inner[0] == 0;
        }
        break;
    case State::Going0_Up:
    //if there is pressed buttons on higher floor go up
        if (CheckButtons(outer, 2, FLOORS))
        {
            _current_state = State::Going0_Up;
            break;
        }       
        if (CheckButtons(inner, 1, FLOORS))
        {
            _current_state = State::Going0_Up;
        }
        //if smbd leaves lift on this floor 
        if (inner[0] == 1)
        {
            inner[0] == 0;
        }
        break;
    default:
        break;
    }
}

void TLift::SetCurrentState(State state)
{
    _current_state = state;
}
