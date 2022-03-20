// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

enum class State
{
	Start, 
	Read,
	Final
};
State current_state = State::Start;

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
		return State::Final;
		break;
	}
}

bool InVector(std::vector<char> vect, char inputSymbol)
{
	auto result = std::find(begin(vect), end(vect), inputSymbol);
	if (result != end(vect)) {
		return true;
	}
	return false;
}

char GetSymbol(std::ifstream& file)
{
	return file.get();
};

char GenerateFloor(int min, int max)
{
	int res = min + rand() % (max - min + 1);
	return (char)res;
};



int main()
{
	std::string fileName = "input.txt";
	std::ifstream file;

	file.open(fileName);
	if (!file) { return 1; }

	char symbol;

	while (1)
	{
		symbol = GetSymbol(file);


		if (current_state == State::Final) break;
	}


	return 0;
}

