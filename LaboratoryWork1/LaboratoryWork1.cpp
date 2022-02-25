// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>

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
//bool IsEmpty(std::vector<char> vect)
//{
//	if (vect.empty()) return true;
//	else return false;
//}
//class StateMachine
//{
//public:
//
//	
//};

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
		Choosing,
		Standing,
		Final
	};
	State _current_state = State::Start;	// Текущее состояние
	State _final_state = State::Final;		// Финальное состояние
	int _current_floor = '0';	// Текущий этаж
	int _final_floor = '0';		// Конечный этаж
public:

	FiniteStateMachine() {};

	char Transition(char input_symbol)
	{
		switch (_current_state)
		{
		case State::Start:
			break;
		case State::Choosing:
			if (_current_state == _final_state) return 'e';
			break;
		case State::Standing:
			break;
		case State::Final:
			break;
		default:
			break;
		}
	}

	void AddQueue(int n, char symbol) {
		if (n == 1) _init_floors.push_back(symbol);
		else if (n == 2) _final_floors.push_back(symbol);
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
	State GetChoosingState() {
		return State::Choosing;
	}
	State WaitInput()
	{
		return State::Choosing;
	}
};

int main()
{
	std::cout << "This is LaboratoryWork1.cpp";


	std::string fileName = "input.txt";
	std::ifstream file;

	file.open(fileName);
	if (!file) { return 1; }

	FiniteStateMachine Elevator;

	char init_floor;
	char final_floor;
	char input_symbol;
	// Сделать массив чисел из файла, а не читать из файла
	while (1)
	{
		if (Elevator.GetCurrentState() == Elevator.WaitInput() || Elevator.GetStartState() == Elevator.WaitInput())
		{
			init_floor = GetData(file);
			final_floor = GetData(file);

			if (InVector(Elevator.GetAlphabet(), init_floor)) input_symbol = init_floor;
			else input_symbol = 'e';
			input_symbol = Elevator.Transition(input_symbol);
		}
		else if (Elevator.GetCurrentState() == Elevator.GetChoosingState())
		{
			Elevator.Transition(input_symbol);
		}
		

		if (Elevator.GetCurrentState() == Elevator.GetFinalState()) break;
	}

	return 0;
}
