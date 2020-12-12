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
  cout << "HEY";
}

Print::~Print() {
   delete expression;
}

void Print::check(SymbolTable& st) const {
   Number n(expression->check(st));
   cout << ">> " << n << endl;
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
