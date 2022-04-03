#include <iostream>
#include <fstream>
#include <ctime>

//#include "../Header Files/TState.h"
#include "../Header Files/TLift.h"
#include "../Header Files/TButtons.h"
#include "../Header Files/Funcs.h"

int main()
{
    int rand;
    char symbol;
    TButtons Buttons;
    TLift elevator;
    State temp;
    std::string file_name = "./Resources Files/in.txt";
    std::ifstream file;

    file.open(file_name);
    if (!file)
        return 1;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    while (1)
    {
        rand = std::rand() / (RAND_MAX / 3);
        if (rand = 0)
        {
            symbol = GetSymbol(file);
        }
        else
            //symbol = 'n';
            continue;

        // temp = elevator.Transition(symbol);
        // elevator.SetCurrentState(temp);

        Buttons.SetOuterButton(symbol - 48, 1);
        
        elevator.Transition(Buttons.GetOuterButtons(), Buttons.GetInnerButtons());



        if (elevator.GetCurrentState() == State::Final)
            break;
    }

    return 0;
}