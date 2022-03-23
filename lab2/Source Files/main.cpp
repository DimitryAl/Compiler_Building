#include <iostream>
#include <fstream>
//#include <algorithm>
#include <string>

#include "../Header Files/TNode.h"

enum class State
{
	Start,
	Read,
	ReadName,
	ReadNumber,
	Final
};
Node* root = new Node();
std::vector <Node*> stack = {};
Node* parent = root;
Node* last;
State current_state = State::Start;
std::string name = {"NULL"};
std::string square = {-0};


State Transition(State cur_state, char symbol)
{
	switch (cur_state) {
	case State::Start:

		if (symbol == '\n') return State::Final;
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
		break;
	case State::Read:

		if (symbol == '\n') return State::Final;

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

		return State::Read;

		break;
	case State::ReadName:

		if (symbol == '\n') return State::Final;

		if (symbol == ':')
		{
			return State::ReadNumber;
		}
		name.push_back(symbol);
		return State::ReadName;

		break;
	case State::ReadNumber:

		if (symbol == '\n') return State::Final;

		if (symbol == '\"')
		{
			last = parent->AddChild(name, std::stoi(square));
			square = {};
			name = {};
			return State::Read;
		}
		if (48 <= symbol <= 57) square.push_back(symbol);
		else return State::Final;
		
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

void CheckSquare(Node* node)
{
	std::vector <Node*> children = node->GetChildren();
	int total_square = node->GetSquare();
	int current_sum = 0;

	if (!children.empty())
	{
		for (auto child : children)
		{
			current_sum += child->GetSquare();
		}
		if (total_square != current_sum)
		{
			std::cout << "Area of " << node->GetName() << " and area of it's children are not equal!\n";
		}
		else {
			std::cout << "Area of " << node->GetName() << " and area of it's children are equal!\n";
		}
	}

	for (auto child : node->GetChildren())
	{
		CheckSquare(child);
	}

}

char GetSymbol(std::ifstream& file)
{
	char symbol = file.get();
	return symbol;
}

int main()
{
	std::string file_name = "./Resource Files/in.txt";
	std::ifstream file;
	char symbol;

	file.open(file_name);
	if (!file) { return 1; }


	while (1)
	{
		symbol = GetSymbol(file);
		current_state = Transition(current_state, symbol);
		
		if (current_state == State::Final) break;
	}

	file.close();

	std::cout << "Checking areas:\n";
	for (Node* child : root->GetChildren())
	{
		CheckSquare(child);
	}
	std::cout << std::endl;
	PrintTree(*root);

	return 0;
}
