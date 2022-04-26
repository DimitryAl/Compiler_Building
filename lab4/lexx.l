%option noyywrap yylineno
%{
 #include <stdio.h>
 int ch;
%}

digit[0-9]
letter[a-zA-Z]
letter2[a-f]
delim[();]
oper[<>=]
ws[\t\n]

%%
for { printf("KEYWORD (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }
do { printf("KEYWORD (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }
("_"|{letter})("_"|{letter}|{digit})* {
    printf("IDENTIFIER (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }
([+-]?({digit}+{letter2}*)) {
    printf("NUMBER (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;   
    }

{oper}  { printf("OPERATION (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }

":="    { printf("OPERATION (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }

{delim} { printf("DELIMITER (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }

{ws}+   { ch += yyleng; }

. { printf("Unknown character (%d, %d): %s\n", yylineno, ch, yytext);
    ch += yyleng;
    }
%%
int main(int argc, char **argv)
{
    if(argc < 2)
    {
        printf("\nThere are no file?!!.\n");
        return -1;
    }
    if((yyin = fopen(argv[1], "r")) == NULL)
    {
        printf("\nCan't open file!%s.\n", argv[1]);
        return -1;
    }
    ch = 1;
    yylineno = 1;
    yylex();
    fclose(yyin);
    return 0;
}
