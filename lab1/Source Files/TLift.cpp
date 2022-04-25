#include "../Header Files/TLift.h"

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
		if (arr[i] > 0)
			return true;
	}
	return false;
}

void TLift::PassengerOut(std::vector<int>& arr, int i)
{
	if (arr[i] == 1)
	{
		std::cout << "Passenger(s) go out\n";
		arr[i] = 0;
	}
}

int TLift::GetFloor()
{
	char symbol;
	do
	{
		std::cout << "Enter floor's number: ";
		std::cin >> symbol;
		//std::cout << std::endl;
	} while (!(48 <= symbol && symbol <= 57));
	
	return (symbol - 48);
}

int TLift::PassengerIn(std::vector<int>& arr, int i)
{
	if (arr[i] == 1)
	{
		arr[i] = 0;
		// get new floor from passanger
		return GetFloor();
	}
	else
		return -1;
}

void TLift::Transition(std::vector<int>& pressedOuterButtons, std::vector<int>& pressedInnerButtons)
{
	int temp = -1;

	switch (currentState)
	{
	case State::Standing0:

		std::cout << "Lift standing on 0 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 0);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 0);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 1; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] == 1)
			{
				SetCurrentState(State::Going_Up1);
				return;
			}
		}
		//  if outer button on higher floor is pressed, go up
		for (int i = 1; i < FLOORS; i++)
		{
			
			if (pressedOuterButtons[i] == 1)
			{
				SetCurrentState(State::Going_Up1);
				return;
			}
		}
		break;

	// states for the first floor
	case State::Standing1:
		
		std::cout << "Lift standing on 1 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 1);
		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 1);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;
		// if inner button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] == 1)
			{
				SetCurrentState(State::Going_Up2);
				return;
			}
		}
		// if inner button on lower floor is pressed, go up
		for (int i = 0; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Standing0);
				return;
			}
		}
		// if outer button on higher floor is pressed, go down
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up2);
				return;
			}
		}
		// if outer button on lower floor is pressed, go down
		for (int i = 0; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Standing0);
				return;
			}
		}
		break;
	case State::Going_Up1:

		std::cout << "Lift come on 1 floor from 0 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 1);
		// if inner button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up2);
				return;
			}
		}
		// if outer button on higher floor is pressed, go up
		for (int i = 2; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up2);
				return;
			}
		}
		SetCurrentState(State::Standing1);
		break;
	case State::Going_Down1:

		std::cout << "Lift come on 1 floor from 2 floor\n";

		// if smbd wants to enter
		temp = PassengerIn(pressedOuterButtons, 1);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;
		// id smbd wants to leave on 1 floor
		PassengerOut(pressedInnerButtons, 1);
		// if smbd wants to leave on 0 floor
		if (pressedInnerButtons[0] == 1)
		{
			SetCurrentState(State::Standing0);
			return;
		}
		// if smbd wants to enter on 0 floor
		if (pressedInnerButtons[0] == 1)
		{
			SetCurrentState(State::Standing0);
			return;
		}
		SetCurrentState(State::Standing1);
		break;

	// states for the second floor
	case State::Standing2:

		std::cout << "Lift standing on 2 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 2);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 2);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up3);
				return;
			}
		}

		// if inner button on lower floor is pressed, go up
		for (int i = 1; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down1);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up3);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down1);
				return;
			}
		}
		break;
	case State::Going_Up2:

		std::cout << "Lift come on 2 floor from 1 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 2);

		// if inner button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up3);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up3);
				return;
			}
		}
		SetCurrentState(State::Standing2);
		break;
	case State::Going_Down2:
		std::cout << "Lift come on 2 floor from 3 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 2);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 2);

		// if inner button on lower floor is pressed, go down
		for (int i = 1; i >= 00; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down1);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 1; i >= 00; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down1);
				return;
			}
		}

		SetCurrentState(State::Standing2);
		break;

	// 3 floor
	case State::Standing3:
		std::cout << "Lift standing on 3 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 3);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 3);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up4);
				return;
			}
		}

		// if inner button on lower floor is pressed, go up
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down2);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up4);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down2);
				return;
			}
		}
		break;
	case State::Going_Up3:
		std::cout << "Lift come on 3 floor from 2 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 3);

		// if inner button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up4);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 4; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up4);
				return;
			}
		}
		SetCurrentState(State::Standing3);
		break;
	case State::Going_Down3:
		std::cout << "Lift come on 3 floor from 4 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 3);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 3);

		// if inner button on lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down2);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 2; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down2);
				return;
			}
		}

		SetCurrentState(State::Standing2);
		break;

	// floor 4
	case State::Standing4:
		std::cout << "Lift standing on 4 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 4);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 4);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 5; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up5);
				return;
			}
		}

		// if inner button on lower floor is pressed, go up
		for (int i = 3; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down3);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 5; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up5);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 3; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down3);
				return;
			}
		}
		break;
	case State::Going_Up4:

		std::cout << "Lift come on 4 floor from 3 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 4);

		// if inner button on higher floor is pressed, go up
		for (int i = 5; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up5);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 5; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up5);
				return;
			}
		}
		SetCurrentState(State::Standing4);
		break;
	case State::Going_Down4:

		std::cout << "Lift come on 4 floor from 5 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 4);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 4);

		// if inner button on lower floor is pressed, go down
		for (int i = 3; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down3);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 3; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down3);
				return;
			}
		}

		SetCurrentState(State::Standing4);
		break;

	// floor 5
	case State::Standing5:

		std::cout << "Lift standing on 5 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 5);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 5);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 6; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up6);
				return;
			}
		}

		// if inner button on lower floor is pressed, go up
		for (int i = 4; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down4);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 6; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up6);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 4; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down4);
				return;
			}
		}
		break;
	case State::Going_Up5:
		std::cout << "Lift come on 5 floor from 4 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 5);

		// if inner button on higher floor is pressed, go up
		for (int i = 6; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up6);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 6; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up6);
				return;
			}
		}
		SetCurrentState(State::Standing5);
		break;
	case State::Going_Down5:
		std::cout << "Lift come on 5 floor from 6 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 5);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 5);

		// if inner button on lower floor is pressed, go down
		for (int i = 4; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down4);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 4; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down4);
				return;
			}
		}

		SetCurrentState(State::Standing5);
		break;

	// floor 6
	case State::Standing6:
		std::cout << "Lift standing on 6 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 6);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 6);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 7; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up7);
				return;
			}
		}

		// if inner button on lower floor is pressed, go down
		for (int i = 5; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down5);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 7; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up7);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 5; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down5);
				return;
			}
		}
		break;
	case State::Going_Up6:
		std::cout << "Lift come on 6 floor from 5 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 6);

		// if inner button on higher floor is pressed, go up
		for (int i = 7; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up7);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 7; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up7);
				return;
			}
		}
		SetCurrentState(State::Standing6);
		break;
	case State::Going_Down6:
		std::cout << "Lift come on 6 floor from 5 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 6);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 6);

		// if inner button on lower floor is pressed, go down
		for (int i = 5; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down5);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 5; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down5);
				return;
			}
		}

		SetCurrentState(State::Standing6);
		break;

	// floor 7
	case State::Standing7:
		std::cout << "Lift standing on 7 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 7);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 7);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 8; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up8);
				return;
			}
		}

		// if inner button on lower floor is pressed, go down
		for (int i = 6; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down6);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 8; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up8);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 6; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down6);
				return;
			}
		}
		break;
	case State::Going_Up7:
		std::cout << "Lift come on 7 floor from 6 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 7);

		// if inner button on higher floor is pressed, go up
		for (int i = 8; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up8);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 8; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Up8);
				return;
			}
		}
		SetCurrentState(State::Standing7);
		break;
	case State::Going_Down7:
		std::cout << "Lift come on 7 floor from 8 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 7);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 7);

		// if inner button on lower floor is pressed, go down
		for (int i = 6; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down6);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 6; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down6);
				return;
			}
		}

		SetCurrentState(State::Standing7);
		break;

	// states for the 8 floor
	case State::Standing8:
		std::cout << "Lift standing on 8 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 8);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 8);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on higher floor is pressed, go up
		for (int i = 9; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Standing9);
				return;
			}
		}

		// if inner button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down7);
				return;
			}
		}

		// if outer button on higher floor is pressed, go down
		for (int i = 9; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Standing9);
				return;
			}
		}

		// if outer button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down7);
				return;
			}
		}
		break;
	case State::Going_Up8:
		std::cout << "Lift come on 8 floor from 7 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 8);

		// if inner button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Standing9);
				return;
			}
		}

		// if outer button on higher floor is pressed, go up
		for (int i = 3; i < FLOORS; i++)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Standing9);
				return;
			}
		}
		SetCurrentState(State::Standing8);
		break;
	case State::Going_Down8:
		std::cout << "Lift come on 8 floor from 9 floor\n";

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 8);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if smbd wants to leave
		PassengerOut(pressedInnerButtons, 8);

		// if inner button on lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedInnerButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down7);
				return;
			}
		}

		// if outer button om lower floor is pressed, go down
		for (int i = 1; i >= 0; i--)
		{
			if (pressedOuterButtons[i] != 0)
			{
				SetCurrentState(State::Going_Down7);
				return;
			}
		}

		SetCurrentState(State::Standing8);
		break;

		// states for the 8 floor
	case State::Standing9:

		std::cout << "Lift standing on 9 floor\n";

		// if inner button is pressed, passanger goes out
		PassengerOut(pressedInnerButtons, 9);

		// if smbd calls lift on this floor, get new passanger
		temp = PassengerIn(pressedOuterButtons, 9);
		if (temp != -1)
			pressedInnerButtons[temp] = 1;

		// if inner button on lower floor is pressed, go up
		for (int i = 8; i >= 0; i--)
		{
			if (pressedInnerButtons[i] == 1)
			{
				SetCurrentState(State::Going_Down8);
				return;
			}
		}

		//  if outer button on lower floor is pressed, go up
		for (int i = 8; i >= 0; i--)
		{
			
			if (pressedOuterButtons[i] == 1)
			{
				SetCurrentState(State::Going_Down8);
				return;
			}
		}
		break;	
	default:
		break;
	}
}
