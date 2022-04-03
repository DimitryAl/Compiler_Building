#ifndef TBUTTONS_H
#define TBUTTONS_H

#define FLOORS 10

class TButtons
{
private:    
    int _pressedOuterButtons[FLOORS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int _pressedInnerButtons[FLOORS] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
public:
    TButtons() {};
    ~TButtons() {};

    int* GetOuterButtons();
    bool SetOuterButton(int place, int value);
    int* GetInnerButtons();
    bool SetInnerButton(int place, int value);
    void Transition(int outer[], int inner[]);
};

#endif