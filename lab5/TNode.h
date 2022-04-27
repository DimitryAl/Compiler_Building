#ifndef TNODE_H
#define TNODE_H

class TNode {
	public:
	int _val;
	TNode* _child;
	TNode* _brother;
	
	TNode() {_val = 0; _child = 0; _brother=0;}
	void setVal( int val) {_val = val;}
	void addChild(TNode* &node) {_child = node;}
	void addBrother(TNode* &node) {_brother = node;}

};

void printTree(const TNode& tree, int ident);

#endif