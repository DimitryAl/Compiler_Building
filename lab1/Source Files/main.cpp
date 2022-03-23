#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <ctime>

enum class State
{
    Start,
    Going_Up,
    Going_Down,
    Standing,
    Final
};
State current_state = State::Start;
char current_floor = 0;
char target_floor = 0;
std::vector<char> queue = {};

bool IsDigit(char symbol) // return true if char is digit else false
{
    if (48 <= symbol <= 57)
        return true;
    else
        return false;
}

State Transition(State cur_state, char symbol)
{
    switch (cur_state)
    {
    case State::Start:

        if (symbol == '\n') return State::Final;

        if (IsDigit(symbol))
        {
            target_floor = symbol;
            return State::Going_Up;
        }

        if (symbol == 'n') return State::Start;
        
        if (symbol == 'u') 
        {
            current_floor++;
            return State::Going_Up;
        }
        
        return State::Final;

        break;
    case State::Going_Up:

        current_floor++;

        if (symbol == '\n') return State::Final;

        if (symbol == 'n') return State::Going_Up;

        if (symbol == 's') return State::Standing;

        break;
    case State::Going_Down:

        current_floor--;

        if (symbol == '\n') return State::Final;

        if (symbol == 'n') return State::Going_Down;

        if (symbol == 's') return State::Standing;

        break;
    case State::Standing:

        if (symbol == '\n') return State::Final;

        if (symbol == 'n') return State::Standing;

        if (symbol == 'u') 
        {
            current_floor++;
            return State::Going_Up;
        }
        if (symbol == 'd') 
        {
            current_floor--;
            return State::Going_Down;
        }

        break;
    case State::Final:

        return State::Final;

        break;
    default:
        break;
    }
}

char GetSymbol(std::ifstream &file) // read symbol from file
{
    return file.get();
}



int main()
{
    std::string file_name = "./Resources Files/in.txt";
    std::ifstream file;

    file.open(file_name);
    if (!file)
        return 1;


    std::srand(std::time(nullptr)); //use current time as seed for random generator
    int rand;
    char symbol;
    int i = 0;
    while (1)
    {
        rand = std::rand() / (RAND_MAX / 3);
        if (rand = 0)
        {
            symbol = GetSymbol(file);
        }
        else  symbol = 'n';
        
        //symbol = GetSymbol(file);
        if (IsDigit(symbol))
        {
            queue.push_back(symbol);
        }

        //std::sort(queue.begin(), queue.end());

        if (current_state == State::Standing)
        {
            if (queue.empty())
            {
                symbol = 'n';
            }
            else
            {
                target_floor = queue.front();
                queue.erase(queue.begin());
                if (target_floor > current_floor)
                    symbol = 'u';
                if (target_floor < current_floor)
                    symbol = 'd';
                if (target_floor == current_floor)
                    symbol = 'n';
            }
        }
        else 
        {
            if (current_floor == target_floor) symbol = 's';
            if (current_state == State::Going_Up) symbol = 'u';
            if (current_state == State::Going_Down) symbol = 'd';
        }

        current_state = Transition(current_state, symbol);

        if (current_state == State::Final)
            break;
    }

    return 0;
}