#include "TNode.h"
#include <iostream>
#include <string>

void printTree(const TNode& tree, int ident)
{
	TNode* child;
	std::cout << std::string(ident++, ' ') << tree._val << std::endl;
	if (tree._child !=0) {
	child = tree._child;
	do {
		printTree(*child, ident);
		child = child->_brother;
		} while(child != 0);
	}
	
}