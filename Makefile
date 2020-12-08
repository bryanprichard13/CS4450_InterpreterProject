CXX = clang++
LEX = flex
YACC = bison -d
YACCFLAGS = -x c++
PROGRAM = python_interpreter

all: python_interpreter

parse.tab.c parse.tab.h: parse.y
	bison -t -v -d parse.y

lex.yy.c: parse.tab.h lex.l
	flex lex.l

python_interpreter: lex.yy.c parse.tab.c parse.tab.h
	g++ -o python_interpreter parse.tab.c lex.yy.c main.cpp
