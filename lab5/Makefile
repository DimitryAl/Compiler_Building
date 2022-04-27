make:
	bison -dy input.y
	flex input.l
	g++ lex.yy.c y.tab.c
start:
	./a.out text.txt
delete:
	rm y.tab.c
	rm y.tab.h
	rm lex.yy.c
	rm a.out
all: delete make start