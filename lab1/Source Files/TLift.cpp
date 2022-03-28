#include "../Header Files/TLift.h"
#include "../Header Files/Funcs.h"

TLift::TLift() {}

TLift::~TLift() {}

State TLift::GetCurrentState()
{
    return _current_state;
}

State TLift::Transition(/*State current_state, */ char symbol)
{
    switch (_current_state)
    {
    case State::Start:
        if (symbol == '\n')
            return State::Final;
            
        if (symbol == 'n')
            return State::Start;

        if (IsDigit(symbol))
        {
            // passanger enters the lift and push button
            _queue.push_back(symbol * 2 % 57);

            if (_current_floor == _target_floor)
            {
                _target_floor = _queue.front();
                _queue.erase(_queue.begin());
            }

            return State::Going_Up;
        }

        return State::Final;
        break;
    case State::Going_Up:

        break;
    case State::Going_Down:
        break;
    case State::Standing:
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
