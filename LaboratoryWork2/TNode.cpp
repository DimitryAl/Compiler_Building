#include "TNode.h"

Node::Node()
{
	_value = 'x';
}

Node::Node(char value) {
	_value = value;
}

void Node::PrintTree(Node* node, int indent)
{
	std::vector <Node*> children;

	for (int i = 0; i < indent; i++)
	{
		std::cout << ' ';
	}
	std::cout << _value;
	
	for (auto node : _children) {
		children = node->GetChildren();
		if (!children.empty())
		{
			indent++;
			PrintTree(node, indent);
		}
	}
}

Node* Node::AddChild(char value)
{
	Node* new_node = new Node(value);
	_children.push_back(new_node);
}

char Node::GetValue()
{
	return _value;
}

std::vector <Node*> Node::GetChildren()
{
	return _children;
}