#include "../Header Files/Funcs.h"

bool IsDigit(char symbol) // return true if char is digit else false
{
    if (48 <= symbol <= 57)
        return true;
    else
        return false;
}

char GetSymbol(std::ifstream &file) // read symbol from file
{
    int sym = file.get() - 48;
    return sym;
}

char GenerateFloor()
{
    return '5';
}