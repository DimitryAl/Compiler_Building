#include "TButtons.h"

int *TButtons::GetOuterButtons()
{
    return _pressedOuterButtons;
}

bool TButtons::SetOuterButton(int place, int value)
{
    if (place < 0)
        return false;
    if (place >= FLOORS)
        return false;
    if (value != 0 and value != 1)
        return false;
    _pressedOuterButtons[place] = value;
}

int *TButtons::GetInnerButtons()
{
    return _pressedInnerButtons;
}

bool TButtons::SetInnerButton(int place, int value)
{
    if (place < 0)
        return false;
    if (place >= FLOORS)
        return false;
    if (value != 0 and value != 1)
        return false;
    _pressedInnerButtons[place] = value;
}

void Transition(int outer[], int inner[])
{

}