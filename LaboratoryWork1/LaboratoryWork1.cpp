// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

class StateMachine
{
private:
	std::vector<char> _alphabet{	// Входной алфавит
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', (char)'/n'};
	std::vector<char> _init_floors{};	// Очередь вызовов
	std::vector<char> _final_floors{};	// Очередь конечных этажей
	std::vector<char> _in_elevator{};	// Этажи на которые нажали люди в лифте
	enum class State {    // Состояния автомата
		Start,
		Moving_Up,
		Moving_Down,
		Standing,
		Final
	};
	State _current_state = State::Start;	// Текущее состояние
	int _current_floor = '0';	// Текущий этаж
	int _final_floor = '0';		// Конечный этаж

public:
	StateMachine() {};

	void Transition()
	{
		std::vector<char>::iterator temp;
		switch (_current_state)
		{
		case State::Start:
			if (!InAlphabet(_init_floors.front()))	// Если символ не из алфавита
			{
				_current_state = State::Standing;
				_init_floors.erase(_init_floors.begin());
				_final_floors.erase(_init_floors.begin());
			}
			_final_floor = _init_floors.front();
			_init_floors.erase(_init_floors.begin());
			// Определяем куда ехать
			if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;

			break;
		case State::Moving_Up:
			_current_floor += 1;
			if (_current_floor == _final_floor) _current_state = State::Standing;
			break;
		case State::Moving_Down:
			_current_floor -= 1;
		
			break;
		case State::Standing:
			if (_final_floors.size() == _init_floors.size())
			{
				_final_floor = _init_floors.front();
				_init_floors.erase(_init_floors.begin());
			}
			else {	// По факту это значит, что человек зашел в лифт и нажал кнопку нужного ему этажа
				_final_floor = _final_floors.front();
				_final_floors.erase(_final_floors.begin());
			}
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
	char GetData(std::ifstream& file)
	{
		return file.get();
	};
	// Сделать интерфейс, где будет метод InVector
	bool InAlphabet(char inputSymbol) {
		auto result = std::find(begin(_alphabet), end(_alphabet), inputSymbol);
		if (result != end(_alphabet)) {
			return true;
		}
		return false;
	}
	bool InVector(std::vector<char> vect, char inputSymbol)
	{
		auto result = std::find(begin(vect), end(vect), inputSymbol);
		if (result != end(vect)) {
			return true;
		}
		return false;
	}
	int GetCurrentFloor()
	{
		return this->_current_floor;
	}
	bool SetCurrentFloor(int floor) {
		if (InAlphabet(floor)) { 
			_current_floor = floor; 
			return true; 
		}
		else return false;
	}
	bool IsEmpty()
	{
		if (_final_floors.empty()) return true;
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

	char init_floor;
	char final_floor;
	while (1)
	{
		if (!file.eof())
		{
			init_floor = Elevator.GetData(file);
			final_floor = Elevator.GetData(file);

			Elevator.AddQueue(1, init_floor);
			Elevator.AddQueue(2, final_floor);
		}
		Elevator.Transition();
		if (Elevator.IsEmpty()) break;
	}

    return 0;
}
