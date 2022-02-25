
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
		'5', '6', '7', '8', '9', (char)'/n' };
	std::vector<char> _init_floors{};	// Очередь вызовов
	std::vector<char> _final_floors{};	// Очередь конечных этажей
	std::vector<char> _in_elevator{};	// Этажи на которые нажали люди в лифте
	enum class State {    // Состояния автомата
		Start,
		Moving_Up,
		Moving_Down,
		Standing,
		//Error,
		Final
	};
	State _current_state = State::Start;	// Текущее состояние
	//State _finite_state = State::Final;		// Конечное состояние
	int _current_floor = '0';	// Текущий этаж
	int _final_floor = '0';		// Конечный этаж

public:
	StateMachine() {};

	void Transition(/*char symbol*/)
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
			//_final_floor = _init_floors.front();
			_init_floors.erase(_init_floors.begin());	// Человек зашел в лифт
			std::cout << "Человек зашел в лифт" << std::endl;
			_final_floor = _final_floors.front();
			_in_elevator.push_back(_final_floors.front());	// Человек нажал на кнопку
			std::cout << "Человек нажал на " << _final_floors.front() << " этаж" << std::endl;
			_final_floors.erase(_final_floors.begin());

			// Определяем куда ехать
			if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;

			/*if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;*/

			/*for (int i = _current_floor; i < _final_floor; i++){}
			for (int i = 0; i < 2; i++)
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
			/*for (int i = 0; i < 2; i++)
			{*/
			_current_floor += 1;
			// Если в лифте есть человек, которому надо выйти на этом этаже 
			/*if (_current_floor == _final_floor)*/
			if (InVector(_in_elevator, _current_floor))
			{
				_current_state = State::Standing;
				std::cout << "Лифт остановился на " << _current_floor << " этаже/n";
				/*_init_floors.erase(_init_floors.begin());
				_final_floors.erase(_final_floors.begin());*/
				//break;
			}
			// Если на этаже есть человек, который хочет ехать вверх

			// Если на этаже есть человек, который хочет ехать вверх 
		//}
			break;
			//case State::Moving_Down:
			//	/*for (int i = 0; i < 2; i++)
			//	{*/
			//		_current_floor -= 1;
			//		if (InVector(_current_floor))	// Если на этаже человек ждет лифт
			//		{
			//			//поиск индекса
			//			int j;
			//			for (j = 0; j < _init_floors.size(); j++)
			//			{
			//				if (_init_floors[j] == _current_floor) break;
			//			}
			//			if (_final_floors[j] <= _current_floor) // Человек заходит в лифт
			//			{
			//				_in_elevator.push_back(_final_floors[j]);
			//				_init_floors.erase(_init_floors.begin() + j);
			//				_final_floors.erase(_final_floors.begin() + j);
			//			}
			//		}

			//		if (_current_floor == _final_floor)
			//		{
			//			
			//			_current_state = State::Standing;
			//			/*_init_floors.erase(_init_floors.begin());
			//			_final_floors.erase(_final_floors.begin());*/
			//			break;
			//		}
			//	//}
			//	break;
		case State::Standing:
			//
			// Типо если в лифте никого нет , то то-то, иначе то-то
			// 
			//if (_in_elevator.size() != 0)	// Если лифт не пустой
			//{
			//	_final_floor = _in_elevator.front();
			//	_in_elevator.erase(_in_elevator.begin());
			//}
			temp = remove(_in_elevator.begin(), _in_elevator.end(), _current_floor);
			std::cout << "Человек(и) вышел на  " << _current_floor << " этаж/n";
			//if (_final_floors.size() == _init_floors.size())
			//{
			//	_final_floor = _init_floors.front();
			//	_init_floors.erase(_init_floors.begin());
			//}
			//else {	// По факту это значит, что человек зашел в лифт и нажал кнопку нужного ему этажа
			//	_final_floor = _final_floors.front();
			//	_final_floors.erase(_final_floors.begin());
			//}
			/*_final_floor = _final_floors.front();
			_init_floors.erase(_init_floors.begin());
			_final_floors.erase(_final_floors.begin());*/
			//// Проверяем хочет ли кто-то зайти в лифт
			//if (InVector(_init_floors, _current_floor))
			//{
			//	for (int i = 0; i < _init_floors.size(); i++)
			//	{
			//		if (_init_floors[i] == _current_floor/* && abs((_final_floor - _final_floors[i])) < _current_floor*/)
			//		{
			//			if (_current_state == State::Moving_Up)
			//			{
			//				if (_final_floors[i] > _current_floor) _in_elevator.push_back(_final_floors[i]);
			//			}
			//			if (_current_state == State::Moving_Down)
			//			{
			//				if (_final_floors[i] < _current_floor) _in_elevator.push_back(_final_floors[i]);
			//			}
			//		}
			//	}
			//	std::vector<char>::iterator temp = remove(_init_floors.begin(), _init_floors.end(), _current_floor);
			//	//_in_elevator.push_back();
			//}
			// если в лифте еще есть люди 
			if (_final_floor > _current_floor) _current_state = State::Moving_Up;
			else if (_final_floor < _current_floor) _current_state = State::Moving_Down;
			else _current_state = State::Standing;
			// если лифт пустой, то берем первый вызов из очереди вызовов

			break;
			/*case State::Error:

				break;*/
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
		auto result = std::find(begin(/*_init_floors*/vect), end(/*_init_floors*/vect), inputSymbol);
		if (result != end(/*_init_floors*/vect)) {
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

//int main()
//{
//	std::string fileName = "input.txt";
//	std::ifstream file;
//	file.open(fileName);
//	if (!file) { return 1; }
//
//	StateMachine Elevator;
//
//	char init_floor;
//	char final_floor;
//	while (1)
//	{
//		if (!file.eof())
//		{
//			init_floor = Elevator.GetData(file);
//			final_floor = Elevator.GetData(file);
//
//			Elevator.AddQueue(1, init_floor);
//			Elevator.AddQueue(2, final_floor);
//		}
//		Elevator.Transition();
//		if (Elevator.IsEmpty()) break;
//	}
//
//	return 0;
//}
