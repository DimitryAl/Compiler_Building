#include "TNode.h"

Node::Node()
{
	_value = 'x';
}

Node::Node(char value) {
	_value = value;
}


Node* Node::AddChild(char value)
{
	Node* new_node = new Node(value);
	_children.push_back(new_node);
	return new_node;
}

char Node::GetValue()
{
	return _value;
}

std::vector <Node*> Node::GetChildren()
{
	return _children;
}