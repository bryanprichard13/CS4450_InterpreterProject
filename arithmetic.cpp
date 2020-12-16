#include "symbolTable.h"
#include "expression.h"

Number Constant::check(const SymbolTable &st) const {
   return num;
}

Number Identity::check(const SymbolTable& st) const {
   return st[name];
}

Negative::~Negative() {
   delete operand;
}

Number Negative::check(const SymbolTable& st) const {
   return -(operand->check(st));
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
