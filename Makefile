PROGRAM = python_interpreter

all: python_interpreter

parse.tab.h parse.tab.h: parse.y
	bison -t -v -d parse.y

lex.yy.c: parse.tab.h lex.l 
	flex lex.l

python_interpreter: lex.yy.c parse.tab.c parse.tab.h
	gcc -o python_interpreter parse.tab.c lex.yy.x
