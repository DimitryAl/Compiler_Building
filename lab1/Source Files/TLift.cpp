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

void TLift::PassangerOut(std::vector<int> arr, int i)
{
	if (arr[i] == 1)
	{
		std::cout << " passager(s) go out\n";
		arr[i] = 0;
	}
}

int TLift::PassangerIn(std::vector<int> arr, int i)
{
	if (arr[i] == 1)
	{
		arr[i] = 0;
		// get new floor from passanger
		return GetFloor();
	}
}

int GetFloor()
{
	char symbol;
	do 
	{
		std::cout << "Enter floor's number: ";
		std::cin >> symbol;
		std::cout << std::endl;
	} while (!(48 <= symbol && symbol <= 57));
	return int(symbol);
}

void TLift::Transition(std::vector <int> pressedOuterButtons, std::vector <int> pressedInnerButtons)
{
	switch (currentState)
	{
	case State::Standing0:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 0);

		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 0)] = 1;

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
		PassangerOut(pressedInnerButtons, 1);
		
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 1)] = 1;
		
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
		PassangerOut(pressedInnerButtons, 1);

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
		// if smbd wants to enter
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 1)] = 1;
		
		// id smbd wants to leave on 1 floor 
		PassangerOut(pressedInnerButtons, 1);
		
		//if smbd wants to leave on 0 floor
		if (pressedInnerButtons[0] == 1)
		{
			SetCurrentState(State::Standing0);
			return;
		}
		
		//if smbd wants to enter on 0 floor
		if (pressedInnerButtons[0] == 1)
		{
			SetCurrentState(State::Standing0);
			return;
		}
		
		SetCurrentState(State::Standing1);
		break;

	// states for the second floor
	case State::Standing2:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 2);
		
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 2)] = 1;
		
		// if inner button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		
		// if outer button on higher floor is pressed, go down
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		
		// if inner button on lower floor is pressed, go up
		for (int i = 1; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down1);
			return;
		}
		
		// if outer button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down1);
			return;
		}
		break;
	case State::Going_Up2:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 2);

		// if inner button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		
		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up3);
			return;
		}
		SetCurrentState(State::Standing2);
		break;
	case State::Going_Down2:
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 2)] = 1;

		//if smbd wants to leave 
		PassangerOut(pressedInnerButtons, 2);

		// if inner button on lower floor is pressed, go down
		for (int i = 1; i >= 00; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down1);
			return;
		}

		//if outer button om lower floor is pressed, go down
		for (int i = 1; i >= 00; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down1);
			return;
		}

		SetCurrentState(State::Standing2);	
		break;

	// 3 floor
	case State::Standing3:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 3);
		
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 3)] = 1;
		
		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if outer button on higher floor is pressed, go down
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if inner button on lower floor is pressed, go up
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		
		// if outer button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		break;
	case State::Going_Up3:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 3);

		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if outer button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		SetCurrentState(State::Standing3);
		break;
	case State::Going_Down3:
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 3)] = 1;

		//if smbd wants to leave 
		PassangerOut(pressedInnerButtons, 3);

		// if inner button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}

		//if outer button om lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}

		SetCurrentState(State::Standing2);	
		break;

	// floor 4
	case State::Standing4:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 3);
		
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 3)] = 1;
		
		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if outer button on higher floor is pressed, go down
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if inner button on lower floor is pressed, go up
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		
		// if outer button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}
		break;
	case State::Going_Up4:
		// if inner button is pressed, passanger goes out
		PassangerOut(pressedInnerButtons, 3);

		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		
		// if outer button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Up4);
			return;
		}
		SetCurrentState(State::Standing3);
		break;
	case State::Going_Down4:
		// if smbd calls lift on this floor, get new passanger
		pressedInnerButtons[PassangerIn(pressedOuterButtons, 3)] = 1;

		//if smbd wants to leave 
		PassangerOut(pressedInnerButtons, 3);

		// if inner button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}

		//if outer button om lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0) SetCurrentState(State::Going_Down2);
			return;
		}

		SetCurrentState(State::Standing2);	
		break;

    default:
        break;
    }
}




