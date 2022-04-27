%{
#include <stdio.h>
#include "TNode.h"
#include <cctype>
#include <iostream>
#define YYSTYPE TNode*
int yylex(void);
void yyerror(const char* s);
TNode root;

%}

%token NUM
%token ENDOF
%token BEGINMARKER
%token ENDMARKER

%%

input:
	| input line
	
line: ENDOF
	| S ENDOF					{root.addChild($1);printTree(root,0);}
	
S:	NUM BEGINMARKER S ENDMARKER	{$$->addChild($3);}
	| S S 						{$$->addBrother($2);}
	| NUM

%%

void yyerror(const char *s) {
	std::cout<< s;
}

int main() {
	return yyparse();
}