#ifndef PROGRAM_H
#define PROGRAM_H

#include "symbolTable.h"

class StatementList;

class Program {
public:
  Program(StatementList* List) : statementList(list) {}
  ~Program();
  int check();

private:
  StatementList* statementList;
  SymbolTable               st;
};

#endif
