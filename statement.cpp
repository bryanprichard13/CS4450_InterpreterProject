#include <iostream>
#include <cstdlib>
// #include "number.h"
#include "symbolTable.h"
#include "arithmetic.h"
#include "statement.h"

using std::cout;
using std::cerr;
using std::endl;

int Statement::getLine() const {
  return line;
}

Assignment::~Assignment() {
  delete arithExp;
}

void Assignment::check(SymbolTable&st) const {
  st[name] = arithExp->check(st);
}
