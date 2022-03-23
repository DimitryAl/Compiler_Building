//#pragma once
#ifndef TNODE_H
#define TNODE_H

#include <iostream>
#include <vector>


class Node
{
private:
	// node's value 
	//char _value;
	std::string _name;
	int _square;
	// vetor of node's children 
	std::vector <Node*> _children;
public:

	Node();
	Node(std::string name, int );
	
	~Node() {};

	Node* AddChild(std::string name, int square);

	int GetSquare();
	std::string GetName();

	std::vector <Node*> GetChildren();
};

#endif	//TNODE_H