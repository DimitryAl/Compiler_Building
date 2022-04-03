#include "../Header Files/TLift.h"
#include "../Header Files/Funcs.h"

TLift::TLift() {}

TLift::~TLift() {}

State TLift::GetCurrentState()
{
    return _current_state;
}

State TLift::Transition(/*State current_state,  char symbol*/ int outer[], int inner[])
{
    switch (_current_state)
    {
    case State::Start:

        break;
    default:
        return State::Final;
        break;
    }
    return State::Final;
}

void TLift::SetCurrentState(State state)
{
    _current_state = state;
}
