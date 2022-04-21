#include "../Header Files/TLift.h"
#include "../Header Files/Funcs.h"



TLift::TLift() {}

TLift::~TLift() {}

State TLift::GetCurrentState()
{
	return _current_state;
}

void TLift::SetCurrentState(State state)
{
	_current_state = state;
}

bool TLift::CheckButtons(int arr[], int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (arr[i] > 0) return true;
	}
	return false;
}

void TLift::Transition(std::vector <int> pressedOuterButtons, std::vector <int> pressedInnerButtons)
{
	switch (current_state)
	{
	case State::Standing0:
		int i = 0;
		// if inner button is pressed, passager goes out
		if (pressedInnerButtons[0] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[0] = 0;
		}
		// if outer button on higher floor is pressed, go up
		for (i = 1; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up1);
		}
		// if smbd calls lift on this floor, get new passanger
		if (pressedOuterButtons[0] == 1)
		{
			//get new floor from passanger
			pressedOuterButtons[0] = 0;
		}
		break;
	case State::Going_Up0:
		//if smbd wants to leave on 1st floor
		if (pressedInnerButtons[1] == 1)
		{
			SetCurrentState(State::Standing1);
			break;
		}
		// if outer button on higher floor is pressed, go up
		for (i = 1; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up1);
			break;
		}
	case State::Standing1:
		// if inner button is pressed, passager goes out
		if (pressedInnerButtons[1] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[1] = 0;
		}
		// if smbd calls lift on this floor, get new passanger
		if (pressedOuterButtons[1] == 1)
		{
			//get new floor from passanger
			pressedOuterButtons[1] = 0;
		}
		// if outer button on higher floor is pressed, go up
		for (i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up1);
			break;
		}
		// if outer button on lower floor is pressed, go down
		for (i = 0; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down1);
			break;
		}
		break;
	case State::Going_Up1:
		//if smbd wants to leave on 2nd floor
		if (pressedInnerButtons[2] == 1)
		{
			SetCurrentState(State::Standing2);
			break;
		}
		// if outer button on higher floor is pressed, go up
		for (i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			break;
		}
		break;
	case State::Going_Down1:

		break;
    default:
        break;
    }
}




