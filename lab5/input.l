%option noyywrap yylineno
%{
 #include "y.tab.h"
 #include <stdio.h>
 int ch;
 
 extern int yylex(void);
 extern void yyerror (char *);
%}
digit[0-9]
letter[a-zA-Z]
letter2[a-f]
delim[();]
oper[<>=]
ws[ \t\n]
%%
for { ch += yyleng; return FOR; }
do { ch += yyleng; return DO; }
({letter})({letter}|{digit})* { ch += yyleng;
        return ID;
}
([+-]?({digit}+{letter2}*)) { ch += yyleng;

 return NUMBER; }

{oper} { ch += yyleng;
        return CMP;
 }

":=" { ch += yyleng; return ASSIGN; }

{delim} { ch += yyleng;
        return *yytext; }

{ws}+ { ch += yyleng; }

. { yyerror("Unknown character"); ch += yyleng; }
%%
