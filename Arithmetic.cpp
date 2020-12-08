#include "symbolTable.h"
#include "arithmetic.h"

Number Constant::check(const SymbolTable &st) const {
   return num;
}

Number Identifier::check(const SymbolTable& st) const {
   return st[name];
}

Number Negation::check(const SymbolTable& st) const {
   return -(negative->check(st));
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