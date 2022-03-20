#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include "TNode.h"

enum class State
{
	Start,
	Read,
	ReadName,
	ReadNumber,
	Final
};
std::vector <char> alphabet = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '{', '}', '\n', 'e' };
Node* root = new Node();
std::vector <Node*> stack = {};
Node* parent = root;
Node* last;
State current_state = State::Start;
std::string name = {};
std::string square = {};


State Transition(State cur_state, char symbol)
{
	switch (cur_state) {
	case State::Start:

		if (symbol == '\n') return State::Final;
		if (symbol == 'e') return State::Final;
		if (symbol == '{')
		{
			return State::Final;
		}
		if (symbol == '}')
		{
			return State::Final;
		}
		if (symbol == '\"')
		{
			return State::ReadName;
		}
		//last = root->AddChild(name, std::stoi(square));
		//return State::Read;
		break;
	case State::Read:

		if (symbol == '\n') return State::Final;
		if (symbol == 'e') return State::Final;

		if (symbol == '{')
		{
			stack.push_back(parent);
			parent = last;
			return State::Read;
		}
		if (symbol == '}')
		{
			parent = stack.back();
			stack.pop_back();
			return State::Read;
		}
		if (symbol == '\"')
		{
			name = {};
			return State::ReadName;
		}


		//last = parent->AddChild(name, std::stoi(square));
		return State::Read;

		break;
	case State::ReadName:

		if (symbol == '\n') return State::Final;
		if (symbol == 'e') return State::Final;

		if (symbol == ':')
		{
			//square = {};
			return State::ReadNumber;
		}
		name.push_back(symbol);
		return State::ReadName;

		break;
	case State::ReadNumber:

		if (symbol == '\n') return State::Final;
		if (symbol == 'e') return State::Final;

		if (symbol == '\"')
		{
			last = parent->AddChild(name, std::stoi(square));
			square = {};
			name = {};
			return State::Read;
		}
		square.push_back(symbol);
		return State::ReadNumber;
		break;
	case State::Final:
		return State::Final;
		break;
	default:
		return State::Final;
	}
}


void PrintTree(Node node, int indent = 0)
{
	std::vector <Node*> children;

	for (int i = 0; i < indent; i++)
	{
		std::cout << '\t';
	}
	std::cout << node.GetName() << ' ' << node.GetSquare();
	std::cout << '\n';

	children = node.GetChildren();
	indent++;
	for (auto child : children) {
		PrintTree(*child, indent);
	}
}

void CheckSquare(Node node)
{
	//std::vector <Node*> children;
	int total_square = node.GetSquare();
	int current_sum = 0;

	for (auto child : node.GetChildren())
	{
		current_sum += child->GetSquare();
	}

	if (total_square != current_sum)
	{
		std::cout << "Площади не совпадают!\n";
	}

}

char GetSymbol(std::ifstream& file)
{
	char symbol = file.get();
	return symbol;
}

bool InVector(char symbol)
{
	if (std::find(alphabet.begin(), alphabet.end(), symbol) != alphabet.end()) {
		return true;
	}
	else {
		return false;
	}
}

int main()
{
	std::string file_name = "in.txt";
	std::ifstream file;
	char symbol;

	file.open(file_name);
	if (!file) { return 1; }

	while (1)
	{
		symbol = GetSymbol(file);
		/*if (!InVector(symbol))
		{
			symbol = 'e';
		}*/

		current_state = Transition(current_state, symbol);

		if (current_state == State::Final) break;
	}
	setlocale(LC_ALL, "rus");

	PrintTree(*root);

	file.close();

	return 0;
}
