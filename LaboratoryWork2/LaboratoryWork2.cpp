#include <iostream>
#include <fstream>
#include <algorithm>

#include "TNode.h"

enum class State
{
	Start,
	Read,
	Final
};
std::vector <char> alphabet = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '{', '}', '\n', 'e' };
Node* root = new Node();
std::vector <Node*> stack = {};
Node* parent = root;
Node* last;
State current_state = State::Start;


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
		last = root->AddChild(symbol);
		return State::Read;
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
		last = parent->AddChild(symbol);
		return State::Read;

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
		std::cout << ' ';
	}
	std::cout << node.GetValue();
	std::cout << '\n';

	children = node.GetChildren();
	indent++;
	for (auto child : children) {
		PrintTree(*child, indent);
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
		if (!InVector(symbol))
		{
			symbol = 'e';
		}

		current_state = Transition(current_state, symbol);

		if (current_state == State::Final) break;
	}

	PrintTree(*root);
	
	file.close();

	return 0;
}
