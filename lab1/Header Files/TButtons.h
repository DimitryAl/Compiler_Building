#ifndef TBUTTONS_H
#define TBUTTONS_H

#include <vector>
//#include "TLift.h"
#include "TState.h"

#define FLOORS 10


class TButtons
{
private:    
    std::vector <int> pressedOuterButtons = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    std::vector <int> pressedInnerButtons = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
   // int destination = 0;
public:
    TButtons() {};
    ~TButtons() {};
    std::vector <int>& GetOuterButtons();
    bool SetOuterButton(int place, int value);
    std::vector <int>& GetInnerButtons();
};

#endif