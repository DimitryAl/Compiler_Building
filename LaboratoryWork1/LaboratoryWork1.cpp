// LaboratoryWork1.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <fstream>
#include <vector>

class StateMachine
{
private:
	//char _new_line = '/n';
	std::vector<char> _alphabet{	// ������� �������
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9', (char)'/n'};
	std::vector<char> _init_floors{};	// ������� �������
	std::vector<char> _final_floors{};	// ������� �������� ������
	enum class State {    // ��������� ��������
		Start,
		Moving_Up,
		Moving_Down,
		Standing,
		Error,
		Final
	};
	State _current_state = State::Start;	// ������� ���������
	State _finite_state = State::Final;		// �������� ���������
	int _current_floor = 0;	// ������� ����
	int _final_floor = 0;	// �������� ����
	

	

	
public:
	StateMachine() {};

	void Transition(/*char symbol*/)
	{
		switch (_current_state)
		{
		case State::Start:
			for (int i = 0; )
			break;
		case State::Moving_Up:

			break;
		case State::Moving_Down:

			break;
		case State::Standing:

			break;
		case State::Error:

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
	while (!file.eof())
	{
		init_floor = Elevator.GetData(file);
		final_floor = Elevator.GetData(file);
		Elevator.AddQueue(1, init_floor);
		Elevator.AddQueue(2, final_floor);
		Elevator.Transition();
	}




    return 0;
}
