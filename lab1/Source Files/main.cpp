#include <iostream>
#include <fstream>
#include <ctime>


#include "../Header Files/TLift.h"
#include "../Header Files/TButtons.h"
#include "../Header Files/Funcs.h"

int main()
{
    int rand;
    int symbol;
    int symbol2;
    TButtons Buttons;
    TLift elevator;
    //State temp;
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
        
        // outside button is pressed
        Buttons.SetOuterButton(symbol - 1, 1);
        std::cout << std::endl;
        // result goes to lift
        elevator.Transition(Buttons.GetOuterButtons(), Buttons.GetInnerButtons());
        if (elevator.GetCurrentState() == State::Final)
            break;
    }

    return 0;
}