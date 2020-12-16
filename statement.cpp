#include <iostream>
#include <cstdlib>
#include "number.h"
#include "arithmetic.h"
#include "statement.h"
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

Print::~Print() {
   delete exp;
}

StatementList::~StatementList() {
   for (list<Statement*>::const_iterator it = stmtList.begin(); it != stmtList.end(); ++it) {
      delete *it;
   }
}

void StatementList::add(Statement* stmt) {
   stmtList.push_back(stmt);
}

void StatementList::check(SymbolTable& st) const {
   // eval() each statement in statement list
   list<Statement*>::const_iterator it;
   // try {
      for (it = stmtList.begin(); it != stmtList.end(); ++it) {
         (*it)->check(st);
      }
   // } catch (ParseException e) {
   //    // if we catch an exception indicating a semantic error, print it and bail out
   //    cerr << "error (line " << (*it)->getLine() << "): " << e.what() << endl;
   //    exit(2);
   // }
}


// used for print and error
using std::cout;
using std::endl;

IfElse::~IfElse() {
  delete condition;
  delete trueList;
  delete falseList;
}

// IF ELSE statements
void IfElse::check(SymbolTable& st) const {
   if (condition->check(st) > 0) {
      trueList->check(st);
   } else {
      falseList->check(st);
   }
}

While::~While() {
  delete condition;
  delete stmtList;
}
// WHILE statements
void While::check(SymbolTable& st) const {
   while (condition->check(st) > 0) {
      stmtList->check(st);
   }
}

// FOR Statements
void For::check(SymbolTable& st) const {
   for (condition->check(state); condition->check(st); condition->check(action)) {
      stmtList->check(st);
   }
}

// PRINT statements
void Print::check(SymbolTable& st) const {
   Number n(exp->check(st));
   cout << ">> " << n << endl;
}
