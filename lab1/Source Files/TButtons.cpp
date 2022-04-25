#include "../Header Files/TButtons.h"

std::vector <int>& TButtons::GetOuterButtons()
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
    pressedOuterButtons[place] = value;
    return true;
}

std::vector <int>& TButtons::GetInnerButtons()
{
    return pressedInnerButtons;
}
