#include <iostream>
#include <fstream>
#include <vector>

enum class State
{
    Start,
    Read,
    Final
};
State current_state = State::Start;
int current_floor = 0;
std::vector <char> queue = {};

State Transition(State cur_state, char symbol)
{
    switch (cur_state)
    {
    case State::Start:
        
        if (symbol == '\n') return State::Final;

        break;
    case State::Read:
        
        if (symbol == '\n') return State::Final;

        break;
    case State::Final:
        
        if (symbol == '\n') return State::Final;

        break;
    default:
        break;
    }
}

char GetSymbol(std::ifstream &file)
{
    return file.get();
}

int main()
{
    std::string file_name = "in.txt";
    std::ifstream file;

    file.open(file_name);
    if (!file)
        return 1;

    char symbol;

    while (1)
    {
        symbol = GetSymbol(file);
        if (symbol > current_floor) symbol = 'u';
        else symbol = 'd';
        
        current_state = Transition(current_state, symbol);

        if (current_state == State::Final)
            break;
    }

    return 0;
}