%option noyywrap yylineno
%{
#include "TNode.h"
#define YYSTYPE TNode*
#include <stdlib.h>
#include "y.tab.hpp"
extern int yylex(void);
extern void yyerror(char* s);

%}

digit[0-9]+
ws[ \t\n]

%%
{digit} {
		yylval = new TNode();
		yylval->setVal(atoi(yytext));
		return NUM;
		}
{ws}	{return ENDOF;		}
\{		{return BEGINMARKER;}
\}		{return ENDMARKER;	}
,		{}


%%
