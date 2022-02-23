// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>

class StateMachine
{
private:
	char _new_line = '/n';
	std::vector<char> _alphabet{	// Входной алфавит
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', (char)'/n'};
	enum class State {    // Состояния автомата
		Start,
		Moving_Up,
		Moving_Down,
		Standing,
		Error,
		Final
	};
	State _current_state = State::Standing;
	int _current_floor = 0;
	int _final_floor = 0;

	bool InAlphabet(char inputSymbol) {
		auto result = std::find(begin(_alphabet), end(_alphabet), inputSymbol);
		if (result != end(_alphabet)) {
			return true;
		}
		return false;
	}
public:
	StateMachine()
	{
		/*this->current_floor = 1;
		this->final_floor = 1;*/
	}
	/*StateMachine(int floor)
	{
		this->_current_floor = floor;
	}*/


	char GetData(std::ifstream& file)
	{
		/*char symbol;
		symbol = file.get();*/
		return file.get();
	};
	int GetCurrentFloor()
	{
		return this->_current_floor;
	}
	int GetFinalFloor()
	{
		return this->_final_floor;
	}
	bool SetCurrentFloor(int floor) {
		if (InAlphabet(floor)) { 
			_current_floor = floor; 
			return true; 
		}
		else return false;
	}
	bool SetFinalFloor(int floor) {
		if (InAlphabet(floor)) {
			_final_floor = floor;  
			return true;
		}
		else return false;
	}

};

int main()
{
	std::string fileName = "input.txt";
	std::ifstream file;
	file.open(fileName);
	if (!file) { return 1; }

	StateMachine Elevator;

	char symbol;
	while (0)
	{
		symbol = Elevator.GetData(file);

	}




    return 0;
}
