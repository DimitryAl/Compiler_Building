// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>

bool InVector(std::vector<char> vect, char inputSymbol)
{
	auto result = std::find(begin(vect), end(vect), inputSymbol);
	if (result != end(vect)) {
		return true;
	}
	return false;
}
char GetData(std::ifstream& file)
{
	return file.get();
};

char GenerateFloor(int min, int max)
{
	int res = min + rand() % (max - min + 1);
	return (char)res;
};




class FiniteStateMachine /*:public StateMachine*/
{
private:
	std::vector<char> _alphabet{	// Входной алфавит
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', (char)'/n', 'e'};
	std::vector<char> _init_floors{};	// Очередь вызовов
	std::vector<char> _final_floors{};	// Очередь конечных этажей
	std::vector<char> _in_elevator{};	// Этажи на которые нажали люди в лифте
	static enum class State {    // Состояния автомата
		Start,
		PickUp,
		Final
	};
	State _current_state = State::Start;	// Текущее состояние
	State _final_state = State::Final;		// Финальное состояние
	int _current_floor = '0';	// Текущий этаж
	int _final_floor = '0';		// Конечный этаж
public:

	FiniteStateMachine() {};

	void Transition(char input_symbol)
	{
		switch (_current_state)
		{
		case State::Start:
			if (input_symbol == '\n') _current_state = State::Final; 
			if (input_symbol == 'e') _current_state = State::Final;
			else {
				_current_state = State::Standing;
				_final_floor = GenerateFloor(48, 57);
			}
			break;
		/*case State::Moving:
			if (input_symbol == '\n') _current_state = State::Final;
			break;*/
		case State::PickUp:
			if (input_symbol == '\n') _current_state = State::Final;
			if (input_symbol == 'e') _current_state = State::Final;
			else {
				_current_state = State::Standing;
				_current_floor = _final_floor;
				_final_floor = GenerateFloor(48, 57);
			}
			break;
		case State::Final:
			break;
		default:
			break;
		}
	}
	
	std::vector<char> GetAlphabet()
	{
		return this->_alphabet;
	}
	State GetCurrentState()
	{
		return this->_current_state;
	}
	State GetFinalState()
	{
		return this->_final_state;
	}
	State GetStartState()
	{
		return State::Start;
	}
	State GetPickUpState()
	{
		return State::PickUp;
	}
	void PrintState()
	{
		switch (_current_state)
		{
		case State::Start:
			std::cout << "Start";
			break;
		case State::PickUp:
			std::cout << "Standing";
			break;
		case State::Final:
		std::cout << "Final";
			break;
		default:
			break;
		}
	}
	void PrintCurrentFloor()
	{
		std::cout << _current_floor;
	}
	void PrintFinalFloor()
	{
		std::cout << _final_floor;
	}
};

void PrintData(FiniteStateMachine Elevator)
{
	std::cout << "Current state ";
	Elevator.PrintState();
	std::cout << "\tCurrent floor ";
	Elevator.PrintCurrentFloor();
	std::cout << "\tFinal floor ";
	Elevator.PrintFinalFloor();
	std::cout << std::endl;
};

int main()
{
	std::string fileName = "input.txt";
	std::ifstream file;

	file.open(fileName);
	if (!file) { return 1; }

	FiniteStateMachine Elevator;

	//char init_floor;
	//char final_floor;
	char input_symbol;
	PrintData(Elevator);
	while (1)
	{
		if (Elevator.GetCurrentState() == Elevator.GetPickUpState() || Elevator.GetCurrentState() == Elevator.GetStartState())
		{
			input_symbol = GetData(file);
			if (!InVector(Elevator.GetAlphabet(), input_symbol)) input_symbol = 'e';
			Elevator.Transition(input_symbol);
			PrintData(Elevator);

		}
		else continue;			
		
		if (Elevator.GetCurrentState() == Elevator.GetFinalState()) break;
	}


	return 0;
}

