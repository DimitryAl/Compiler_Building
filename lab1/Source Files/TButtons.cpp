#include "../Header Files/TButtons.h"
#include "../Header Files/TState.h"

std::vector <int> TButtons::GetOuterButtons()
{
    return pressedOuterButtons;
}

bool TButtons::SetOuterButton(int place, int value)
{
    if (place < 0)
        return false;
    if (place >= FLOORS)
        return false;
    if (value != 0 and value != 1)
        return false;
    pressedOuterButtons[place] += value;
}

std::vector <int> TButtons::GetInnerButtons()
{
    return pressedInnerButtons;
}

bool TButtons::SetInnerButton(int place, int value)
{
    if (place < 0)
        return false;
    if (place >= FLOORS)
        return false;
    if (value != 0 and value != 1)
        return false;
    pressedInnerButtons[place] += value;
}

int TButtons::Transition(State state)
{
    // get current floor
    int currentFloor;
    if (state == State::Standing0 || state == State::Going_Up0)
    {   
        currentFloor = 0;
    }
    if (state == State::Standing1 || state == State::Going_Up1 || state == State::Going_Down1)
    {   
        currentFloor = 1;
    }
    if (state == State::Standing2 || state == State::Going_Up2 || state == State::Going_Down2)
    {   
        currentFloor = 2;
    }
    if (state == State::Standing3 || state == State::Going_Up3 || state == State::Going_Down3)
    {   
        currentFloor = 3;
    }
    if (state == State::Standing4 || state == State::Going_Up4 || state == State::Going_Down4)
    {   
        currentFloor = 4;
    }
    if (state == State::Standing5 || state == State::Going_Up5 || state == State::Going_Down5)
    {   
        currentFloor = 5;
    }
    if (state == State::Standing6 || state == State::Going_Up6 || state == State::Going_Down6)
    {   
        currentFloor = 6;
    }
    if (state == State::Standing7 || state == State::Going_Up7 || state == State::Going_Down7)
    {   
        currentFloor = 7;
    }
    if (state == State::Standing8 || state == State::Going_Up8 || state == State::Going_Down8)
    {   
        currentFloor = 8;
    }
    if (state == State::Standing9 || state == State::Going_Down9)
    {   
        currentFloor = 9;
    }
    
    //choose action depending on current floor and pressed buttons
    if (destination > currentFloor) 
    {
        return 1;
    }
    if (destination < currentFloor)
    {
        return -1;
    }

    

    
    
    return 1;
}