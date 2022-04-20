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

void TLift::Transition(int symbol)
{
    switch (_current_state)
    {
    case State::Standing0:
        
        break;
    case State::Going_Up0:
    
        break;
    default:
        break;
    }
}

void TLift::SetCurrentState(State state)
{
    _current_state = state;
}
