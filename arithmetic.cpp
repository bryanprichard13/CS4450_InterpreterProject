#include <iostream>
#include "symbolTable.h"
#include "arithmetic.h"

using std::cout;

Number Constant::check(const SymbolTable &st) const {
  cout << "HEY";
   return num;
}

Number Identity::check(const SymbolTable& st) const {
   return st[name];
}

Negative::~Negative() {
   delete operand;
}

Number Negative::check(const SymbolTable& st) const {
   return Number(-1) * (operand->check(st));
}


BinaryExpression::~BinaryExpression() {
   delete operand1;
   delete operand2;
}

Number Add::check(const SymbolTable& st) const {
   return operand1->check(st) + operand2->check(st);
}

Number Subtract::check(const SymbolTable& st) const {
   return operand1->check(st) - operand2->check(st);
}

Number Multiply::check(const SymbolTable& st) const {
   return operand1->check(st) * operand2->check(st);
}

Number Divide::check(const SymbolTable& st) const {
   return operand1->check(st) / operand2->check(st);
}

Number Mod::check(const SymbolTable& st) const {
   return operand1->check(st) % operand2->check(st);
}

Number Exponent::check(const SymbolTable& st) const {
   return operand1->check(st) ^ operand2->check(st);
}

void ExpressionList::add(ArithmeticExpression* exp) {
   expList.push_back(exp);
}

unsigned int ExpressionList::size() const {
   return expList.size();
}

list<ArithmeticExpression*>::const_iterator ExpressionList::begin() const {
   return expList.begin();
}

list<ArithmeticExpression*>::const_iterator ExpressionList::end() const {
   return expList.end();
}

ExpressionList::~ExpressionList() {
   for (list<ArithmeticExpression*>::iterator it = expList.begin(); it != expList.end(); ++it) {
      delete *it;
   }
}
