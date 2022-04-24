#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <thread>

#include "../Header Files/TLift.h"
#include "../Header Files/TButtons.h"
//#include "../Header Files/Funcs.h"

bool isDigit(int symbol)
{
    if ((0 <= symbol && symbol <= 9)) return true;
    else return false;
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
    int symbol2;
    TButtons Buttons;
    TLift elevator;
    // State temp;
    std::string file_name = "./Resources Files/in.txt";
    std::ifstream file;

    file.open(file_name);
    if (!file)
        return 1;

//    std::srand(std::time(nullptr)); // use current time as seed for random generator

    // std::cout << "before while\n";
    int cnt = 0;
    while (1)
    {
        cnt++;
        if (cnt == 20) break;
      //  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

        // std::cout << (int)elevator.GetCurrentState() << std::endl;

        // rand = std::rand() % 3;
        // if (rand == 0)
        // {
        //     symbol = GetSymbol(file);
        //     std::cout << symbol << "\n";
        //     if (!(48 <= symbol && symbol <= 57))
        //     {
        //         // elevator.SetCurrentState(State::Final);
        //     }
        //     else
        //     {
        //         std::cout << "Lift was called on " << symbol << " floor" << std::endl;
        //         bool flag = Buttons.SetOuterButton(symbol, 1);
        //         if (!flag)
        //             break;
        //     }
        // }
        // else
        //     continue;
        symbol = GetSymbol(file);
        if (isDigit(symbol))
        {
            std::cout << "Lift was called on " << symbol << " floor" << std::endl;
            bool flag = Buttons.SetOuterButton(symbol, 1);
            if (!flag)
                break;
        }

        // result goes to lift
        elevator.Transition(Buttons.GetOuterButtons(), Buttons.GetInnerButtons());

        if (elevator.GetCurrentState() == State::Final)
            break;
    }

    return 0;
}