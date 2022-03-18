#pragma once

#include <iostream>
#include <vector>


class Node
{
private:
	// node's value 
	char _value;
	// vetor of node's children 
	std::vector <Node*> _children = {};
public:

	Node();
	Node(char value);
	
	~Node() {};

	Node* AddChild(char value);

	char GetValue();

	std::vector <Node*> GetChildren();
};

