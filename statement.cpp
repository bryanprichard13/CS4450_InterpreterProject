#include <iostream>
#include <cstdlib>
#include <number.h>
#include <arithmetic.h>
#include <statement.h>
#include "symbolTable.h"

int Statement::getLine() const {
  return line;
}

Assignment::~Assignment() {
  delete arithExp;
}

void Assignment::check(SymbolTable&st) const {
  st[name] = arithExp->check(st);
}


// used for print and error
using std::cout;
using std::endl;

// IF ELSE statements
void IfElse::check(SymbolTable& st) const {
   if (condition->check(st) > 0) {
      trueList->check(st);
   } else {
      falseList->check(st);
   }
}

// WHILE statements
void While::check(SymbolTable& st) const {
   while (condition->check(st) > 0) {
      stmtList->check(st);
   }
}

// PRINT statements
void Print::check(SymbolTable& st) const {
   Number n(exp->check(st));
   cout << ">> " << n << endl;
}

// COMMENTS
void Comment::check(SymbolTable& st) const {
   Number n(exp->check(st));
   cout << "#" << n << endl;
}
