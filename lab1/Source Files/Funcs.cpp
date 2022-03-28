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
    return file.get();
}

char GenerateFloor()
{
    return '5';
}