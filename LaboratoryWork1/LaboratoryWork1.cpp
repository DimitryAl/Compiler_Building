// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>

class StateMachine
{
private:
	//char _new_line = '/n';
	std::vector<char> _alphabet{	// Входной алфавит
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', (char)'/n'};
	std::vector<char> _init_floors{};	// Очередь нажатий
	std::vector<char> _final_floors{};	// Очередь конечных этажей

	enum class State {    // Состояния автомата
		Start,
		Moving_Up,
		Moving_Down,
		Standing,
		Error,
		//Final
	};
	State _current_state = State::Start;	// Текущее состояние
	//State _finite_state = State::Final;		// Конечное состояние
	State _finite_state = State::Standing;		// Конечное состояние
	int _current_floor = '0';	// Текущий этаж
	int _final_floor = '0';	// Конечный этаж
	

	

	
public:
	StateMachine() {};

	void Transition(/*char symbol*/)
	{
		switch (_current_state)
		{
		case State::Start:
			//_final_floor = _final_floors.front();
			if (!InAlphabet(_init_floors.front()))
			{
				_current_state = State::Error;
				_init_floors.erase(_init_floors.begin());
				_final_floors.erase(_init_floors.begin());
			}
			_final_floor = _init_floors.front();
			_init_floors.erase(_init_floors.begin());
			if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;
			/*for (int i = _current_floor; i < _final_floor; i++){}*/
			/*for (int i = 0; i < 2; i++)
			{
				_current_floor += 1;
				if (_current_floor == _final_floor)
				{
					_current_state = State::Standing;
					_init_floors.erase(_init_floors.begin());
					_final_floors.erase(_final_floors.begin());
					break;
				}
			}*/	
			break;
		case State::Moving_Up:
			for (int i = 0; i < 2; i++) 
			{
				_current_floor += 1;
				if (_current_floor == _final_floor)
				{
					_current_state = State::Standing;
					/*_init_floors.erase(_init_floors.begin());
					_final_floors.erase(_final_floors.begin());*/
					break;
				}
			}
			break;
		case State::Moving_Down:
			for (int i = 0; i < 2; i++)
			{
				// if current_floor == 
				_current_floor -= 1;
				if (_current_floor == _final_floor)
				{
					
					_current_state = State::Standing;
					/*_init_floors.erase(_init_floors.begin());
					_final_floors.erase(_final_floors.begin());*/
					break;
				}
			}
			break;
		case State::Standing:
			if (_final_floors.size() == _init_floors.size())
			{
				_final_floor = _init_floors.front();
				_init_floors.erase(_init_floors.begin());
			}
			else {
				_final_floor = _final_floors.front();
				_final_floors.erase(_final_floors.begin());
			}
			/*_final_floor = _final_floors.front();
			_init_floors.erase(_init_floors.begin());
			_final_floors.erase(_final_floors.begin());*/
			if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;
			break;
		case State::Error:

			break;
		/*case State::Final:

			break;*/
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
	bool InAlphabet(char inputSymbol) {
		auto result = std::find(begin(_alphabet), end(_alphabet), inputSymbol);
		if (result != end(_alphabet)) {
			return true;
		}
		return false;
	}
	int GetCurrentFloor()
	{
		return this->_current_floor;
	}
	//int GetFinalFloor()
	//{
	//	return this->_final_floor;
	//}
	bool SetCurrentFloor(int floor) {
		if (InAlphabet(floor)) { 
			_current_floor = floor; 
			return true; 
		}
		else return false;
	}
	/*bool SetFinalFloor(int floor) {
		if (InAlphabet(floor)) {
			_final_floor = floor;  
			return true;
		}
		else return false;
	}*/
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
