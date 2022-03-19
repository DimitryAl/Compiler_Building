#include "TNode.h"

Node::Node()
{
	//_value = 'x';
	_name = {"root"};
	_square = 0;
	_children = {};
}

Node::Node(std::string name, int square) {
	//_value = value;
	_name = name;
	_square = square;
}


Node* Node::AddChild(std::string name, int square)
{
	Node* new_node = new Node(name, square);
	_children.push_back(new_node);
	return new_node;
}

int Node::GetSquare()
{
	return _square;
}

std::string Node::GetName()
{
	return _name;
}

std::vector <Node*> Node::GetChildren()
{
	return _children;
}