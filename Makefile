PROGRAM = python_interpreter

all: python_interpreter

parse.tab.h parse.tab.h: parse.y
	bison -t -v -d parse.y