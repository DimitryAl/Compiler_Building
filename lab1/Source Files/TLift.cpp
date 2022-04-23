#include "../Header Files/TLift.h"
#include "../Header Files/Funcs.h"

#include <iostream>

TLift::TLift() {}

TLift::~TLift() {}

State TLift::GetCurrentState()
{
	return currentState;
}

void TLift::SetCurrentState(State state)
{
	currentState = state;
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
	switch (currentState)
	{
	case State::Standing0:
		// if inner button is pressed, passanger goes out
		if (pressedInnerButtons[0] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[0] = 0;
		}
		// if smbd calls lift on this floor, get new passanger
		if (pressedOuterButtons[0] == 1)
		{
			//get new floor from passanger
			pressedOuterButtons[0] = 0;
		}
		// if inner button on higher floor is pressed, go up
		for (int i = 1; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Up1);
			return;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 1; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up1);
			return;
		}
		break;
	// case State::Going_Up0:
	// 	//if smbd wants to leave on 1st floor
	// 	if (pressedInnerButtons[1] == 1)
	// 	{
	// 		SetCurrentState(State::Standing1);
	// 		break;
	// 	}
	// 	// if inner button on higher floor is pressed, go up
	// 	for (int i = 1; i < FLOORS; i++)
	// 	{
	// 		// replace OuterButtons on innerButtons ???
	// 		if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Up1);
	// 		return;
	// 	}
	// 	SetCurrentState(State::Standing1); // ???
	// 	break;

	// states for the first floor
	case State::Standing1:
		// if inner button is pressed, passanger goes out
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
		// if inner button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		// if outer button on higher floor is pressed, go down
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		// if inner button on lower floor is pressed, go up
		for (int i = 0; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Standing0);
			return;
		}
		// if outer button on lower floor is pressed, go down
		for (int i = 0; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Standing0);
			return;
		}
		break;
	case State::Going_Up1:
		// if inner button is pressed, passanger goes out
		if (pressedInnerButtons[1] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[1] = 0;
		}
		// // if smbd calls lift on this floor, get new passanger
		// if (pressedOuterButtons[1] == 1)
		// {
		// 	//get new floor from passanger
		// 	pressedOuterButtons[1] = 0;
		// }
		// if inner button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		SetCurrentState(State::Standing1);
		break;
	case State::Going_Down1:
		//if smbd wants to leave on 0 floor
		if (pressedInnerButtons[0] == 1)
		{
			SetCurrentState(State::Standing0);
			return;
		}
		else SetCurrentState(State::Standing1);
		break;

	// states for the second floor
	case State::Standing2:
		// if inner button is pressed, passanger goes out
		if (pressedInnerButtons[2] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[2] = 0;
		}
		// if smbd calls lift on this floor, get new passanger
		if (pressedOuterButtons[2] == 1)
		{
			//get new floor from passanger
			pressedOuterButtons[2] = 0;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		// if outer button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		break;
	case State::Going_Up2:
		//if smbd wants to leave on 3nd floor
		if (pressedInnerButtons[3] == 1)
		{
			SetCurrentState(State::Standing3);
			return;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		break;
	case State::Going_Down2:
		
		/////
		//// make loop from 1 to 0
		////
		// for (int i = 1; i >=00; i--)
		// {
		// 	if (pressedInnerButtons)
		// }
		//if smbd wants to leave on 1st floor
		if (pressedInnerButtons[1] == 1)
		{
			SetCurrentState(State::Standing1);
			return;
		}
		//if noone wants to leave on 1 floor
		else SetCurrentState(State::Going_Down1);
		break;

	// 3 floor
	case State::Standing3:
		// if inner button is pressed, passanger goes out
		if (pressedInnerButtons[3] == 1)
		{
			std::cout << " passager(s) go out\n";
			pressedInnerButtons[3] = 0;
		}
		// if smbd calls lift on this floor, get new passanger
		if (pressedOuterButtons[3] == 1)
		{
			//get new floor from passanger
			pressedOuterButtons[3] = 0;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up2);
			return;
		}
		// if outer button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		break;
	case State::Going_Up3:
		//if smbd wants to leave on 3nd floor
		if (pressedInnerButtons[3] == 1)
		{
			SetCurrentState(State::Standing3);
			return;
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		SetCurrentState(State::Standing4);
		break;
	case State::Going_Down3:
		//if smbd wants to leave on lower floor
		for (int i = 2; i >= 0; i--)
		{
			SetCurrentState(State::Going_Down2);
		}
		if (pressedInnerButtons[2] == 1)
		{
			SetCurrentState(State::Standing2);
			return;
		}
		//if noone wants to leave on 1 floor
		//else SetCurrentState(State::Going_Down1);
		break;

    default:
        break;
    }
}




