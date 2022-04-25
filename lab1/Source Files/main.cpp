#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <thread>

#include "../Header Files/TLift.h"
#include "../Header Files/TButtons.h"

bool isDigit(int symbol)
{
    if ((0 <= symbol && symbol <= 9))
        return true;
    else
        return false;
}

int GetSymbol(std::ifstream &file) // read symbol from file
{
    int sym = file.get() - 48;
    return sym;
}

int main()
{
    int rand;
    int symbol;
    TButtons Buttons;
    TLift elevator;
    std::string file_name = "./Resources Files/in.txt";
    std::ifstream file;

    file.open(file_name);
    if (!file)
        return 1;

    std::srand(std::time(nullptr)); // use current time as seed for random generator

    int cnt = 0;
    while (1)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        rand = std::rand() % 3;
        if (rand == 0)
        {
            symbol = GetSymbol(file);
            if (isDigit(symbol))
            {
                std::cout << "Lift was called on " << symbol << " floor" << std::endl;
                bool flag = Buttons.SetOuterButton(symbol, 1);
                if (!flag)
                    break;
            }
            else
            {
                if (symbol != '\n')
                {
                    std::cout << "Wrong input symbol!\n";
                    elevator.SetCurrentState(State::Final);
                }
            }
        }

        if (elevator.GetCurrentState() == State::Final)
            break;

        // result goes to lift
        elevator.Transition(Buttons.GetOuterButtons(), Buttons.GetInnerButtons());
    }

    return 0;
}